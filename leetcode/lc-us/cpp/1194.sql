SELECT group_id, player_id
FROM (
         SELECT group_id, player_id, SUM(score) AS score
         FROM (
                  SELECT Players.group_id, Players.player_id, SUM(Matches.first_score) AS score
                  FROM Players
                           JOIN Matches ON Players.player_id = Matches.first_player
                  GROUP BY Players.player_id

                  UNION ALL

                  SELECT Players.group_id, Players.player_id, SUM(Matches.second_score) AS score
                  FROM Players
                           JOIN Matches ON Players.player_id = Matches.second_player
                  GROUP BY Players.player_id
              ) s
         GROUP BY player_id
         ORDER BY score DESC, player_id
     ) result
GROUP BY group_id;