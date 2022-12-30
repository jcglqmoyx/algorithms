with t as (select airport, sum(flights_count) sum_flights_count
           from (select departure_airport as airport, flights_count
                 from flights
                 union all
                 select arrival_airport as airport, flights_count
                 from flights) as f
           group by airport)
select airport as airport_id
from t
where sum_flights_count >= all (select sum_flights_count from t)