SELECT p1.product_id AS 'product_id', p1.product_name AS 'product_name'
FROM Product AS p1
         INNER JOIN Sales AS s1 ON p1.product_id = s1.product_id
GROUP BY p1.product_id
HAVING '2019-01-01' <= MIN(s1.sale_date)
   AND MAX(s1.sale_date) <= '2019-03-31';