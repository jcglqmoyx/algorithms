SELECT round(part.hasCount / total.totalCount, 2) AS 'fraction'
FROM (
         SELECT count(a1.player_id) AS 'hasCount'
         FROM (
                  SELECT player_id, min(event_date) AS 'firstData'
                  FROM activity
                  GROUP BY player_id
              ) a1,
              activity a2
         WHERE a1.player_id = a2.player_id
           AND DATEDIFF(a2.event_date, a1.firstData) = 1
     ) AS part,
     (SELECT count(DISTINCT player_id) AS 'totalCount' FROM activity) AS total
