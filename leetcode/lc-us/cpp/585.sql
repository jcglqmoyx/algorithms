select round(sum(tiv_2016), 2) as tiv_2016
from (
         select tiv_2016,
                count(1) over (partition by tiv_2015) as tiv_2015_count,
                count(1) over (partition by lat, lon) as location_count
         from Insurance
     ) tmp
where tiv_2015_count <> 1
  and location_count = 1;