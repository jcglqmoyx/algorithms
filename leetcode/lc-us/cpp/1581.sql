SELECT v1.customer_id AS 'customer_id', COUNT(v1.visit_id) AS 'count_no_trans'
FROM Visits AS v1
         LEFT OUTER JOIN Transactions AS t1 ON v1.visit_id = t1.visit_id
WHERE t1.visit_id IS NULL
GROUP BY v1.customer_id;