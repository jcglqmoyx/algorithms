with recursive t(n) as (
    select 0
    union all
    select n + 1
    from t
    where n < (select max(datediff(period_end, period_start)) from Sales)
)
select s.product_id,
       p.product_name,
       DATE_FORMAT(DATE_ADD(s.period_start, INTERVAL t.n DAY), '%Y') as report_year,
       sum(s.average_daily_sales)                                    as total_amount
from Sales s
         join t on datediff(s.period_end, s.period_start) >= t.n
         join Product p on s.product_id = p.product_id
group by 1, 2, 3
order by 1, 3
