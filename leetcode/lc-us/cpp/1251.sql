SELECT product_id,
       Round(SUM(sales) / SUM(units), 2) AS average_price
FROM (
         SELECT Prices.product_id              AS product_id,
                Prices.price * UnitsSold.units AS sales,
                UnitsSold.units                AS units
         FROM Prices
                  JOIN UnitsSold ON Prices.product_id = UnitsSold.product_id
         WHERE UnitsSold.purchase_date BETWEEN Prices.start_date AND Prices.end_date
     ) T
GROUP BY product_id