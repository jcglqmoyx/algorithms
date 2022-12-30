with a as (
    select contest_id, gold_medal as user_id
    from contests
    union all
    select contest_id, silver_medal as user_id
    from contests
    union all
    select contest_id, bronze_medal as user_id
    from contests
    order by contest_id
),
     b as (
         select a0.user_id
         from a a0
                  inner join a a1 on a1.contest_id = a0.contest_id + 1 and a1.user_id = a0.user_id
                  inner join a a2 on a2.contest_id = a0.contest_id + 2 and a2.user_id = a0.user_id
     ),
     c as (
         select gold_medal as user_id
         from contests
         group by gold_medal
         having count(gold_medal) >= 3
     ),
     d as (
         select user_id
         from b
         union
         select user_id
         from c
     )
select name, mail
from users
where user_id in (select * from d)