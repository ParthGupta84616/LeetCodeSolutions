# Write your MySQL query statement below
select w1.id from weather w2 right join weather w1 on
DATEDIFF(w1.recordDate , w2.recordDate) = 1
where w1.temperature > w2.temperature;