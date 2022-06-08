-----------------------------------------------------------
--пункт №1
-----------------------------------------------------------
create database lr2

use lr2

drop table Mecanics

create table Mecanics 
(	Full_name nvarchar(256) not null,
	Salary int not null,
	PN int not null);

go

insert into Mecanics values ('Иванов Иван Иванович', 15000, 3)

select * from Mecanics

-----------------------------------------------------------
--пункт №2, 4
-----------------------------------------------------------
select * from Mecanics

begin tran
update Mecanics set Salary = 16000 where PN = 3

select * from Mecanics

commit

-----------------------------------------------------------
--пункт №5
-----------------------------------------------------------

create table Car
(	Number nvarchar(6) not null,
	Brand nvarchar(256) not null,
	Model nvarchar(256) not null);

go

delete from Mecanics
delete from Car
insert into Mecanics values ('Иванов Иван Иванович', 15000, 3)
insert into Mecanics values ('Петров Пётр Петрович', 20000, 6)

insert into Car values ('ЕК123У', 'BMW', 'X5M')
insert into Car values ('ПР455Ц', 'Audi', 'A5')

select * from Mecanics
select * from Car

-----------------------------------------------------------
--пункт №7
-----------------------------------------------------------

begin tran
update Mecanics set Salary = 16000 where PN = 3
update Car set Model = 'X6' where Number = 'ЕК123У'

commit

-----------------------------------------------------------
--пункт №8
-----------------------------------------------------------

begin tran
update Mecanics set Salary = 16000 where PN = 3
select * from Car

commit

-----------------------------------------------------------
--пункт №9
-----------------------------------------------------------

begin tran
update Mecanics set Salary = 16000 where PN = 3
set transaction isolation level read uncommitted
select * from Car

commit
