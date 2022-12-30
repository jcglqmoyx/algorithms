select *
from Orders
where not (customer_id in (select distinct customer_id from Orders where order_type = 0) and order_type = 1)