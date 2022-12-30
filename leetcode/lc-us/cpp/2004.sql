with a as (
    select employee_id
         , experience
         , salary
         , sum(salary) over (order by salary,employee_id) ssal
    from candidates
    where experience = 'Senior'
),
     b as (
         select employee_id
              , experience
              , salary
              , sum(salary) over (order by salary,employee_id) jsal
         from candidates
         where experience = 'Junior'
     ),
     c as (select experience, ssal from a where ssal < 70000),
     d as (
         select experience, jsal
         from b
         where jsal < 70000 - (select ifnull(max(ssal), 0) from c)
     )
select 'Senior' experience, count(ssal) accepted_candidates
from c
union all
select 'Junior', count(jsal)
from d;