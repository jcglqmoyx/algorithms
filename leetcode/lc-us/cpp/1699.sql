select p1 as person1, p2 as person2, count(*) as call_count, sum(duration) as total_duration
from (select if(from_id > to_id, to_id, from_id) as p1, if(from_id > to_id, from_id, to_id) as p2, duration
      from calls) as newtable
group by p1, p2;