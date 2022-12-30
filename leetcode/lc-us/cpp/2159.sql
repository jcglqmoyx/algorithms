select a.first_col, b.second_col
from (select row_number() over (order by first_col) as id, first_col
      from Data) a
         join
     (select row_number() over (order by second_col desc) as id, second_col
      from Data) b on a.id = b.id
