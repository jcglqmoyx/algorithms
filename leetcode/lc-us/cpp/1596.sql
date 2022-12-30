select a.customer_id, a.product_id, b.product_name
from (select customer_id, product_id, rank() over (partition by customer_id order by cnt desc) as rk
      from (select customer_id, product_id, count(1) as cnt from Orders group by customer_id, product_id) a) a
         join Products b on a.product_id = b.product_id
where a.rk = 1
order by customer_id, product_id