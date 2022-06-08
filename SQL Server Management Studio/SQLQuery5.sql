create database ��4
drop database ��4
use ��4

create table Clients(
	Full_name nvarchar(50) not null unique,
	Drivers_license_number int not null primary key,
	Clients_addsress nvarchar(50) not null,
	Client_phone bigint null,
	Archiving bit null,
	check (Client_phone LIKE '8%'));

create table Cars(
	Number nvarchar(50) not null primary key,
	Brand nvarchar(50) not null,
	Color nvarchar(50) not null default '׸����',
	FK_Drivers_license_number int not null foreign key references Clients(Drivers_license_number),);

create table Repairs(
	Type_of_repair nvarchar(50) not null primary key,);
 
create table Cars_Reapairs(
	FK_Number nvarchar(50) not null foreign key references Cars(Number),
	FK_Type_of_repair nvarchar(50) not null foreign key references Repairs(Type_of_repair),);

create table Workshops(
	Workshops_address nvarchar(50) not null primary key,
	Workshops_phone bigint null,
	constraint phone_and_address check(Workshops_phone LIKE '8%' and Workshops_address LIKE '��������%'));

create table Mechanics(
	Full_name nvarchar(50) not null unique,
	Qualification nvarchar(50) not null,
	FK_Workshops_address nvarchar(50) not null foreign key references Workshops(Workshops_address),
	Mechanics_phone bigint null,
	PN int not null primary key,
	check (Qualification = '�������' or Qualification = '�������' or Qualification = '�������' or Qualification = '��������'));

create table Repairs_Mechanics(
	FK_Type_of_repair nvarchar(50) null foreign key references Repairs(Type_of_repair),
	FK_PN int null foreign key references Mechanics(PN),);



create table LOG(
	Name_table nvarchar(50),
	Name_operation nvarchar(50),
	datetime_local datetime);

insert into Clients values
	('������ ���� ��������', 3647, '�������� �������� 1', 89008007060, null),
	('������ ϸ�� ��������', 3676, '�������� �������� 2', 89007006050, null),
	('������ ���� ����������', 4154, '�������� �������� 3', 89006005040, null),
	('����� ������� ���������', 8895, '�������� �������� 4', 89005004030, null),
	('�������� ������ �����������', 6378, '�������� �������� 5', 89004003020, null),
	('������ ������ ����������', 3477, '�������� �������� 6', 89003002010, null),
	('�������� �������� ��������', 1154, '�������� �������� 7', 89002001000, null),
	('�������� �������� ����������', 2384, '�������� �������� 8', 89001009080, null),
	('�������� ��������� ���������', 2761, '�������� �������� 8', 89002001090, null),
	('������ ������� ������������', 8253, '�������� �������� 10', 89003007060, null);

insert into Workshops values
	('�������� ������ 11', 89018587479),
	('�������� ������ 123', 89011266106),
	('�������� ������ 54', 89016698667),
	('�������� ������ 65', 89018205250),
	('�������� ������ 33', 89010884585),
	('�������� ������ 554', 89010232292),
	('�������� ������ 36', 89015172848),
	('�������� ������ 112', 89017829320),
	('�������� ������ 9', 89011996853),
	('�������� ������ 89', 89017709738);

insert into Mechanics values
	('������ ������ ����������', '�������', '�������� ������ 11', 89003895257, 476),
	('�������� ������ ����������', '�������', '�������� ������ 11 ', 89003486235 , 475),
	('������� ���� ����������', '�������', '�������� ������ 123 ', 89006816011, 474),
	('������� ����� ����������', '��������', '�������� ������ 54 ', 89001288791, 473),
	('������� ���� ���������', '�������', '�������� ������ 554 ', 89003954024, 472),
	('������� �������� �������������', '�������', '�������� ������ 36 ', 89006762190, 471),
	('������� ������� ����������', '��������', '�������� ������ 89 ', 89008248456, 469),
	('��������� ����� ���������', '��������', '�������� ������ 11 ', 89008545460, 468),
	('������ ������ ����������', '�������', '�������� ������ 65 ', 89005626879, 467),
	('������� ����� ����������', '�������', '�������� ������ 9 ', 89005586594, 466);

insert into Cars values 
	('� 113 � �', 'Lada', '׸����', 3647),
	('� 244 � �', 'BMW', '�����', 3676),
	('� 641 � �', 'Audi', '�������', 2384),
	('� 355 � �', 'Fiat', '�������', 4154),
	('� 711 � �', 'BMW', '�����', 8895),
	('� 752 � �', 'Lada', '����������', 3647),
	('� 514 � �', 'Honda', '�������', 2384),
	('� 142 � �', 'Audi', '�������', 3477),
	('� 247 � �', 'Lada', 'Ƹ����', 4154),
	('� 972 � �', 'Fiat', '�����', 3647);

insert into Repairs values
	('������ ���������'),
	('������ �������'),
	('������ �����'),
	('������ ��������'),
	('������ ��������'),
	('������ ������������'),
	('������ ������ ������'),
	('������ ��������'),
	('��������� ������ ������������'),
	('������ ���������');

insert into Cars_Reapairs values
	('� 113 � �', '������ ���������'),
	('� 113 � �', '��������� ������ ������������'),
	('� 514 � �', '������ ��������'),
	('� 247 � �', '������ ���������'),
	('� 355 � �', '������ ������������'),
	('� 142 � �', '������ ��������'),
	('� 641 � �', '������ ��������'),
	('� 752 � �', '��������� ������ ������������'),
	('� 641 � �', '������ �������'),
	('� 113 � �', '������ ���������');

insert into Repairs_Mechanics values
	('������ ���������', 476),
	('������ �������', 475),
	('������ �����', 476),
	('������ ��������', 466),
	('������ ��������', 473),
	('������ ������������', 468),
	('������ ������ ������', 472),
	('������ ��������', 468),
	('��������� ������ ������������', 473),
	('������ ���������', 471);


CREATE TRIGGER insert_ on Cars AFTER insert 
	as 
	begin insert into LOG Values('������� Cars', '���������e', GetDate()); 
	end

drop TRIGGER delete_
CREATE TRIGGER delete_ on Cars AFTER delete 
	as 
	begin insert into LOG Values('������� Cars', '��������', GetDate()); 
	end

CREATE TRIGGER update_ on Cars AFTER Update 
	as 
	begin insert into LOG Values('������� Cars', '���������', GetDate()); 
	end

CREATE TRIGGER Cascade_Delete on Mechanics instead of delete 
	as 
	begin 
	if (exists (select Repairs_Mechanics.FK_PN from Repairs_Mechanics
		where Repairs_Mechanics.FK_PN = (select PN from deleted))) 
			begin 
			delete from Repairs_Mechanics where FK_PN = (select PN from deleted) 
			delete from Mechanics where PN = (select PN from deleted) 
			insert into LOG Values('������� Mechanics','��������� ��������', Getdate());
			END  
	END

drop procedure Archiving_table
create procedure Archiving_table
@���_��_�����_������ int OUTPUT
	as 
	insert into Archiving_Clients(Full_name, Drivers_license_number, Clients_addsress, Client_phone) 
	select Full_name, Drivers_license_number, Clients_addsress, Client_phone 
	from Clients 
	where Archiving = 0
	select ���_��_�����_������ = count(*) from Clients where Archiving = 0
	group by Clients.Archiving
	update Clients set Archiving = 1 where Drivers_license_number is not NULL




	select * from LOG
	select * from Cars 
	select * from Cars_Reapairs
	select * from Repairs_Mechanics
	select * from Mechanics

	insert into Cars values ('� 623 � �', 'BMW', '�������', 3676); --����������
	Update Clients Set Archiving = 0 Where Archiving =1;      --���������
	delete from Cars where Number = '� 244 � �';                    --�������� 
	delete from Mechanics where PN = 476;                    --��������� ��������

	--����� �������� ��������� ��������� �������
	declare @x int
	exec Archiving_table @x OUTPUT
	print @x
	select* from Archiving_Clients
	select* from Clients


	drop table Archiving_Clients

	create table Archiving_Clients(
	Full_name nvarchar(50) not null unique,
	Drivers_license_number int not null primary key,
	Clients_addsress nvarchar(50) not null,
	Client_phone bigint null);