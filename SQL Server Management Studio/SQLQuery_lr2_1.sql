use lr2
-----------------------------------------------------------
--����� �3, 4
-----------------------------------------------------------
set transaction isolation level read uncommitted
begin tran
select * from Mecanics

commit


set transaction isolation level read committed
begin tran
select * from Mecanics

commit


set transaction isolation level repeatable read
begin tran
select * from Mecanics

commit


set transaction isolation level serializable
begin tran
select * from Mecanics

commit

-----------------------------------------------------------
--����� �7
-----------------------------------------------------------

begin tran
update Car set Model = 'A4' where Number = '��455�'
update Mecanics set Salary = 21000 where PN = 6

commit

-----------------------------------------------------------
--����� �9
-----------------------------------------------------------

begin tran
update Car set Model = 'A4' where Number = '��455�'
set transaction isolation level read uncommitted
update Mecanics set Salary = 21000 where PN = 6

commit