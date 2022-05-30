--1
SELECT COUNT(*) AS "No. of Emp", AVG(SALARY) AS "Avg Salary", 
DEPARTMENT_ID FROM HR.EMPLOYEES 
GROUP BY DEPARTMENT_ID;

--2
SELECT COUNT(*) AS "Total", JOB_ID FROM HR.EMPLOYEES GROUP BY JOB_ID

--3
SELECT FIRST_NAME,HIRE_DATE FROM HR.EMPLOYEES WHERE
HIRE_DATE > (SELECT HIRE_DATE FROM HR.EMPLOYEES WHERE EMPLOYEE_ID=110)

--4
SELECT EMPLOYEE_ID, FIRST_NAME, LAST_NAME, JOB_ID FROM HR.EMPLOYEES
WHERE SALARY < ANY(SELECT SALARY FROM HR.EMPLOYEES WHERE JOB_ID='IT_PROG')

--5
SELECT DEPARTMENT_ID, COUNT(*) AS "Employees" FROM HR.EMPLOYEES WHERE 
SALARY > 2000 GROUP BY DEPARTMENT_ID HAVING COUNT(*) > 5