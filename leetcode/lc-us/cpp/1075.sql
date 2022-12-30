SELECT project_id AS 'project_id', ROUND(AVG(experience_years), 2) AS 'average_years'
FROM Project AS p1
         INNER JOIN Employee AS e1 ON p1.employee_id = e1.employee_id
GROUP BY p1.project_id