SELECT contest_id                                                                      AS 'contest_id',
       ROUND(COUNT(DISTINCT r1.user_id) / (SELECT COUNT(user_id) FROM Users) * 100, 2) AS 'percentage'
FROM Register AS r1
GROUP BY r1.contest_id
ORDER BY percentage DESC, contest_id;