select name as customer_name, customer_id, order_id, order_date
from (select name,
             customer_id,
             order_id,
             order_date,
             row_number() over (partition by customer_id order by order_date desc) as rn
      from customers
               join orders using (customer_id)) as newtable
where rn = 1
   or rn = 2
   or rn = 3
order by customer_name, customer_id, order_date desc;