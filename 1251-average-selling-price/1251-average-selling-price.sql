# Write your MySQL query statement below
select 
p.product_id ,round(
        ifnull(sum(us.units * p.price) / sum(us.units), 0),
        2
    ) 
 as average_price 
 from prices p
 left join unitssold us
 on us.product_id = p.product_id
 and purchase_date between start_date and end_date
 group by p.product_id;