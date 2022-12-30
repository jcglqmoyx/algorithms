SELECT name, balance
FROM (select name, sum(amount) AS balance
      FROM Users u
               JOIN Transactions t ON u.account = t.account
      GROUP BY u.account) AS temp
WHERE balance > 10000;