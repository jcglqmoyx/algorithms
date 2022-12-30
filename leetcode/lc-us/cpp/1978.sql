select a.employee_id
from Employees a
where a.salary < 30000
  AND a.manager_id is not null
  AND not exists
    (select 1 from Employees b where a.manager_id = b.employee_id)
ORDER BY a.employee_id;