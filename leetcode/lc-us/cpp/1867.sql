SELECT order_id
FROM OrdersDetails
GROUP BY order_id
HAVING max(quantity) > ALL (SELECT avg(quantity) FROM OrdersDetails GROUP BY order_id);