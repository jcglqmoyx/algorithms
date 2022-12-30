SELECT spend_date,
       b.platform,
       SUM(if(a.platform = b.platform, amount, 0)) AS total_amount,
       COUNT(if(a.platform = b.platform, 1, null)) AS total_users
FROM (SELECT spend_date,
             user_id,
             if(COUNT(distinct platform) = 2,
                'both', platform) AS platform,
             SUM(amount)          AS amount
      FROM spending
      GROUP BY user_id, spend_date) a,
     (SELECT 'desktop' AS platform
      UNION
      SELECT 'mobile' AS platform
      UNION
      SELECT 'both' AS platform) b
GROUP BY spend_date, platform