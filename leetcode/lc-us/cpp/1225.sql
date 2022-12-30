SELECT period_state, MIN(date) as start_date, MAX(date) as end_date
FROM (
         SELECT success_date                                                                 AS date,
                "succeeded"                                                                  AS period_state,
                IF(DATEDIFF(@pre_date, @pre_date := success_date) = -1, @id, @id := @id + 1) AS id
         FROM Succeeded,
              (SELECT @id := 0, @pre_date := NULL) AS temp
         UNION
         SELECT fail_date                                                                 AS date,
                "failed"                                                                  AS period_state,
                IF(DATEDIFF(@pre_date, @pre_date := fail_date) = -1, @id, @id := @id + 1) AS id
         FROM Failed,
              (SELECT @id := 0, @pre_date := NULL) AS temp
     ) T
WHERE date BETWEEN "2019-01-01" AND "2019-12-31"
GROUP BY T.id
ORDER BY start_date