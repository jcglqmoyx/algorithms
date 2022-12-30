SELECT Name
FROM (
         SELECT CandidateId AS id
         FROM Vote
         GROUP BY CandidateId
         ORDER BY COUNT(id) DESC
         limit 1
     ) AS Winner
         JOIN Candidate
              ON Winner.id = Candidate.id
