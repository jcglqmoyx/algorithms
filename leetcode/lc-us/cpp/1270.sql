SELECT DISTINCT employee_id
FROM (
         SELECT employee_id
         FROM Employees
         WHERE manager_id = 1
         UNION ALL
         SELECT employee_id
         FROM Employees
         WHERE manager_id IN (
             SELECT employee_id
             FROM Employees
             WHERE manager_id = 1
         )
         UNION ALL
         SELECT employee_id
         FROM Employees
         WHERE manager_id IN (
             SELECT employee_id
             FROM Employees
             WHERE manager_id IN (
                 SELECT employee_id
                 FROM Employees
                 WHERE manager_id = 1
             )
         )
     ) T
WHERE employee_id != 1