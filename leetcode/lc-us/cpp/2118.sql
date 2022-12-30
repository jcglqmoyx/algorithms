select concat(
               group_concat(concat(factor, po) order by power desc separator '')
           , '=0'
           ) equation
from (
         select '1'                                                        flag
              , if(power = 0, '', if(power = 1, 'X', concat('X^', power))) po
              , if(factor > 0, concat('+', factor), factor)                factor
              , power
         from Terms
     ) t
group by flag