# Write your MySQL query statement below
select name as Customers from 
Orders right join Customers 
on Orders.customerId = customers.id
where customerId is NULL;
