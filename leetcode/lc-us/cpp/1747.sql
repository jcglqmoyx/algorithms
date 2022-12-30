SELECT DISTINCT a.account_id
FROM LogInfo a
         INNER JOIN LogInfo b ON a.account_id = b.account_id AND a.ip_address <> b.ip_address AND
                                 ((a.login between b.login and b.logout) OR (a.logout between b.login and b.logout))