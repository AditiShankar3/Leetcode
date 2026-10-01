# Write your MySQL query statement below
with count_dept as(
    select employee_id,department_id,primary_flag, count(*) over (partition by employee_id) as dept_count from Employee
)
select employee_id, department_id from count_dept where dept_count=1 or primary_flag='Y';