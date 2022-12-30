SELECT w1.name AS 'WAREHOUSE_NAME', SUM(p1.Width * p1.Length * p1.Height * w1.units) AS 'VOLUME'
FROM Warehouse AS w1
         INNER JOIN Products AS p1 ON w1.product_id = p1.product_id
GROUP BY w1.name;