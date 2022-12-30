SELECT DISTINCT buyer_id AS "buyer_id"
FROM Sales AS s1
         INNER JOIN Product AS p1 ON s1.product_id = p1.product_id
WHERE p1.product_name = 'S8'
  AND buyer_id NOT IN (SELECT buyer_id
                       FROM Sales AS s2
                                INNER JOIN Product AS p2 ON s2.product_id = p2.product_id
                       WHERE p2.product_name = 'iPhone');