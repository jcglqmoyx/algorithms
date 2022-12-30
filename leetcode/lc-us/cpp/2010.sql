with tmp as (
    select employee_id
    from (
             select 70000 - sum(salary) over (order by salary rows UNBOUNDED PRECEDING) sum,
                    employee_id
             from Candidates
             where experience = "senior"
             group by employee_id) tb
    where sum > 0),
     tmp2 as (
         select 70000 - sum(salary) over (order by salary rows UNBOUNDED PRECEDING) sum
         from Candidates
         where experience = "senior"
         group by employee_id
     )
        (select employee_id from tmp)
union
(select employee_id
 from (
          select sum(salary) over (order by salary rows UNBOUNDED PRECEDING) sum,
                 employee_id
          from Candidates c
          where experience = "Junior"
          group by employee_id) tb
 where tb.sum < ifnull((select min(sum) from tmp2 where sum > 0), 70000))