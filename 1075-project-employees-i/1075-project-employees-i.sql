# Write your MySQL query statement below
select p.project_id,AVG(e.experience_years) AS average_years  from
employee e right join project p on
e.employee_id  = p.employee_id
group by p.project_id