select ym                                                       as 'month',
       country,
       sum(case when state = 'approved' then 1 else 0 end)      as approved_count,
       sum(case when state = 'approved' then amount else 0 end) as approved_amount,
       sum(case when state = 'charge' then 1 else 0 end)        as chargeback_count,
       sum(case when state = 'charge' then amount else 0 end)   as chargeback_amount
from (
         select id, country, state, amount, trans_date, date_format(trans_date, '%Y-%m') as ym
         from (
                  select *
                  from transactions
                  union all
                  (select chargebacks.trans_id   as id,
                          transactions.country   as country,
                          'charge'               as state,
                          transactions.amount    as amount,
                          chargebacks.trans_date as trans_date
                   from chargebacks
                            left join transactions
                                      on transactions.id = chargebacks.trans_id)) tmp1) tmp2
group by ym, country
having sum(case when state = 'approved' or state = 'charge' then amount else 0 end) > 0