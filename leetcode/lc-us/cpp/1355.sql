select activity as ACTIVITY
from friends
group by activity
having count(*) > any (select count(*) from friends group by activity)
   and count(*) < any (select count(*) from friends group by activity)