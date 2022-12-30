select tmp.id1 P1, tmp.id2 P2, abs(tmp.xv2 - tmp.xv1) * abs(tmp.yv2 - tmp.yv1) AREA
from (select p1.id id1, p1.x_value xv1, p1.y_value yv1, p2.id id2, p2.x_value xv2, p2.y_value yv2
      from Points p1
               cross join Points p2
      where p1.x_value <> p2.x_value
        and p1.y_value <> p2.y_value) tmp
where tmp.id1 < tmp.id2
order by area desc, p1, p2