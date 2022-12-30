CREATE PROCEDURE UnpivotProducts()
BEGIN
    DECLARE store_name varchar(100) default '';
    DECLARE done INT;
    DECLARE product_cursor CURSOR FOR
        SELECT column_name
        FROM information_schema.columns
        WHERE table_name = 'Products'
          AND column_name <> 'product_id';
    DECLARE continue handler FOR SQLSTATE '02000' SET done = 1;

    SET @sql = '';

    OPEN product_cursor;
    REPEAT
        FETCH product_cursor INTO store_name;
        SET @sql = concat(@sql,
                          'select product_id, ''',
                          store_name,
                          ''' store,',
                          store_name,
                          ' price from Products where ',
                          store_name,
                          ' is not null union ');
    UNTIL done
        END REPEAT;
    CLOSE product_cursor;

    SET @sql = substring(@sql, 1, length(@sql) - 7);

    PREPARE stmt FROM @sql;
    EXECUTE stmt;
    DEALLOCATE PREPARE stmt;
END