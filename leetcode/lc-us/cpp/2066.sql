select account_id, day, sum(if(type = 'deposit', 1, -1) * amount) over (partition by account_id order by day) balance
from Transactions
order by account_id, day