SELECT unique_id, name
FROM Employees AS a
         LEFT JOIN EmployeeUNI AS b ON a.id = b.id;