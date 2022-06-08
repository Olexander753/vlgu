use lr1

--создание некластерного индекса по числовому полю
create index index_PN on mechanics (PN)

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
	select*from Mechanics where PN = round(rand()* @count, 0)
	set @counter = @counter - 1
end
set @endTime=getdate()
print str(datediff(ms, @startTime, @endTime))+'ms'

--удаление индекса
drop index index_PN on Mechanics
-------------------------------------------------------
create index index_Working_hours on Mechanics (Working_hours)

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
	select*from Mechanics where Working_hours = round(rand()*2000, 0)
	set @counter = @counter - 1
end
set @endTime=getdate()
print str(datediff(ms, @startTime, @endTime))+'ms'

--удаление индекса
drop index index_Working_hours on Mechanics
-------------------------------------------------------


-------------------------------------------------------
--создание некластерного индекса по числовому полю флоат
create index index_Salary on Mechanics (Salary)

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
	-- выборка по числовому полю
	select*from Mechanics where Salary = round(rand()*10000, 0)
	set @counter = @counter - 1
end
set @endTime=getdate()
print str(datediff(ms, @startTime, @endTime))+'ms'

--удаление индекса
drop index index_Salary on Mechanics
-------------------------------------------------------


-------------------------------------------------------
--создание некластерного индекса по символьному полю
create index index_Full_name on Mechanics (Full_name)

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
-- выборка по символьному полю
	select*from Mechanics where Full_name = str(round(floor(rand()*(1000999999-1000000000)+1000000000), 0))
	set @counter = @counter - 1
end
set @endTime=getdate()
print str(datediff(ms, @startTime, @endTime))+'ms'

--удаление некластерного индекса 
drop index index_Full_name on Mechanics
-------------------------------------------------------