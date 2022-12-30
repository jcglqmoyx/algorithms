SELECT DISTINCT t.user1_id AS user_id, t.user2_id AS recommended_id
FROM (SELECT a.user_id                                                      AS user1_id
           , b.user_id                                                      AS user2_id
           , a.song_id
           , a.day
           , COUNT(a.song_id) OVER (PARTITION BY a.day,a.user_id,b.user_id) AS cnt
      FROM (SELECT DISTINCT * FROM Listens) a
               INNER JOIN (SELECT DISTINCT * FROM Listens) b
                          ON a.user_id <> b.user_id
                              AND a.song_id = b.song_id
                              AND a.day = b.day) t
         LEFT JOIN Friendship t1
                   ON t.user1_id = t1.user1_id AND t.user2_id = t1.user2_id
         LEFT JOIN Friendship t2
                   ON t.user1_id = t2.user2_id AND t.user2_id = t2.user1_id
WHERE t.cnt >= 3
  AND t1.user1_id IS NULL
  AND t2.user1_id IS NULL