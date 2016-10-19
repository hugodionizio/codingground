-- Geração de Modelo físico
-- Sql ANSI 2003 - brModelo.



CREATE TABLE Pessoa (
Primeiro Nome Varchar(50),
Sobrenome Varchar(50),
RG int32 PRIMARY KEY
)

CREATE TABLE Cliente (
Código int32 PRIMARY KEY,
RG int32,
FOREIGN KEY(RG) REFERENCES Pessoa (RG)
)

CREATE TABLE Funcionário (
Matrícula int32 PRIMARY KEY,
RG int32,
FOREIGN KEY(RG) REFERENCES Pessoa (RG)
)

CREATE TABLE Fita (
Código int32 PRIMARY KEY,
RG int32,
FOREIGN KEY(RG) REFERENCES Pessoa (RG)
)

ALTER TABLE Cliente ADD FOREIGN KEY(RG) REFERENCES Pessoa (RG);
ALTER TABLE Funcionário ADD FOREIGN KEY(RG) REFERENCES Pessoa (RG);
