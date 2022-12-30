select id,
       @temp := if(drink is null, @temp, drink) as drink
from CoffeeShop