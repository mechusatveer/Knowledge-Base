http://www.programmerinterview.com/index.php/database-sql/having-vs-where-clause/

In SQL, what’s the difference between the having clause and the where clause?

emp_bonus
Employee	Bonus
A	        1000
B	        2000
A	        500
C	        700
B	        1250

If we want to calculate the total bonus that each employee received,
then we would write a SQL statement like this:

select employee, sum(bonus) from emp_bonus group by employee;

Running the SQL above would return this:

Employee	Sum(Bonus)
A	        1500
B	        3250
C	        700

Now, suppose we wanted to find the employees who received more than $1,000 in
bonuses for the year of 2007. You might think that we could write a query like this:

BAD SQL:
select employee, sum(bonus) from emp_bonus 
group by employee where sum(bonus) > 1000;

The WHERE clause does not work with aggregates like SUM

The SQL above will not work, because the where clause doesn’t work with aggregates 
– like sum, avg, max, etc.. Instead, what we will need to use is the having clause.
The having clause was added to sql just so we could compare aggregates to other values
– just how the ‘where’ clause can be used with non-aggregates. 
Now, the correct sql will look like this:

GOOD SQL:
select employee, sum(bonus) from emp_bonus 
group by employee having sum(bonus) > 1000;

So we can see that the difference between the having and where clause in sql is that 
the where clause can not be used with aggregates, but the having clause can. One way 
to think of it is that the having clause is an additional filter to the where clause.




