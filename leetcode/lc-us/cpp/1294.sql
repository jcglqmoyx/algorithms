SELECT country_name        AS 'country_name',
       CASE
           WHEN AVG(w1.weather_state) <= 15 THEN 'Cold'
           WHEN AVG(w1.weather_state) >= 25 THEN 'Hot'
           ELSE 'Warm' END AS 'weather_type'
FROM Countries AS c1
         INNER JOIN Weather AS w1 ON c1.country_id = w1.country_id
WHERE YEAR(w1.day) = 2019
  AND MONTH(w1.day) = 11
GROUP BY c1.country_id;