WITH temp AS (
    SELECT team_id,
           team_name,
           CASE
               WHEN host_goals > guest_goals THEN IF(host_team = team_id, 3, 0)
               WHEN host_goals = guest_goals THEN 1
               WHEN host_goals < guest_goals THEN IF(host_team = team_id, 0, 3)
               END AS point
    FROM teams
             LEFT JOIN matches ON team_id IN (host_team, guest_team)
)
SELECT team_id, team_name, ifnull(sum(point), 0) num_points
FROM temp
GROUP BY team_id, team_name
ORDER BY num_points DESC, team_id;