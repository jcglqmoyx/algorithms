SELECT stu.student_id          AS 'student_id',
       stu.student_name        AS 'student_name',
       sub.subject_name        AS 'subject_name',
       COUNT(exa.subject_name) AS 'attended_exams'
FROM Students AS stu
         CROSS JOIN Subjects AS sub
         LEFT OUTER JOIN Examinations AS exa ON stu.student_id = exa.student_id AND sub.subject_name = exa.subject_name
GROUP BY stu.student_id, sub.subject_name
ORDER BY stu.student_id, sub.subject_name
;