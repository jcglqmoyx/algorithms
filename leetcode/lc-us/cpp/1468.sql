select s.company_id,
       s.employee_id,
       s.employee_name,
       round(s.salary * (1 - companytaxrate.taxrate)) as salary
from salaries s
         join
     (select company_id,
             case
                 when max(salary) < 1000 then 0
                 when max(salary) between 1000 and 10000 then 0.24
                 when max(salary) > 10000 then 0.49
                 end as taxrate
      from salaries
      group by company_id) as companytaxrate on s.company_id = companytaxrate.company_id;