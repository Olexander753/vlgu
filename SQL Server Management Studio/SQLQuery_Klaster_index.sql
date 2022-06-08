use lr1

--создание кластерного индекса числового поля 
ALTER TABLE Mechanics ADD CONSTRAINT
	PK_PN PRIMARY KEY CLUSTERED (PN)

-- выборка по числовому полю
dbcc dropcleanbuffers
declare @startTime dateTime,
		@endTime dateTime,
		@count int
select @count =count(*)from Mechanics

set @startTime=getdate()

declare @counter int
set @counter= 100

while(@counter>0)
begin
	-- выборка по числовому полю
	select*from Mechanics where PN = round(rand()* @count, 0)
	set @counter = @counter - 1
end
set @endTime=getdate()
print str(datediff(ms, @startTime, @endTime))+'ms'

--удаление индекса
alter table Mechanics drop constraint PK_PN
-------------------------------------------------------
CREATE CLUSTERED index index_Working_hours_ ON Mechanics(Working_hours)

-- выборка по числовому полю флоат
dbcc dropcleanbuffers
declare @startTime dateTime,
		@endTime dateTime,
		@count int
select @count =count(*)from Mechanics

set @startTime=getdate()

declare @counter int
set @counter= 100

while(@counter>0)
begin
	select*from Mechanics where Working_hours = round(rand()*2000, 0)
	set @counter = @counter - 1
end
set @endTime=getdate()
print str(datediff(ms, @startTime, @endTime))+'ms'

-- удаление индекса
DROP index index_Working_hours_ ON Mechanics
-------------------------------------------------------


-------------------------------------------------------
--создание кластерного индекса числового поля флоат
CREATE CLUSTERED index index_Salary_ ON Mechanics(Salary)

-- выборка по числовому полю флоат
dbcc dropcleanbuffers
declare @startTime dateTime,
		@endTime dateTime,
		@count int
select @count =count(*)from Mechanics

set @startTime=getdate()

declare @counter int
set @counter= 100

while(@counter>0)
begin
	select*from Mechanics where Salary = round(rand()*10000, 0)
	set @counter = @counter - 1
end
set @endTime=getdate()
print str(datediff(ms, @startTime, @endTime))+'ms'

-- удаление индекса
DROP index index_Salary_ ON Mechanics
-------------------------------------------------------


-------------------------------------------------------
--по символьному полю
CREATE CLUSTERED index index_Full_name_ ON Mechanics(Full_name)

-- выборка по символьному полю
dbcc dropcleanbuffers
declare @startTime dateTime,
		@endTime dateTime,
		@count int
select @count =count(*)from Mechanics

set @startTime=getdate()

declare @counter int
set @counter= 100

while(@counter>0)
begin
	select*from Mechanics where Full_name = str(round(floor(rand()*(1000999999-1000000000)+1000000000), 0))
	set @counter = @counter - 1
end
set @endTime=getdate()
print str(datediff(ms, @startTime, @endTime))+'ms'

-- удаление индекса
DROP index index_Full_name_ ON Mechanics
-------------------------------------------------------