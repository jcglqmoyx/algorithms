select s.user_id,
       sum(p.price * s.quantity) as spending
from Sales s
         inner join Product p
                    on s.product_id = p.product_id
group by s.user_id
order by spending desc, s.user_id