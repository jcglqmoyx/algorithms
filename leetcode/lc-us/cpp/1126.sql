SELECT business_id
FROM Events AS e
         JOIN (SELECT event_type, AVG(occurences) AS eventAvg FROM Events GROUP BY event_type) AS e1
              ON e.event_type = e1.event_type
WHERE e.occurences > e1.eventAvg
GROUP BY business_id
HAVING COUNT(*) >= 2