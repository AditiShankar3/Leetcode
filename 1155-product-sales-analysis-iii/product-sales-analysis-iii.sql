# Write your MySQL query statement below
with ranked_rows as (
    select product_id,year,quantity,price,
    rank() over (partition by product_id order by year asc) as rn from Sales
)
select product_id,year as first_year,quantity,price from ranked_rows where rn=1;