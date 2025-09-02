# Write your MySQL query statement below
select u.name , sum(t.amount) as balance 
from
users u right join Transactions t
on 
t.account = u.account
group by u.account 
having 
sum(t.amount) > 10000
