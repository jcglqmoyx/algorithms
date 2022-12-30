with t1 as (
    select customer_id,
           year(order_date) as year,
           sum(price)       as tot
    from Orders
    group by 1, 2
),
     t2 as (
         select *,
                lag(year, 1, null) over (partition by customer_id order by year) as pre_year,
                lag(tot, 1, null) over (partition by customer_id order by year)  as pre_tot
         from t1
     )

select distinct customer_id
from t2
where customer_id not in (
    select customer_id
    from t2
    where pre_year is not null
      and (year != pre_year + 1 or tot <= pre_tot)
)