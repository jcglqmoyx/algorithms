SELECT product_id,
       year AS first_year,
       quantity,
       price
FROM (SELECT product_id,
             year,
             quantity,
             price,
             dense_rank()
                     over
                         (partition BY product_id
                         ORDER BY year ASC) AS rk
      FROM sales) AS newtable
WHERE rk = 1;