create database ��3
use ��3
create table Clients(
	Full_name nvarchar(50) not null unique,
	Drivers_license_number int not null primary key,
	Clients_addsress nvarchar(50) not null,
	Client_phone bigint null,
	check (Client_phone LIKE '8%'));

create table Cars(
	Number nvarchar(50) not null primary key,
	Brand nvarchar(50) not null,
	Color nvarchar(50) not null default '׸����',
	Drivers_license_number int not null foreign key references Clients(Drivers_license_number),);

create table Repairs(
	Type_of_repair nvarchar(50) not null primary key,);

create table Cars_Reapairs(
	Number nvarchar(50) not null foreign key references Cars(Number),
	Type_of_repair nvarchar(50) not null foreign key references Repairs(Type_of_repair),);

create table Workshops(
	Workshops_address nvarchar(50) not null primary key,
	Workshops_phone bigint null,
	constraint phone_and_address check(Workshops_phone LIKE '8%' and Workshops_address LIKE '��������%'));

create table Mechanics(
	Full_name nvarchar(50) not null unique,
	Qualification nvarchar(50) not null,
	Workshops_address nvarchar(50) not null foreign key references Workshops(Workshops_address),
	Mechanics_phone bigint null,
	PN int not null primary key,
	check (Qualification = '�������' or Qualification = '�������' or Qualification = '�������' or Qualification = '��������'));

create table Repairs_Mechanics(
	Type_of_repair nvarchar(50) null foreign key references Repairs(Type_of_repair),
	PN int null foreign key references Mechanics(PN),);


select *
from Clients


insert into Clients values
	('������ ���� ��������', 3647, '�������� �������� 1', 89008007060),
	('������ ϸ�� ��������', 3676, '�������� �������� 2', 89007006050),
	('������ ���� ����������', 4154, '�������� �������� 3', 89006005040),
	('����� ������� ���������', 8895, '�������� �������� 4', 89005004030),
	('�������� ������ �����������', 6378, '�������� �������� 5', 89004003020),
	('������ ������ ����������', 3477, '�������� �������� 6', 89003002010),
	('�������� �������� ��������', 1154, '�������� �������� 7', 89002001000),
	('�������� �������� ����������', 2384, '�������� �������� 8', 89001009080),
	('�������� ��������� ���������', 2761, '�������� �������� 8', 89002001090),
	('������ ������� ������������', 8253, '�������� �������� 10', 89003007060);

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


	--������������
	insert into Clients values ('������ ���� ��������', 4757, '�������� 1', 88008007060);


	insert into Mechanics values('������ ������ ����������', '�������', '�������� ������ 11', 89003895257, 488);

	--check
	insert into Clients values ('������ ���� ��������', 4757, '�������� 1', 318008007060);


	insert into Mechanics values('������ ������� ����������', '�����', '�������� ������ 11', 89003895257, 488);

	--���������� check
	insert into Workshops values('������ ������ 11', 79018587479);

	-- �������� ������ �� ������������ ������
	select * from Clients
	delete from Clients
	where Drivers_license_number = 1154

	select * from Clients

	-- �������� ����� �� ���������� �������
	select * from Cars
	delete from Cars
	where Number = '� 244 � �'

	select * from Cars