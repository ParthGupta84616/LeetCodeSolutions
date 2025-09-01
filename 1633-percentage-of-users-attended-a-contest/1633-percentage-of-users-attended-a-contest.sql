# Write your MySQL query statement below
select contest_id , 
Round(100*count(*)/
(
    select count(DISTINCT user_id) from users
),2) as percentage
from register 
group by contest_id
order by percentage desc , contest_id  asc;