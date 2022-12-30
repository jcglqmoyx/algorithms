with a as (
    select caller_id caller, duration
    from Calls
    union all
    select callee_id caller, duration
    from Calls
)
select c.name country
from a
         left join Person p on a.caller = p.id
         left join Country c on left(p.phone_number, 3) = c.country_code
group by c.name
having avg(a.duration) > (select avg(duration) from a)