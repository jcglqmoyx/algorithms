SELECT f1.follower, COUNT(distinct f2.follower) AS num
FROM follow f1
         JOIN follow f2 ON f1.follower = f2.followee
GROUP BY f2.followee
ORDER BY f1.follower