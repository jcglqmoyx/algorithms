select round(sqrt(min(pow(a.x - b.x, 2) + pow(a.y - b.y, 2))), 2) as shortest
from point2d a
         inner join point2d b on (a.x <= b.x and a.y != b.y) or (a.x < b.x and a.y = b.y);