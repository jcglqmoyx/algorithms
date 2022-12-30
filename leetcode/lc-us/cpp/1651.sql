WITH RECURSIVE t AS (SELECT 1 month UNION ALL SELECT month + 1 FROM t WHERE month < 12)
SELECT t3.month, t3.average_ride_distance, t3.average_ride_duration
FROM (SELECT t2.month,
             ROUND(AVG(ride_distance) OVER (ORDER BY month ROWS BETWEEN CURRENT ROW AND 2 FOLLOWING),
                   2)                                                                                    AS average_ride_distance,
             ROUND(AVG(ride_duration) OVER (ORDER BY month ROWS BETWEEN CURRENT ROW AND 2 FOLLOWING),
                   2)                                                                                    AS average_ride_duration
      FROM (SELECT t.month, IFNULL(t1.ride_distance, 0) AS ride_distance, IFNULL(t1.ride_duration, 0) AS ride_duration
            FROM t
                     LEFT JOIN (SELECT month(requested_at) AS month,
                                       SUM(ride_distance)  AS ride_distance,
                                       SUM(ride_duration)  AS ride_duration
                                FROM Rides a
                                         INNER JOIN AcceptedRides b ON a.ride_id = b.ride_id
                                WHERE year(requested_at) = 2020
                                GROUP BY month(requested_at)) t1 ON t.month = t1.month) t2) t3
WHERE month < 11
ORDER BY month;