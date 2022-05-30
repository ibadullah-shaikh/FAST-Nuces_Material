--1
SELECT E.EMPLOYEE_ID, E.FIRST_NAME, D.DEPARTMENT_NAME FROM HR.EMPLOYEES E
JOIN HR.DEPARTMENTS D ON E.DEPARTMENT_ID = D.DEPARTMENT_ID;

--2
SELECT E.EMPLOYEE_ID, E.LAST_NAME, D.JOB_TITLE FROM HR.EMPLOYEES E
JOIN HR.JOBS D ON E.JOB_ID = D.JOB_ID;

--3
SELECT D.DEPARTMENT_NAME,COUNT(E.EMPLOYEE_ID) FROM HR.EMPLOYEES E JOIN HR.DEPARTMENTS D
ON E.DEPARTMENT_ID = D.DEPARTMENT_ID GROUP BY D.DEPARTMENT_NAME;

--4
SELECT D.DEPARTMENT_NAME FROM HR.EMPLOYEES E JOIN HR.DEPARTMENTS D ON E.DEPARTMENT_ID = D.DEPARTMENT_ID
HAVING COUNT(E.EMPLOYEE_ID) >= 2 GROUP BY D.DEPARTMENT_NAME;

--5
SELECT COUNT(E.EMPLOYEE_ID)FROM HR.EMPLOYEES E JOIN HR.JOBS D ON E.JOB_ID = D.JOB_ID GROUP BY D.JOB_TITLE;

--6
SELECT M.MANAGER_ID,COUNT(M.MANAGER_ID) FROM HR.EMPLOYEES M,HR.EMPLOYEES E WHERE M.MANAGER_ID = E.EMPLOYEE_ID
GROUP BY M.MANAGER_ID ORDER BY M.MANAGER_ID ASC;

--7
SELECT * FROM HR.EMPLOYEES RIGHT JOIN HR.DEPARTMENTS ON EMPLOYEES.DEPARTMENT_ID=DEPARTMENTS.DEPARTMENT_ID;

--8
SELECT * FROM HR.EMPLOYEES JOIN HR.DEPARTMENTS
ON EMPLOYEES.DEPARTMENT_ID=DEPARTMENTS.DEPARTMENT_ID WHERE DEPARTMENT_NAME='Marketing' OR DEPARTMENT_NAME='Executive';

--9


--10
SELECT DISTINCT E.JOB_TITLE FROM HR.JOBS E JOIN HR.EMPLOYEES D ON E.JOB_ID = D.JOB_ID 
JOIN HR.DEPARTMENTS A ON D.DEPARTMENT_ID = A.DEPARTMENT_ID AND (A.DEPARTMENT_NAME NOT IN ('Marketing','Executive'));