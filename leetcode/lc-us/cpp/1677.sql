SELECT p1.name                     AS 'name',
       IFNULL(SUM(i1.rest), 0)     AS 'rest',
       IFNULL(SUM(i1.paid), 0)     AS 'paid',
       IFNULL(SUM(i1.canceled), 0) AS 'canceled',
       IFNULL(SUM(i1.refunded), 0) AS 'refunded'
FROM Product as p1
         LEFT OUTER JOIN Invoice AS i1 ON i1.product_id = p1.product_id
GROUP BY p1.product_id
ORDER BY p1.name;