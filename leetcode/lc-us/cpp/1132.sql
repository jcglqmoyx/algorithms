SELECT ROUND(AVG(proportion) * 100, 2) AS average_daily_percent
FROM (
         SELECT actions.action_date, COUNT(DISTINCT removals.post_id) / COUNT(DISTINCT actions.post_id) AS proportion
         FROM actions
                  LEFT JOIN removals
                            ON actions.post_id = removals.post_id
         WHERE extra = 'spam'
         GROUP BY actions.action_date
     ) a