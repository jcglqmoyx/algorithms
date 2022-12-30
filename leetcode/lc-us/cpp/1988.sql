select school_id,
       coalesce(min(score), -1) as score
from (
         select s.school_id,
                e.score
         from schools s
                  left join exam e on
             s.capacity >= e.student_count
     ) tmp
group by school_id;