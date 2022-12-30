select distinct p1.user_id
from Purchases p1
         left join Purchases p2
                   on p1.purchase_date <= p2.purchase_date
                       and p2.purchase_date <= date_add(p1.purchase_date, interval 7 day)
                       and p1.purchase_id != p2.purchase_id
                       and p1.user_id = p2.user_id
where p2.user_id is not null
order by 1