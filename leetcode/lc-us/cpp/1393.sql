SELECT stock_name, SUM(case WHEN operation = 'Buy' THEN -price ELSE price end) AS capital_gain_loss
FROM stocks
GROUP BY stock_name;