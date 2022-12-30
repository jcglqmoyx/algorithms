WITH l AS (
    SELECT DISTINCT user_id
                  , song_id
                  , day
    FROM Listens
),
     f AS (
         SELECT DISTINCT l1.user_id AS uid
                       , l2.user_id AS fid
         FROM l AS l1,
              l AS l2
         WHERE l2.user_id > l1.user_id
           AND l2.song_id = l1.song_id
           AND l2.day = l1.day
         GROUP BY l1.user_id, l2.user_id, l1.day
         HAVING COUNT(l2.song_id = l1.song_id) >= 3
     )
SELECT f.uid AS user1_id
     , f.fid AS user2_id
FROM f
         JOIN Friendship AS fe
              ON fe.user1_id = f.uid
                  AND fe.user2_id = f.fid
;














