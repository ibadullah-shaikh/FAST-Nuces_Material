--10
ALTER TABLE EMPLOYEES ADD CONSTRAINT CHECK (UPPER(FIRST_NAME)= FIRST_NAME);

--11
ALTER TABLE EMPLOYEES ADD UNIQUE (SALARY);

--12
ALTER TABLE EMPLOYEES MODIFY PHONE_NUMBER NOT NULL;

--13
INSERT INTO EMPLOYEES VALUES(1,'Ibad','Shaikh','IbadShaikh',3042991869,'21-APR-02',
'CS',200000,0.5,100,259);

--14
UPDATE EMPLOYEES SET SALARY=8000 WHERE EMPLOYEE_ID=105 AND SALARY<5000;

--15
UPDATE HR.EMPLOYEES SET JOB_ID= 'CS' where EMPLOYEE_ID = 118 AND DEPARTMENT_ID = 30 AND JOB_ID != 'SH%';

--16
ALTER TABLE EMPLOYEES ADD PRIMARY KEY (EMPLOYEE_ID, JOB_ID);