select sum(if(dayofweek(submit_date) in (1, 7), 1, 0))          weekend_cnt,
       sum(if(dayofweek(submit_date) in (2, 3, 4, 5, 6), 1, 0)) working_cnt
from Tasks;