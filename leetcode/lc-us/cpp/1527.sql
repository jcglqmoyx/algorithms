SELECT patient_id AS 'patient_id', patient_name AS 'patient_name', conditions AS 'conditions'
FROM Patients
WHERE conditions LIKE 'DIAB1%'
   OR conditions LIKE '% DIAB1%'