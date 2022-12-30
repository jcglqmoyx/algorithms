with a as (select count(*) as ex from NewYork where score >= 90),
     b as (select count(*) as ex from California where score >= 90)
select case
           when a.ex > b.ex then 'New York University'
           when a.ex < b.ex then 'California University'
           else 'No Winner' end as winner
from a
         inner join b