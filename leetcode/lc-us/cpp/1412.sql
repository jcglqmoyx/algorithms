select student_id, student_name
from student
where student_id not in
      (
          select student_id
          from (select student_id, rank() over (partition by exam_id order by score desc) as rk1 from exam) a
          where rk1 = 1
          union all
          select student_id
          from (select student_id, rank() over (partition by exam_id order by score asc) as rk2 from exam) b
          where rk2 = 1
          union all
          select student_id
          from student
          where student_id not in (select distinct student_id from exam)
      )
order by student_id;