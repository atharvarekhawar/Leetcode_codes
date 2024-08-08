# Write your MySQL query statement below
select Visits.customer_id, COUNT(Visits.visit_id) as count_no_trans
from Visits left join Transactions on Visits.visit_id = Transactions.visit_id
where Transactions.transaction_id is NULL
group by Visits.customer_id;