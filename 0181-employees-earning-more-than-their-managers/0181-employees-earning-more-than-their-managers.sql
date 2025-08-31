select e.name as Employee from employee e
right join employee m on e.managerId  = m.id 
where e.salary > m.salary;