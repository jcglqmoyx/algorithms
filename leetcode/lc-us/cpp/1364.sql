select i.invoice_id,
       c1.customer_name,
       i.price,
       count(contacts.contact_name) contacts_cnt,
       count(c2.customer_name)      trusted_contacts_cnt
from invoices i
         join customers c1 on i.user_id = c1.customer_id
         left join contacts on i.user_id = contacts.user_id
         left join customers c2 on contacts.contact_email = c2.email
group by i.invoice_id
order by i.invoice_id