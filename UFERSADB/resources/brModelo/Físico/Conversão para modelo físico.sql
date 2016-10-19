-- Geração de Modelo físico
-- Sql ANSI 2003 - brModelo.



CREATE TABLE Pessoa (
Primeiro Nome Texto(1),
Sobrenome Texto(1),
RG Texto(1) PRIMARY KEY
)

CREATE TABLE Cliente (
Código Texto(1) PRIMARY KEY,
RG Texto(1),
FOREIGN KEY(RG) REFERENCES Pessoa (RG)
)

CREATE TABLE Funcionário (
Matrícula Texto(1) PRIMARY KEY,
RG Texto(1),
FOREIGN KEY(RG) REFERENCES Pessoa (RG)
)

CREATE TABLE Fita (
Código Texto(1) PRIMARY KEY,
RG Texto(1),
FOREIGN KEY(RG) REFERENCES Pessoa (RG)
)

