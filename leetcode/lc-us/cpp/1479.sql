select distinct b.item_category as                                                        Category,
                ifnull(sum(case when dayofweek(a.order_date) = 2 then a.quantity end), 0) Monday,
                ifnull(sum(case when dayofweek(a.order_date) = 3 then a.quantity end), 0) Tuesday,
                ifnull(sum(case when dayofweek(a.order_date) = 4 then a.quantity end), 0) Wednesday,
                ifnull(sum(case when dayofweek(a.order_date) = 5 then a.quantity end), 0) Thursday,
                ifnull(sum(case when dayofweek(a.order_date) = 6 then a.quantity end), 0) Friday,
                ifnull(sum(case when dayofweek(a.order_date) = 7 then a.quantity end), 0) Saturday,
                ifnull(sum(case when dayofweek(a.order_date) = 1 then a.quantity end), 0) Sunday
from Orders a
         right join Items b
                    on a.item_id = b.item_id
group by Category
order by Category