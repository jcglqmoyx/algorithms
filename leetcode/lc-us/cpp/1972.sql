with a as (
    SELECT caller_id, recipient_id, call_time
    FROM Calls
    UNION ALL
    SELECT recipient_id caller_id, caller_id recipient_id, call_time
    FROM Calls
)

SELECT DISTINCT a.caller_id user_id
FROM (SELECT caller_id,
             recipient_id,
             dense_rank() over (PARTITION BY caller_id, DATE_FORMAT(call_time, '%Y-%m-%d') order by call_time) AS rk
      FROM a) a
         INNER JOIN
     (SELECT caller_id,
             recipient_id,
             dense_rank() over (PARTITION BY caller_id, DATE_FORMAT(call_time, '%Y-%m-%d') order by call_time DESC) AS rk
      FROM a) b
     ON a.caller_id = b.caller_id AND a.recipient_id = b.recipient_id AND a.rk = 1 AND b.rk = 1