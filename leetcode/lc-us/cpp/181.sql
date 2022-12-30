SELECT A.Name AS Employee
FROM Employee AS A
         JOIN Employee AS B
              ON A.ManagerId = B.Id AND A.Salary > B.Salary;
