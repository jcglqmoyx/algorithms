SELECT s1.student_name AS 'member_A', s2.student_name AS 'member_B', s3.student_name AS 'member_C'
FROM SchoolA AS s1
         CROSS JOIN SchoolB AS s2
         CROSS JOIN SchoolC AS s3
WHERE s1.student_id <> s2.student_id
  AND s2.student_id <> s3.student_id
  AND s1.student_id <> s3.student_id
  AND s1.student_name <> s2.student_name
  AND s2.student_name <> s3.student_name
  AND s1.student_name <> s3.student_name;