# Write your MySQL query statement belsele
select *,IF(x+y>z and y+z>x and z+x>y, "Yes", "No") as triangle from triangle;