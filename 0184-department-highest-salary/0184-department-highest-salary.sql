# Write your MySQL query statement below
select d.name as Department ,
e.name as Employee, 
e.salary as salary from 
department d right join employee e
on e.departmentId = d.id
where 
(e.salary , e.departmentId) in
(
    select max(e.salary) , e.departmentId  from employee e
    group by e.departmentId 
)


