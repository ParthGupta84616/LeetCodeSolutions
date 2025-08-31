# Write your MySQL query statement below
SELECT firstName , lastName , city , state 
from address right join person 
on address.personId = person.personId; 