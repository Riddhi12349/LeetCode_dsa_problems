# Write your MySQL query statement below

SELECT Customer_id , COUNT(Customer_id) AS count_no_trans
/*----------------------------*/
from Visits v LEFT JOIN Transactions t 
ON v.visit_id = t.visit_id
WHERE transaction_id is NULL

/*
after this join we have rows
v_id c_id
4      30
6      96
7      54
8      54
*/
/*---------------*/
GROUP BY Customer_id