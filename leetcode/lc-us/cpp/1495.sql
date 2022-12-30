SELECT DISTINCT c1.title AS 'title'
FROM Content AS c1
         INNER JOIN TVProgram AS t1
                    ON t1.content_id = c1.content_id
WHERE t1.program_date BETWEEN '2020-06-01' AND '2020-06-30'
  AND c1.Kids_content = 'Y'
  AND c1.content_type = 'Movies'
;