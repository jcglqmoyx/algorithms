with a as (select post_id, topic_id
           from posts
                    left join keywords
                              on POSITION(concat(' ', keywords.word, ' ') in concat(' ', posts.content, ' ')) > 0),
     b as (select post_id, group_concat(distinct topic_id order by topic_id) topic from a group by post_id)
select post_id, ifnull(topic, 'Ambiguous!') topic
from b