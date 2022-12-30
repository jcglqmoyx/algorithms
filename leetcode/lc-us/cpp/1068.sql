SELECT product_name, year, price
FROM Sales AS s
         JOIN Product AS p ON s.product_id = p.product_id;