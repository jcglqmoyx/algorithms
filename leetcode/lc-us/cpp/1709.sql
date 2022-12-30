select user_id, max(datediff(visit_date, last_vist)) as biggest_window
from (select user_id, visit_date, lag(visit_date, 1, null) over (partition by user_id order by visit_date) as last_vist
      from (select distinct user_id, '2021-1-1' visit_date
            from UserVisits
            union all
            select user_id, visit_date
            from UserVisits) t) t1
group by user_id
order by user_id