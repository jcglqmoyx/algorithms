SELECT ID, COMPANY, SALARY
FROM (SELECT *,
             RANK() OVER (PARTITION BY COMPANY ORDER BY SALARY, ID)           AS R1,
             RANK() OVER (PARTITION BY COMPANY ORDER BY SALARY DESC, ID DESC) AS R2
      FROM EMPLOYEE) AS A
WHERE R1 BETWEEN R2 - 1 AND R2 + 1;