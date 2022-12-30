select distinct newtable.id, name
from accounts
         join (select l2.id, l2.login_date
               from logins l2
                        join logins l1 on l1.id = l2.id and datediff(l2.login_date, l1.login_date) between 0 and 4
               group by l1.id, l1.login_date
               having count(distinct l2.login_date) = 5) as newtable on accounts.id = newtable.id
order by newtable.id;