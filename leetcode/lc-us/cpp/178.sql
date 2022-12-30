SELECT Score,
       dense_rank() over (Order BY Score DESC ) AS 'Rank'
FROM Scores;
