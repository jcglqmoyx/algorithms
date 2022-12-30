select a.symbol 'Metal', b.symbol 'Nonmetal'
from Elements a,
     Elements b
where a.type = 'Metal'
  and b.type = 'Nonmetal'