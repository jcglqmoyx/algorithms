with t as (select user1_id u1, user2_id u2 from Friendship union all select user2_id u1, user1_id u2 from Friendship)
select u2 user_id, page_id, count(1) friends_likes
from Likes l
         left join t on l.user_id = t.u1
where not exists(select user_id, page_id from Likes where user_id = t.u2 and page_id = l.page_id)
group by 1, 2
order by 1, 2 desc