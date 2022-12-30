CREATE PROCEDURE PivotProducts()
BEGIN
    declare colCnt int default 0;
    declare cname_i varchar(50);
    declare colindex int default 0;

    set @sqlStr = 'select product_id ';

    set colCnt = (select count(distinct store)
                  from products);

    while colCnt > colindex
        do
            set cname_i = (select store
                           from products
                           group by store
                           order by store
                           limit colindex,1);

            set @sqlStr = concat(@sqlStr, ',max(if(store=''', cname_i, ''',price,null)) as ', cname_i);

            set colindex = colindex + 1;
        end while;

    set @sqlStr = concat(@sqlStr, ' from products group by product_id ');

    prepare dosql from @sqlStr;
    execute dosql;
END