SELECT employee_id, name, b.salary, b.team_id
FROM Employees a
         INNER JOIN (SELECT salary, dense_rank() over (ORDER BY salary) AS team_id
                     FROM Employees
                     GROUP BY salary
                     HAVING COUNT(DISTINCT employee_id) > 1) b ON a.salary = b.salary
ORDER BY b.team_id, employee_id