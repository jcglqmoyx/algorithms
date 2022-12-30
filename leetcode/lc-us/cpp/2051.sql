select m.member_id,
       m.name,
       case
           when count(v.visit_id) = 0 then 'Bronze'
           when count(p.visit_id) / count(v.visit_id) < 0.5 then 'Silver'
           when count(p.visit_id) / count(v.visit_id) >= 0.8 then 'Diamond'
           else 'Gold' end as category
from members as m
         left join visits as v on m.member_id = v.member_id
         left join Purchases as p on v.visit_id = p.visit_id
group by m.member_id, m.name