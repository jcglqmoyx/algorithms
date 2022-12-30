SELECT id      AS `Id`,
       CASE
           WHEN tree.id = (SELECT atree.id FROM tree atree WHERE atree.p_id IS NULL)
               THEN 'Root'
           WHEN tree.id IN (SELECT atree.p_id FROM tree atree)
               THEN 'Inner'
           ELSE 'Leaf'
           END AS Type
FROM tree
ORDER BY `Id`
;