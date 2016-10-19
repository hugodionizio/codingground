/*
create table Alunos (
	Matricula int not null primary key,
	Nome varchar);

create table Disciplina (
	Codigo int not null primary key,
	Nome varchar);

*/

/*alter table Alunos alter column Nome type varchar (30);
alter table Disciplina alter column Nome type varchar (30);
*/

/*create table matricula_alunos (
	mat_A int references Alunos (matricula),
	cod_D int references Disciplina (codigo),
	Data_mat Date);*/

/*
create table matricula_alunos2 (
	mat_A int references Alunos (matricula),
	cod_D int references Disciplina (codigo),
	Data_mat Date,
	Primary key(mat_A, cod_D));*/

/*
alter table Alunos rename to Aluno;
insert into Aluno values (1, 'Adriana');
insert into Aluno values (2, 'Alex');
insert into Aluno values (3, 'Marcos');
insert into Aluno values (4, 'Pedro');
*/

/*
insert into Aluno (matricula, nome)
values
	(5, 'Sergio'),
	(6, 'Mário'),
	(7, 'Danilo');
*/

/*
insert into Aluno (matricula)
values (8);
*/

/*
insert into Disciplina values (40, 'POO');
insert into Disciplina values (50, 'BD');
insert into Disciplina values (60, 'PPI');
*/

/*
insert into Matricula_Alunos
	(Mat_A, Cod_D, Data_Mat)
values
	(1, 40, '02/03/2012'),
	(2, 50, '02/03/2012'),
	(2, 50, '02/03/2012');
*/

insert into Matricula_Alunos2
	(Mat_A, Cod_D, Data_Mat)
values
	(1, 40, '02/03/2012'),
	(2, 50, '02/03/2012'),
	(2, 60, '02/03/2012');