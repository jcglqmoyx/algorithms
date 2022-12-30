with Friendship_new as
         (select a.user1_id, a.user2_id
          from Friendship a
          UNION ALL
          select b.user2_id, b.user1_id
          from Friendship b)
select a.user1_id as user1_id,
       b.user1_id as user2_id,
       COUNT(1)      common_friend
from Friendship_new a,
     Friendship_new b
where a.user1_id <> b.user1_id
  AND a.user1_id < b.user1_id
  AND a.user2_id = b.user2_id
  AND exists(select 1
             from Friendship c
             where c.user1_id = a.user1_id
               AND b.user1_id = c.user2_id)
GROUP BY a.user1_id, b.user1_id
HAVING COUNT(1) >= 3