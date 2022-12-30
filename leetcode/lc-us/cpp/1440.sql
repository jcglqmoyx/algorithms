select e.left_operand,
       e.operator,
       e.right_operand,
       case e.operator
           when '>' then if(v1.value > v2.value, 'true', 'false')
           when '<' then if(v1.value < v2.value, 'true', 'false')
           else if(v1.value = v2.value, 'true', 'false')
           end value

from Expressions e
         left join Variables v1
                   on v1.name = e.left_operand
         left join Variables v2 on v2.name = e.right_operand