select c.user_id,
       c.product_id
from (
         select a.user_id,
                a.product_id,
                dense_rank() over (partition by a.user_id order by sum(a.quantity * b.price) desc) as rk
         from Sales as a
                  join Product as b on a.product_id = b.product_id
         group by a.user_id, a.product_id
     ) as c
where c.rk = 1