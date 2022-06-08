create database lr1

use lr1

drop table Mechanics

create table Mechanics(
	Full_name char(10) not null,
	Salary float not null,
	PN int not null,
	Working_hours int not null);

declare @startTime datetime,
  @endTime datetime,
  @timeDiff int

set @startTime=getdate()
set @endTime= @startTime
set @timeDiff= 1000 * 60 * 5  --5min

declare @Full_name char(50),
		@Salary float,
		@PN int,
		@Working_hours int
set @PN = 0
while datediff(ms, @startTime, @endTime) < @timeDiff
begin
	set @PN = @PN + 1
	set @Full_name = str(round(floor(rand()*(1000999999-1000000000)+1000000000), 0))
	set @Salary = round(rand()*10000, 0)
	set @Working_hours =  round(rand()*2000, 0)
	insert into Mechanics(Full_name, Salary, PN, Working_hours)
	values (@Full_name, @Salary, @PN, @Working_hours)
		set @endTime = getdate()
end

print str(datediff(ms, @startTime, @endTime))+'ms'

select count(*)as'Количество строк'from Mechanics;

select*  from Mechanics
