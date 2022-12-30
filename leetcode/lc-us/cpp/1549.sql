select p.product_name, t1.product_id, t1.order_id, t1.order_date
from products p
         join (select product_id,
                      order_id,
                      order_date,
                      rank() over (partition by product_id order by order_date desc) as r from orders o) as t1
              on p.product_id = t1.product_id
where t1.r = 1
order by p.product_name, t1.product_id, t1.order_id;