with recursive t(task_id, subtask_id) as (SELECT task_id, subtasks_count
                                          FROM Tasks
                                          UNION ALL
                                          SELECT task_id, subtask_id - 1
                                          FROM t
                                          where subtask_id - 1 > 0)
SELECT *
FROM t
         left join Executed using (task_id, subtask_id)
WHERE Executed.subtask_id is null
ORDER BY task_id, subtask_id