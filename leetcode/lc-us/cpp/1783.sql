select player_id,
       player_name,
       sum((case when wimbledon = player_id then 1 else 0 end) + (case when Fr_open = player_id then 1 else 0 end) +
           (case when US_open = player_id then 1 else 0 end) +
           (case when Au_open = player_id then 1 else 0 end)) as grand_slams_count
from championships
         cross join players
group by player_id
having grand_slams_count > 0;