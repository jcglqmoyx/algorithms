SELECT b.book_id, name
FROM books b
         LEFT JOIN orders o ON b.book_id = o.book_id AND dispatch_date >= '2018-06-23'
WHERE available_from < '2019-05-23'
GROUP BY b.book_id
HAVING IFNULL(SUM(quantity), 0) < 10