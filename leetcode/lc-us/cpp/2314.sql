with t as (select city_id,
                  day,
                  degree,
                  dense_rank() over (partition by city_id order by degree desc, day) as rnk
           from weather
)
select city_id, day, degree
from t
where t.rnk = 1