WITH a AS (SELECT player_id, result, IFNULL(LAG(player_id) OVER (order by player_id, match_day), player_id) AS last_one
           FROM Matches
           ORDER BY player_id, match_day)

SELECT player_id, MAX(longest_streak) longest_streak
FROM (SELECT player_id,
             result,
             CASE
                 WHEN result = 'Win' and player_id = last_one THEN @P := @P + 1
                 WHEN result = 'Win' and player_id != last_one THEN @P := 1
                 WHEN result != 'Win' THEN @P := 0
                 END AS longest_streak
      FROM a,
           (SELECT @P := 0) b) c
GROUP BY player_id
ORDER BY player_id