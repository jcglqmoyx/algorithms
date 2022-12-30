SELECT student_id, course_id, grade
FROM (SELECT *, row_number() over (partition by student_id ORDER BY grade desc,course_id) AS rownum FROM enrollments) t1
WHERE rownum = 1
ORDER BY student_id