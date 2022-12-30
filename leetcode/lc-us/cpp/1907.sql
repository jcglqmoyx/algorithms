SELECT 'High Salary' category, count(1) accounts_count
FROM accounts
WHERE income > 50000
UNION
SELECT 'Average Salary' category, count(1) accounts_count
FROM accounts
WHERE income >= 20000
  AND income <= 50000
UNION
SELECT 'Low Salary' category, count(1) accounts_count
FROM accounts
WHERE income < 20000