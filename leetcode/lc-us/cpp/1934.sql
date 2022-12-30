SELECT s.user_id,
       ifnull(round(sum(action = 'confirmed') / count(c.action), 2), 0.00) AS confirmation_rate
FROM signups AS s
         LEFT JOIN confirmations AS c ON s.user_id = c.user_id
GROUP BY s.user_id