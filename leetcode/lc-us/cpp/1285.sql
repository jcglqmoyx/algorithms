SELECT MIN(log_id) START_ID, MAX(log_id) END_ID
FROM (SELECT DISTINCT log_id, log_id - ROW_NUMBER() OVER ( ORDER BY log_id ASC ) reference FROM Logs) T
GROUP BY reference
ORDER BY START_ID