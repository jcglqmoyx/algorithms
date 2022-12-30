select a.month,
       sum(ifnull(c.c, 0)) over (order by a.month) as active_drivers,
       ifnull(b.accepted_rides, 0)                 as accepted_rides
from (select 1 as month
      union
      select 2
      union
      select 3
      union
      select 4
      union
      select 5
      union
      select 6
      union
      select 7
      union
      select 8
      union
      select 9
      union
      select 10
      union
      select 11
      union
      select 12) a
         left join (select month(r.requested_at) as month, count(a.ride_id) as accepted_rides
                    from Rides r
                             inner join AcceptedRides a on r.ride_id = a.ride_id and left(r.requested_at, 4) = '2020'
                    group by 1) b on a.month = b.month
         left join (select month, sum(cn) as c
                    from (select month(join_date) as month, count(*) as cn
                          from Drivers
                          where left(join_date, 4) = '2020'
                          group by 1
                          union all
                          (select '1', count(*) from Drivers where datediff('2020-01-01', join_date) > 0)) t2
                    group by 1) c on a.month = c.month
order by 1;