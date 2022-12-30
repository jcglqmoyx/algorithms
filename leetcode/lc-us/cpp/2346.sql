select student_id,
       department_id,
       round((percent_rank() over (partition by department_id order by mark desc)) * 100, 2) as percentage
from Students