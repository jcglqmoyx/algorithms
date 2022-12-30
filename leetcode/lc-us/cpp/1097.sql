SELECT first_day                                                                                    AS install_dt,
       count(DISTINCT player_id)                                                                    AS installs,
       ROUND((SUM(if(datediff(event_date, first_day) = 1, 1, 0))) / (count(DISTINCT player_id)), 2) AS Day1_retention
FROM (SELECT player_id, event_date, MIN(event_date) over (partition by player_id) AS first_day FROM Activity) a
GROUP BY first_day