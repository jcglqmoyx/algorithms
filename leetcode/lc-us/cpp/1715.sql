SELECT SUM(`apple_count`) AS 'apple_count', SUM(`orange_count`) AS 'orange_count'
FROM ((SELECT `box_id`, `apple_count`, `orange_count` FROM `boxes`)
      UNION ALL
      (SELECT b.`box_id`, c.`apple_count`, c.`orange_count`
       FROM `boxes` AS b
                RIGHT JOIN `chests` AS c USING (`chest_id`)
       WHERE b.`box_id` IS NOT NULL)) AS a