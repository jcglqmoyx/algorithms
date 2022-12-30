SELECT avg(num) median
FROM (SELECT num,
             SUM(frequency) over (ORDER BY num)      asc_accumu,
             SUM(frequency) over (ORDER BY num desc) desc_accumu
      FROM numbers) t1,
     (SELECT SUM(frequency) total FROM numbers) t2
WHERE asc_accumu >= total / 2
  AND desc_accumu >= total / 2