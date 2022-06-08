use lr1

-- выборка по числовому полю
dbcc dropcleanbuffers
declare @startTime dateTime,
		@endTime dateTime,
		@count int
select @count = count(*)from Mechanics

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
-------------------------------------------------------
dbcc dropcleanbuffers
declare @startTime dateTime,
		@endTime dateTime,
		@count int
select @count = count(*)from Mechanics

set @startTime=getdate()

declare @counter int
set @counter= 100

while(@counter>0)
begin
	select*from Mechanics where Working_hours = round(rand()*1500, 0)
	set @counter = @counter - 1
end
set @endTime=getdate()
print str(datediff(ms, @startTime, @endTime))+'ms'
-------------------------------------------------------



-------------------------------------------------------
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
-------------------------------------------------------



-------------------------------------------------------
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
-------------------------------------------------------