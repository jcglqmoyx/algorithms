SELECT project_id, employee_id
FROM (SELECT project_id, employee_id, dense_rank() over (partition by project_id ORDER BY experience_years DESC) AS rk
      FROM employee
               JOIN project USING (employee_id)) AS newtable
WHERE rk = 1