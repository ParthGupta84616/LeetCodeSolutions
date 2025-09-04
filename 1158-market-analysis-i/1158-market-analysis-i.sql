# Write your MySQL query statement below
select u.user_id as buyer_id , u.join_date, (
    COUNT(o.order_id)
) as orders_in_2019 
from users u left join orders o 
on u.user_id = o.buyer_id
and Year(o.order_date) = 2019
group by u.user_id, u.join_date
