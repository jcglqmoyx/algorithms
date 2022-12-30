SELECT post_id, COUNT(sub_id) AS number_of_comments
FROM (
         SELECT DISTINCT post.sub_id AS post_id, sub.sub_id AS sub_id
         FROM Submissions post
                  LEFT JOIN Submissions sub
                            ON post.sub_id = sub.parent_id
         WHERE post.parent_id is null
     ) T
GROUP BY post_id
ORDER BY post_id