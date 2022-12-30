with t as (select distinct product_id, year(purchase_date) as yr
           from orders
           group by product_id, year(purchase_date)
           having count(order_id) >= 3)

select distinct product_id
from (select product_id, (yr - row_number() over (partition by product_id order by yr)) as diff from t) as t1
group by product_id, diff
having count(*) >= 2