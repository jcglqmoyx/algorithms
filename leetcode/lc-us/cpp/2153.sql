select id bus_id, if(cum_sum > 0, cnt - cum_sum, cnt) passengers_cnt
from (SELECT *, sum(cnt) over (order by dt,mark desc) cum, if(@t > 0, @t := cnt, @t := @t + cnt) cum_sum
      FROM (select 'b' mark, bus_id id, arrival_time dt, capacity cnt
            from Buses
            union
            select 'p' mark, passenger_id id, arrival_time dt, -1 cnt
            from Passengers) a
               join (select @t := 0 flag) b
      order by dt, mark desc) tmp
where mark = 'b'
order by bus_id;