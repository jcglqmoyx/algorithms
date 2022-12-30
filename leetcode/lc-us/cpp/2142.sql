select b.bus_id, count(t.passenger_id) passengers_cnt
from Buses b
         left join (
    select p.passenger_id, min(b.arrival_time) bus_arrival_time
    from Passengers p
             left join Buses b on b.arrival_time >= p.arrival_time
    group by p.passenger_id
) t on b.arrival_time = t.bus_arrival_time
group by b.bus_id
order by b.bus_id;