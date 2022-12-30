SELECT home_team, away_team
FROM (SELECT t1.team_name home_team, t2.team_name away_team
      FROM Teams t1
               JOIN Teams t2 ON t1.team_name != t2.team_name) temp