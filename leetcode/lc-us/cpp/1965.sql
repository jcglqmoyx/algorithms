with t as (
    select employee_id
    from Employees
    union all
    select employee_id
    from Salaries
)
select employee_id
from t
group by 1
having count(1) = 1
order by 1;