# Write your MySQL query statement below
select name , bonus 
from bonus right outer join employee 
on bonus.empId = employee.empId
where bonus < 1000 or bonus is null;