SELECT login_date,
       COUNT(user_id) user_count
FROM (SELECT user_id,
             MIN(activity_date) login_date
      FROM Traffic
      WHERE activity = 'login'
      GROUP BY user_id) t
WHERE datediff('2019-06-30', login_date) <= 90
GROUP BY login_date;