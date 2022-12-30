select a.user1_id, a.user2_id
from (select a.user_id                            user1_id,
             b.user_id                            user2_id,
             rank() over (order by COUNT(1) desc) rn
      from Relations a,
           Relations b
      where a.user_id < b.user_id
        AND a.follower_id = b.follower_id
      group by a.user_id, b.user_id) A
WHERE A.rn = 1