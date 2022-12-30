select c.team_id,
       c.name,
       cast(c.berk as signed) - cast(c.afrk as signed) as rank_diff
from (
         select a.team_id,
                a.name,
                row_number() over (order by a.points desc,a.name asc)                      as berk,
                row_number() over (order by (a.points + b.points_change) desc,a.name asc ) as afrk
         from TeamPoints a
                  left join PointsChange b on a.team_id = b.team_id
     ) c