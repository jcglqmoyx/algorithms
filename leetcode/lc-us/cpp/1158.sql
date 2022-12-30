SELECT Users.user_id          AS buyer_id,
       join_date,
       IFNULL(UserBuy.cnt, 0) AS orders_in_2019
FROM Users
         LEFT JOIN
     (SELECT buyer_id,
             count(order_id) cnt
      FROM Orders
      WHERE order_date
                BETWEEN '2019-01-01'
                AND '2019-12-31'
      GROUP BY buyer_id) UserBuy
     ON Users.user_id = UserBuy.buyer_id
