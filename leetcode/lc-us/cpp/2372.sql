SELECT S1.salesperson_id,
       name,
       IFNULL(SUM(price), 0) total

FROM Salesperson S1
         LEFT JOIN Customer C1
                   ON S1.salesperson_id = C1.salesperson_id
         LEFT JOIN Sales S2
                   ON S2.customer_id = C1.customer_id
GROUP BY salesperson_id