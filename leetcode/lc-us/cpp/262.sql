SELECT request_at              as Day,
       ROUND(COUNT(CASE
                       WHEN status != 'completed'
                           THEN 1
           END) / COUNT(*), 2) AS "Cancellation Rate"
FROM Trips
         INNER JOIN Users client ON client.users_id = Trips.client_id
         INNER JOIN Users driver ON driver.users_id = Trips.driver_id
WHERE client.banned = 'No'
  AND driver.banned = 'No'
  AND request_at >= "2013-10-01"
  AND request_at <= "2013-10-03"
GROUP BY request_at