-- Gera��o de Modelo f�sico
-- Sql ANSI 2003 - brModelo.



CREATE TABLE Pessoa (
Primeiro Nome Texto(1),
Sobrenome Texto(1),
RG Texto(1) PRIMARY KEY
)

CREATE TABLE Cliente (
C�digo Texto(1) PRIMARY KEY,
RG Texto(1),
FOREIGN KEY(RG) REFERENCES Pessoa (RG)
)

CREATE TABLE Funcion�rio (
Matr�cula Texto(1) PRIMARY KEY,
RG Texto(1),
FOREIGN KEY(RG) REFERENCES Pessoa (RG)
)

CREATE TABLE Fita (
C�digo Texto(1) PRIMARY KEY,
RG Texto(1),
FOREIGN KEY(RG) REFERENCES Pessoa (RG)
)

