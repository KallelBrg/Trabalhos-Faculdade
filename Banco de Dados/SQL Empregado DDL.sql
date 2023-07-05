CREATE TABLE Empregado(
	nome TEXT NULL,
	cpf INT PRIMARY KEY NOT NULL,
	data_nasc DATE NULL,
	sexo CHAR(1) NULL,
	salario DECIMAL(10,2) NULL,
	cpf_supervisor INT NULL,
	dept INT NULL,
	CHECK (sexo in ('m','f'))
	);


CREATE TABLE Departamento(
	nome TEXT NULL,
	numero INT PRIMARY KEY NOT NULL,
	cpf_gerente INT NULL,
	data_inicio_gerencia DATE NULL
	);

CREATE TABLE Projeto(
	nome TEXT NULL,
	numero INT PRIMARY KEY NOT NULL,
	dept INT NULL
	);

CREATE TABLE Trabalha_Para(
	empregado INT NOT NULL,
	projeto INT NOT NULL,
	horas INT NULL,
	primary key(empregado,projeto),
	foreign key(empregado) REFERENCES Empregado(cpf),
	foreign key(projeto) REFERENCES Projeto(numero)
	);

CREATE TABLE Gerenciou(
	cpf_ger INT NOT NULL,
	num_dept INT NOT NULL,
	primary key(cpf_ger,num_dept),
	foreign key(cpf_ger) REFERENCES Empregado(cpf),
	foreign key(num_dept) REFERENCES Departamento(numero)
	);


VALORES EMPREGADO

INSERT INTO Empregado VALUES(
	'Arnaldo Silva',
	123456,
	'1928-02-21',
	'm',
	4000,
	333333,
	5
	);

INSERT INTO Empregado VALUES(
	'Bruna Souza',
	654321,
	'1956-02-19',
	'f',
	2000,
	123456,
	5
	);

INSERT INTO Empregado VALUES(
	'Carlos Pedrosa',
	333333,
	'1065-01-08',
	'm',
	1000,
	null,
	5
	);

INSERT INTO Empregado VALUES(
	'Dulce Franco',
	123123,
	'1969-04-02',
	'f',
	1500,
	555555,
	2
	);

INSERT INTO Empregado VALUES(
	'Eduardo Dias',
	555555,
	'1955-05-06',
	'm',
	2500,
	null,
	2
	);

INSERT INTO Empregado VALUES(
	'Fernanda Cabral',
	444444,
	'1966-07-17',
	'f',
	3500,
	null,
	1
	);


VALORES DEPARTAMENTO

INSERT INTO Departamento VALUES(
	'Pesquisa',
	5,
	333333,
	'1985-06-22'
	);

INSERT INTO Departamento VALUES(
	'Administração ',
	2,
	555555,
	'1989-08-04'
	);

INSERT INTO Departamento VALUES(
	'Ensino',
	1,
	444444,
	'1992-09-29'
	);


VALORES PROJETO 

INSERT INTO Projeto VALUES(
	'P1',
	1,
	5
	);

INSERT INTO Projeto VALUES(
	'P2',
	2,
	5
	);

INSERT INTO Projeto VALUES(
	'P1',
	3,
	1
	);

INSERT INTO Projeto VALUES(
	'P1',
	4,
	2
	);

INSERT INTO Projeto VALUES(
	'P3',
	5,
	5
	);

INSERT INTO Projeto VALUES(
	'P2',
	6,
	2
	);





VALORES GERENCIOU

INSERT INTO Gerenciou VALUES(
	444444,
	1
	);


INSERT INTO Gerenciou VALUES(
	444444,
	2
	);

INSERT INTO Gerenciou VALUES(
	444444,
	5
	);

INSERT INTO Gerenciou VALUES(
	333333,
	5
	);

INSERT INTO Gerenciou VALUES(
	555555,
	2
	);


INSERT INTO Gerenciou VALUES(
	444444,
	5
	);


VALORES TRABALHA_PARA

INSERT INTO Trabalha_Para VALUES(
	123456,
	1,
	12
	);

INSERT INTO Trabalha_Para VALUES(
	123456,
	2,
	6
	);

INSERT INTO Trabalha_Para VALUES(
	123456,
	5,
	8
	);

INSERT INTO Trabalha_Para VALUES(
	654321,
	2,
	20
	);

INSERT INTO Trabalha_Para VALUES(
	333333,
	1,
	40
	);

INSERT INTO Trabalha_Para VALUES(
	123123 ,
	4,
	20
	);

INSERT INTO Trabalha_Para VALUES(
	123123 ,
	6,
	20
	);

INSERT INTO Trabalha_Para VALUES(
	555555 ,
	4,
	10
	);

INSERT INTO Trabalha_Para VALUES(
	444444 ,
	3,
	40
	);



