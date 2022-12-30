with t as (
    select *,
           @g := if(@h = hall_id and @e >= start_day, @g, @g + 1) as g,
           @e := if(@h = hall_id and @e >= end_day, @e, end_day),
           @h := hall_id
    from (select * from HallEvents order by hall_id, start_day) as hall,
         (select @g := 0, @e := null, @h := null) as init
)

select hall_id, min(start_day) as start_day, max(end_day) as end_day
from t
group by g