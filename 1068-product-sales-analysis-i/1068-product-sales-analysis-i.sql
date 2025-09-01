# Write your MySQL query statement below
select product_name , year , price from 
product right join sales 
on product.product_id = sales.product_id;