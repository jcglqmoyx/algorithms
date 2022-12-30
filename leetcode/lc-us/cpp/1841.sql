SELECT distinct team_name,
                COUNT(*)                                                          AS matches_played,
                SUM(
                        CASE
                            WHEN (team_id = home_team_id AND home_team_goals > away_team_goals) OR
                                 (team_id = away_team_id AND home_team_goals < away_team_goals) THEN 3
                            WHEN (team_id = home_team_id AND home_team_goals < away_team_goals) OR
                                 (team_id = away_team_id AND home_team_goals > away_team_goals) THEN 0
                            ELSE 1 END)                                           AS points,
                SUM(IF(team_id = home_team_id, home_team_goals, away_team_goals)) AS goal_for,
                SUM(IF(team_id = home_team_id, away_team_goals, home_team_goals)) AS goal_against,
                SUM(IF(team_id = home_team_id, home_team_goals, away_team_goals)) -
                SUM(IF(team_id = home_team_id, away_team_goals, home_team_goals)) AS goal_diff
FROM Teams
         JOIN Matches ON team_id = home_team_id OR team_id = away_team_id
GROUP BY team_id
ORDER BY points DESC, goal_diff DESC, team_name ASC