SELECT p1.product_name AS 'product_name', SUM(o1.unit) AS 'unit'
FROM Orders AS o1
         LEFT OUTER JOIN Products AS p1 ON o1.product_id = p1.product_id
WHERE o1.order_date BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY o1.product_id
HAVING SUM(o1.unit) >= 100;