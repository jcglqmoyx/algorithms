SELECT DISTINCT account_id
FROM (SELECT c.account_id, c.date, (c.date - row_number() over (Partition by c.account_id ORDER BY c.date)) AS label
      FROM (SELECT account_id, EXTRACT(YEAR_MONTH FROM day) AS date, SUM(amount) AS total
            FROM Transactions
            WHERE type = 'Creditor'
            GROUP BY account_id, EXTRACT(YEAR_MONTH FROM day)) c
               INNER JOIN Accounts d ON c.account_id = d.account_id AND c.total > d.max_income) a
GROUP BY account_id, label
HAVING COUNT(date) >= 2