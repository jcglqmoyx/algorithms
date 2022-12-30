select s1.sale_date as sale_date, s1.sold_num - s2.sold_num as diff
from (select sale_date, sold_num from Sales where fruit = 'apples') s1,
     (select sale_date, sold_num from Sales where fruit = 'oranges') s2
where s1.sale_date = s2.sale_date
order by sale_date