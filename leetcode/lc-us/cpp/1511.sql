SELECT c1.customer_id AS 'customer_id', c1.name AS 'name'
FROM Orders AS o1
         INNER JOIN Customers AS c1 ON o1.customer_id = c1.customer_id
         INNER JOIN Product AS p1 ON o1.product_id = p1.product_id
GROUP BY customer_id
HAVING SUM(CASE WHEN o1.order_date BETWEEN '2020-06-01' AND '2020-06-30' THEN o1.quantity * p1.price ELSE 0 END) >= 100
   AND SUM(CASE WHEN o1.order_date BETWEEN '2020-07-01' AND '2020-07-31' THEN o1.quantity * p1.price ELSE 0 END) >= 100;