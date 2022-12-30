SELECT product_id                             AS 'product_id',
       SUM(IF(store = 'store1', price, NULL)) AS 'store1',
       SUM(IF(store = 'store2', price, NULL)) AS 'store2',
       SUM(IF(store = 'store3', price, NULL)) AS 'store3'
FROM Products
GROUP BY product_id;