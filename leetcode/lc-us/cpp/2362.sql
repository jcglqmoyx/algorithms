select b.product_id, b.quantity, (a.price * b.quantity) price
from products a
         join Purchases b
              using (product_id)
where invoice_id =
      (
          select b.invoice_id
          from products a
                   join Purchases b
                        using (product_id)
          group by 1
          order by sum(a.price * b.quantity) desc, 1
          limit 1)