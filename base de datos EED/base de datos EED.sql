create database cutonala;
	create table Sede(idSede int(10) not null Auto_increment primary key,
		              NombreSede varchar(50) not null, Ubicacion varchar(150) not null);

	create table Licenciatura(idLicenciatura int(10) not null Auto_increment primary key,
		                      NombreLicenciatura varchar(50) not null, id_sede int(10) not null,
		                      FOREIGN KEY (id_sede) REFERENCES Sede(idSede));

	create table Grupo(idGrupo int(10) not null Auto_increment primary key, NombreGrupo varchar(5) not null,
		               Turno varchar(5) not null, Aula varchar(5) not null, id_Licenciatura int(10) not null,
		               FOREIGN KEY (id_Licenciatura) REFERENCES Licenciatura(idLicenciatura));

	create table Estudiante(idEstudiante int(10) not null Auto_increment primary key,
		                    Codigo int(10) not null, NombreEstudiante varchar(30) not null, 
		                    ApellidoPaterno varchar(20) not null, ApellidoMaterno varchar(20) not null,
		                    id_Grupo int(10) not null, id_Licenciatura int(10) not null,
		                    FOREIGN KEY (id_Grupo) REFERENCES Grupo(idGrupo),
		                    FOREIGN KEY (id_Licenciatura) REFERENCES Licenciatura (idLicenciatura));
insert into Sede(NombreSede, Ubicacion) 
	values('Casa de la Cultura','www.google.com'),('Casa de la Cultura II','www.google'), ('Sillitas', 'www.google.com'),
	      ('Santa Paula', 'www.google.com');
insert into Licenciatura(NombreLicenciatura, id_sede)
	values('Lic. Salud Publica', '2'), ('Lic. Medico, Cirujano y Partero', '2'), ('Ing. Nanotecnologia', '1'),
	      ('Ing. Energia', '1'), ('Ing. Ciencias Computacionales', '1'), ('Lic. Historia del Arte', '1'),
	      ('Lic. Gerontologia', '2'), ('Lic. Estudios Liberales', '2'), ('Lic. Diseño de Artesanias', '4'),
	      ('Lic. Contaduria Publica', '3'), ('Lic. Administracion de Negocios', '3'), ('Lic. Abogado', '3');
insert into Grupo(NombreGrupo, Aula, id_Licenciatura, Turno)
	values('1ero', '6', '5', 'Matutino'), ('1ero', '6', '5', 'Vespertino'), ('2do', '5', '5', 'Matutino'),
	      ('2do', '5', '5', 'Vespertino'), ('3ero', '4', '5', 'Vespertino'), ('3ero', '8', '5', 'Vespertino'),
	      ('4to', '8', '5', 'Matutino'), ('4to', '4', '5', 'Matutino');


insert into Estudiante(Codigo, NombreEstudiante, ApellidoPaterno, ApellidoMaterno, id_Grupo, id_Licenciatura)
	values('207630719', 'Joel Emmanuel', 'Valdivia', 'Ramirez', 7, 5);