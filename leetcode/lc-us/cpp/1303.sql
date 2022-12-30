SELECT e1.employee_id AS 'employee_id', tmp1.cnt AS 'team_size'
FROM Employee AS e1
         INNER JOIN
     (
         SELECT team_id, COUNT(*) AS 'cnt'
         FROM Employee
         GROUP BY team_id
     ) AS tmp1 ON e1.team_id = tmp1.team_id
;