Select V.customer_id,count(V.customer_id) as count_no_trans from Visits as V 
left join Transactions as T on V.visit_id = T.visit_id
where T.visit_id is null 
group by V.customer_id;
