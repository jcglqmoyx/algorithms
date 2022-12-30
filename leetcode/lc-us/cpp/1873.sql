select employee_id, IF(employee_id % 2 != 0 and name not like 'M%', salary, 0) as bonus
from Employees
order by 1