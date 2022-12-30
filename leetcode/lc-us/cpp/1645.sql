with RECURSIVE f(n) as (select 1 union all select n + 1 from f where n < 12),
               a as (select driver_id, date_format(join_date, '%Y-%m') as join_month
                     from drivers
                     where date_format(join_date, '%Y-%m') < '2021-01'
                       and date_format(join_date, '%Y-%m') >= '2020-01'),
               b as (select join_month, count(driver_id) as amount from a group by join_month order by join_month),
               bb as (select '2020-01' as join_month, count(driver_id) as amount
                      from drivers
                      where date_format(join_date, '%Y-%m') < '2020-01'
                      union all
                      select join_month, amount
                      from b),
               cc as (select join_month, sum(amount) as amount from bb group by join_month),
               c as (select n as join_month, ifnull(amount, 0) as sm
                     from f
                              left join cc on month(CONCAT(join_month, '-01')) = f.n),
               c1 as (select join_month, sum(sm) over (order by join_month) as sm from c),
               d as (select acceptedRides.ride_id,
                            acceptedRides.driver_id,
                            date_format(requested_at, '%Y-%m') as accept_month
                     from acceptedRides
                              left join rides on rides.ride_id = acceptedRides.ride_id
                     where requested_at like '2020%'
                       and acceptedRides.driver_id in (select driver_id
                                                       from drivers
                                                       where date_format(join_date, '%Y-%m') <=
                                                             date_format(rides.requested_at, '%Y-%m'))
                     order by accept_month),
               dd as (select * from d group by accept_month, driver_id),
               e as (select month(CONCAT(accept_month, '-01')) as accept_month, count(ride_id) as sn
                     from dd
                     group by accept_month),
               g as (select n as month, ifnull(sm, 0) as active_drivers, ifnull(sn, 0) as accepted_rides
                     from f
                              left join c1 on c1.join_month = f.n
                              left join e on e.accept_month = f.n)
select month, if(accepted_rides = 0, 0, round(accepted_rides / active_drivers * 100, 2)) as working_percentage
from g