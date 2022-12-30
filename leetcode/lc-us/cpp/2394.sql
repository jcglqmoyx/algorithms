with t as (
    select employee_id,
           ceil(timestampdiff(second, in_time, out_time) / 60) as tot_time
    from Logs
)

select e.employee_id
from Employees as e
         left join
     t
     on
         e.employee_id = t.employee_id
group by e.employee_id
having sum(t.tot_time) is null
    or sum(t.tot_time) < max(e.needed_hours) * 60