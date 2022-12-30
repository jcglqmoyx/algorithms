SELECT transaction_id
FROM (SELECT transaction_id, rank() OVER (PARTITION BY date_format(DAY, "%Y%m%e") ORDER BY amount DESC) AS rnk
      FROM Transactions) tmp
WHERE rnk = 1
ORDER BY transaction_id