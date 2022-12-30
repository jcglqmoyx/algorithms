SELECT u1.name AS 'name', IFNULL(SUM(r1.distance), 0) AS 'travelled_distance'
FROM Users AS u1
         LEFT OUTER JOIN Rides AS r1 ON u1.id = r1.user_id
GROUP BY r1.user_id
ORDER BY SUM(r1.distance) DESC, u1.name;