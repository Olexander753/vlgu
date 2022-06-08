create database лр4
drop database лр4
use лр4

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
	Color nvarchar(50) not null default 'Чёрный',
	FK_Drivers_license_number int not null foreign key references Clients(Drivers_license_number),);

create table Repairs(
	Type_of_repair nvarchar(50) not null primary key,);
 
create table Cars_Reapairs(
	FK_Number nvarchar(50) not null foreign key references Cars(Number),
	FK_Type_of_repair nvarchar(50) not null foreign key references Repairs(Type_of_repair),);

create table Workshops(
	Workshops_address nvarchar(50) not null primary key,
	Workshops_phone bigint null,
	constraint phone_and_address check(Workshops_phone LIKE '8%' and Workshops_address LIKE 'Владимир%'));

create table Mechanics(
	Full_name nvarchar(50) not null unique,
	Qualification nvarchar(50) not null,
	FK_Workshops_address nvarchar(50) not null foreign key references Workshops(Workshops_address),
	Mechanics_phone bigint null,
	PN int not null primary key,
	check (Qualification = 'Слесарь' or Qualification = 'Сварщик' or Qualification = 'Плотник' or Qualification = 'Электрик'));

create table Repairs_Mechanics(
	FK_Type_of_repair nvarchar(50) null foreign key references Repairs(Type_of_repair),
	FK_PN int null foreign key references Mechanics(PN),);



create table LOG(
	Name_table nvarchar(50),
	Name_operation nvarchar(50),
	datetime_local datetime);

insert into Clients values
	('Иванов Иван Иванович', 3647, 'Владимир Горькова 1', 89008007060, null),
	('Петров Пётр Петрович', 3676, 'Владимир Горькова 2', 89007006050, null),
	('Зайцев Исак Арсеньевич', 4154, 'Владимир Горькова 3', 89006005040, null),
	('Зимин Тимофей Дамирович', 8895, 'Владимир Горькова 4', 89005004030, null),
	('Прохоров Овидий Григорьевич', 6378, 'Владимир Горькова 5', 89004003020, null),
	('Фролов Михаил Кириллович', 3477, 'Владимир Горькова 6', 89003002010, null),
	('Устинова Серафима Лукьевна', 1154, 'Владимир Горькова 7', 89002001000, null),
	('Кабанова Альберта Николаевна', 2384, 'Владимир Горькова 8', 89001009080, null),
	('Веселова Маргарита Натановна', 2761, 'Владимир Горькова 8', 89002001090, null),
	('Панова Эвелина Валентиновна', 8253, 'Владимир Горькова 10', 89003007060, null);

insert into Workshops values
	('Владимир Ленина 11', 89018587479),
	('Владимир Ленина 123', 89011266106),
	('Владимир Ленина 54', 89016698667),
	('Владимир Ленина 65', 89018205250),
	('Владимир Ленина 33', 89010884585),
	('Владимир Ленина 554', 89010232292),
	('Владимир Ленина 36', 89015172848),
	('Владимир Ленина 112', 89017829320),
	('Владимир Ленина 9', 89011996853),
	('Владимир Ленина 89', 89017709738);

insert into Mechanics values
	('Гурьев Платон Маскимович', 'Слесарь', 'Владимир Ленина 11', 89003895257, 476),
	('Белоусов Степан Дмитриевич', 'Сварщик', 'Владимир Ленина 11 ', 89003486235 , 475),
	('Архипов Ефим Степанович', 'Плотник', 'Владимир Ленина 123 ', 89006816011, 474),
	('Беляков Игорь Германович', 'Электрик', 'Владимир Ленина 54 ', 89001288791, 473),
	('Петухов Фрол Макарович', 'Сварщик', 'Владимир Ленина 554 ', 89003954024, 472),
	('Суворов Анатолий Владиславович', 'Слесарь', 'Владимир Ленина 36 ', 89006762190, 471),
	('Елисеев Климент Кириллович', 'Электрик', 'Владимир Ленина 89 ', 89008248456, 469),
	('Терентьев Артем Филатович', 'Электрик', 'Владимир Ленина 11 ', 89008545460, 468),
	('Волков Герман Геласьевич', 'Сварщик', 'Владимир Ленина 65 ', 89005626879, 467),
	('Куликов Захар Германович', 'Слесарь', 'Владимир Ленина 9 ', 89005586594, 466);

insert into Cars values 
	('У 113 М С', 'Lada', 'Чёрный', 3647),
	('Р 244 К Н', 'BMW', 'Синий', 3676),
	('О 641 Н Х', 'Audi', 'Красный', 2384),
	('К 355 О В', 'Fiat', 'Вишнёвый', 4154),
	('В 711 С Е', 'BMW', 'Серый', 8895),
	('В 752 А С', 'Lada', 'Коричневый', 3647),
	('Е 514 М У', 'Honda', 'Бежевый', 2384),
	('Е 142 Е У', 'Audi', 'Красный', 3477),
	('Р 247 С В', 'Lada', 'Жёлтый', 4154),
	('Е 972 У У', 'Fiat', 'Белый', 3647);

insert into Repairs values
	('Ремонт сцепления'),
	('Сварка порогов'),
	('Замена масла'),
	('Ремонт тормозов'),
	('Замена проводки'),
	('Замена аккамулятора'),
	('Сварка петель капота'),
	('Замена лампочек'),
	('Настройка нового оборудования'),
	('Ремонт двигателя');

insert into Cars_Reapairs values
	('У 113 М С', 'Ремонт сцепления'),
	('У 113 М С', 'Настройка нового оборудования'),
	('Е 514 М У', 'Замена лампочек'),
	('Р 247 С В', 'Ремонт двигателя'),
	('К 355 О В', 'Замена аккамулятора'),
	('Е 142 Е У', 'Замена проводки'),
	('О 641 Н Х', 'Ремонт тормозов'),
	('В 752 А С', 'Настройка нового оборудования'),
	('О 641 Н Х', 'Сварка порогов'),
	('У 113 М С', 'Ремонт двигателя');

insert into Repairs_Mechanics values
	('Ремонт сцепления', 476),
	('Сварка порогов', 475),
	('Замена масла', 476),
	('Ремонт тормозов', 466),
	('Замена проводки', 473),
	('Замена аккамулятора', 468),
	('Сварка петель капота', 472),
	('Замена лампочек', 468),
	('Настройка нового оборудования', 473),
	('Ремонт двигателя', 471);


CREATE TRIGGER insert_ on Cars AFTER insert 
	as 
	begin insert into LOG Values('Таблица Cars', 'Добавлениe', GetDate()); 
	end

drop TRIGGER delete_
CREATE TRIGGER delete_ on Cars AFTER delete 
	as 
	begin insert into LOG Values('Таблица Cars', 'Удаление', GetDate()); 
	end

CREATE TRIGGER update_ on Cars AFTER Update 
	as 
	begin insert into LOG Values('Таблица Cars', 'Изменение', GetDate()); 
	end

CREATE TRIGGER Cascade_Delete on Mechanics instead of delete 
	as 
	begin 
	if (exists (select Repairs_Mechanics.FK_PN from Repairs_Mechanics
		where Repairs_Mechanics.FK_PN = (select PN from deleted))) 
			begin 
			delete from Repairs_Mechanics where FK_PN = (select PN from deleted) 
			delete from Mechanics where PN = (select PN from deleted) 
			insert into LOG Values('Таблица Mechanics','Каскадное удаление', Getdate());
			END  
	END

drop procedure Archiving_table
create procedure Archiving_table
@Кол_во_архив_данных int OUTPUT
	as 
	insert into Archiving_Clients(Full_name, Drivers_license_number, Clients_addsress, Client_phone) 
	select Full_name, Drivers_license_number, Clients_addsress, Client_phone 
	from Clients 
	where Archiving = 0
	select Кол_во_архив_данных = count(*) from Clients where Archiving = 0
	group by Clients.Archiving
	update Clients set Archiving = 1 where Drivers_license_number is not NULL




	select * from LOG
	select * from Cars 
	select * from Cars_Reapairs
	select * from Repairs_Mechanics
	select * from Mechanics

	insert into Cars values ('Т 623 К Р', 'BMW', 'Вишнёвый', 3676); --добавление
	Update Clients Set Archiving = 0 Where Archiving =1;      --изменение
	delete from Cars where Number = 'Р 244 К Н';                    --удаление 
	delete from Mechanics where PN = 476;                    --каскадное удаление

	--вызов хранимой процедуры архивации таблицы
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