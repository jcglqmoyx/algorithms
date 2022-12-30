select customer_id, customer_name
from orders
         join customers using (customer_id)
group by customer_id
having sum(product_name = 'A') >= 1
   and sum(product_name = 'B') >= 1
   and sum(product_name = 'C') < 1
order by customer_id ASC;