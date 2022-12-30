SELECT s1.seller_name AS 'seller_name'
FROM Seller AS s1
WHERE s1.seller_id NOT IN (SELECT DISTINCT seller_id FROM Orders AS o1 WHERE YEAR(o1.sale_date) = '2020')
ORDER BY s1.seller_name;