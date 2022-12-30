SELECT class
FROM courses
GROUP BY class
HAVING COUNT(distinct student) >= 5;