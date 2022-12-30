(
    select Users.name as results
    FROM MovieRating
             JOIN Users ON MovieRating.user_id = Users.user_id
    GROUP BY MovieRating.user_id
    ORDER BY count(MovieRating.user_id) desc,
             Users.name
    LIMIT 1
)
UNION
(
    select Movies.title as results
    FROM MovieRating
             JOIN Movies ON MovieRating.movie_id = Movies.movie_id
    WHERE MovieRating.created_at >= '2020-02-01'
      AND MovieRating.created_at < '2020-03-01'
    GROUP BY MovieRating.movie_id
    ORDER BY avg(MovieRating.rating) desc,
             Movies.title
    LIMIT 1
)