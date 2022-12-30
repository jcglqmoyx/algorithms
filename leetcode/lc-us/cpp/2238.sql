SELECT r1.driver_id, COUNT(r2.ride_id) as cnt
FROM (
         SELECT DISTINCT driver_id
         FROM Rides
     ) r1
         LEFT JOIN Rides r2 ON r1.driver_id = r2.passenger_id
GROUP BY r1.driver_id