SELECT session_id
FROM Playback
WHERE session_id NOT IN (SELECT session_id
                         FROM Playback p
                                  JOIN ads a
                         WHERE p.customer_id = a.customer_id
                           AND TIMESTAMP BETWEEN start_time AND end_time)