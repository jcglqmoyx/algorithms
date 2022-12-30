with recursive t as (select 1 customer_id
                     union all
                     select customer_id + 1
                     from t
                     where customer_id < (select max(customer_id) from Customers))
select t.customer_id as ids
from t
         left join Customers t1 on t.customer_id = t1.customer_id
where t1.customer_id is null