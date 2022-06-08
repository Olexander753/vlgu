create database lr4

use lr4

create table Repair(
	ID int NOT NULL,
	Title nvarchar(256) NOT NULL,
	Price float NOT NULL)

insert into Repair values (1, 'q', 1.1)
insert into Repair values (2, 'w', 1.2)
insert into Repair values (3, 'e', 1.3)
insert into Repair values (4, 'r', 1.4)
insert into Repair values (5, 't', 1.5)
insert into Repair values (6, 'y', 1.6)
insert into Repair values (7, 'u', 1.7)
insert into Repair values (8, 'i', 1.8)
insert into Repair values (9, 'o', 1.9)
insert into Repair values (10, 'p', 2.1)

select ID, Title, Price from Repair

CREATE LOGIN u1 with password ='u1', check_expiration = off, check_policy = off
create user u1 for login u1
GRANT SELECT ON Repair TO u1
