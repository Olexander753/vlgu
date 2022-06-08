use lr2
-----------------------------------------------------------
--пункт №3, 4
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
--пункт №7
-----------------------------------------------------------

begin tran
update Car set Model = 'A4' where Number = 'ПР455Ц'
update Mecanics set Salary = 21000 where PN = 6

commit

-----------------------------------------------------------
--пункт №9
-----------------------------------------------------------

begin tran
update Car set Model = 'A4' where Number = 'ПР455Ц'
set transaction isolation level read uncommitted
update Mecanics set Salary = 21000 where PN = 6

commit