# Write your MySQL query statement below
select Sales.price,Sales.year,Product.product_name from Sales left join Product on Sales.product_id=Product.product_id;