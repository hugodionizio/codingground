-- Gera��o de Modelo f�sico
-- Sql ANSI 2003 - brModelo.



CREATE TABLE Pessoa (
Primeiro Nome Varchar(50),
Sobrenome Varchar(50),
RG int32 PRIMARY KEY
)

CREATE TABLE Cliente (
C�digo int32 PRIMARY KEY,
RG int32,
FOREIGN KEY(RG) REFERENCES Pessoa (RG)
)

CREATE TABLE Funcion�rio (
Matr�cula int32 PRIMARY KEY,
RG int32,
FOREIGN KEY(RG) REFERENCES Pessoa (RG)
)

CREATE TABLE Fita (
C�digo int32 PRIMARY KEY,
RG int32,
FOREIGN KEY(RG) REFERENCES Pessoa (RG)
)

