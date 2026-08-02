# Write your MySQL query statement below
select p.firstName,p.lastName,A.city,A.state from Person p left join Address a on p.personId=a.personId;