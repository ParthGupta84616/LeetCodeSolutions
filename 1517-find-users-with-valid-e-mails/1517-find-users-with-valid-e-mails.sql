# Write your MySQL query statement below
select * from users 
where mail 
regexp 
'^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode[.]{1}com$' collate utf8mb4_bin