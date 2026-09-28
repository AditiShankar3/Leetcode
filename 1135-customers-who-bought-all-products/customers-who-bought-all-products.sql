# Write your MySQL query statement below
with prod_count as(
    select count(distinct product_key) as products from Product
)
select c.customer_id from Customer c cross join prod_count p group by c.customer_id,p.products having count(distinct c.product_key)=p.products; 