SELECT COUNT(account_id) accounts_count
FROM Subscriptions
WHERE end_date >= '2021-01-01'
  AND start_date <= '2021-12-31'
  AND account_id NOT IN (
    SELECT account_id
    FROM Streams
    WHERE LEFT(stream_date, 4) = 2021
)