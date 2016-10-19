/*
create table empregado (
	matricula int NOT NULL,
	nome VARCHAR(10),
	Dataentrada DATE,
	salario numeric (7,2),
	num_depto int DEFAULT 0
);
*/

-- insert into empregado (matricula, nome, Dataentrada, salario, num_depto)
 -- values (001, 'Jose', '01-01-2001', 2000, 15), (002, 'Maria', '01-01-2001', 5000, 20);

-- insert into empregado (matricula, nome, Dataentrada, salario)
 -- values (003, 'Joana', '01-01-2001', 2000), (004, 'Joao', '01-01-2001', 2000);

--alter table empregado insert Matricula 001;insert into empregado (matricula, nome, Dataentrada, salario)

--alter table empregado alter column num_depto set default 1;

--insert into empregado (matricula, nome, Dataentrada, salario)
--values (005, 'Antonio', '01-01-2001', 2000), (006, 'Inacio', '01-01-2001', 5000);

/*
create table empregado2 (
	matricula int NOT NULL,
	nome VARCHAR(10),
	Dataentrada DATE,
	salario numeric (7,2) CHECK (salario >= 724.00),
	num_depto int DEFAULT 0
);
*/

--insert into empregado2 (matricula, nome, Dataentrada, salario, num_depto)
--values (001, 'Jose', '01-01-2001', 2000, 15), (002, 'Maria', '01-01-2001', 5000, 20);

--insert into empregado2 (matricula, nome, Dataentrada, salario)
--values (003, 'Joana', '01-01-2001', 800);

--insert into empregado2 (matricula, nome, Dataentrada, salario)
--values (004, 'Joao', '01-01-2001', 400); -- ERRO: novo registro da relação "empregado2" viola restrição de verificação "empregado2_salario_check"

--alter table empregado2 column num_depto 

--alter table empregado2 add check (salario >= 800);

--insert into empregado2 (matricula, nome, Dataentrada, salario)
--values (004, 'Joao', '01-01-2001', 800);

/*
create table produtos (
	Numero int not null,
	nome text,
	preco numeric CHECK (preco > 0),
	desconto numeric CHECK (desconto > 0),
	CHECK (preco > desconto)
);
*/

--insert into produtos (numero, preco, desconto) values (001, 20,8);
--insert into produtos (numero, preco, desconto) values (002, 20,32);

--update empregado2 set nome = 'Jose Mario' where nome = 'Jose';
--update empregado2 set nome = 'Maria Ana' where nome = 'Maria';
--update empregado2 set Salario = 10000 where nome = 'Maria Ana';
--update empregado2 set Salario = 50000 where nome = 'Jose Mario';
update empregado2 set Salario = 1000 where num_depto = 1;
