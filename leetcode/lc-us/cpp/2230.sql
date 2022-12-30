CREATE PROCEDURE getUserIDs(startDate DATE, endDate DATE, minAmount INT)
BEGIN
    select distinct user_id
    from Purchases
    where amount >= minAmount
      and time_stamp between startDate and endDate
    order by user_id;
END