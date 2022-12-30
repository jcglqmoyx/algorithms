select t1.visited_on,
       sum(t2.amount)               as amount,
       round(sum(t2.amount) / 7, 2) as average_amount
from (select visited_on, sum(amount) as amount
      from customer
      group by visited_on) as t1,
     (select visited_on, sum(amount) as amount
      from customer
      group by visited_on) as t2
where datediff(t1.visited_on, t2.visited_on) <= 6
  and datediff(t1.visited_on, t2.visited_on) >= 0
  and datediff(t1.visited_on, (select min(visited_on) from customer)) >= 6
group by t1.visited_on;