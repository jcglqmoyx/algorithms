SELECT '[0-5>' AS 'bin', COUNT(*) AS 'total'
FROM Sessions
WHERE 0 <= duration / 60
  AND duration / 60 < 5
UNION ALL
SELECT '[5-10>' AS 'bin', COUNT(*) AS 'total'
FROM Sessions
WHERE 5 <= duration / 60
  AND duration / 60 < 10
UNION ALL
SELECT '[10-15>' AS 'bin', COUNT(*) AS 'total'
FROM Sessions
WHERE 10 <= duration / 60
  AND duration / 60 < 15
UNION ALL
SELECT '15 or more' AS 'bin', COUNT(*) AS 'total'
FROM Sessions
WHERE 15 <= duration / 60;