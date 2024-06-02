CREATE TABLE IF NOT EXISTS Жанр (
	id SERIAL PRIMARY KEY,
	Название VARCHAR(40) NOT NULL
);

CREATE TABLE IF NOT EXISTS Альбомы (
	id SERIAL PRIMARY KEY,
	Название VARCHAR(60) NOT NULL,
	Год_выпуска integer
);

CREATE TABLE IF NOT EXISTS Треки (
	id SERIAL PRIMARY KEY,
	id_альбома INTEGER REFERENCES Альбомы(id),
	Название VARCHAR(60) NOT NULL,
	Длительность numeric
);


CREATE TABLE IF NOT EXISTS Сборник (
	id SERIAL PRIMARY KEY,
	Название VARCHAR(60),
	Год_выпуска integer
);


CREATE TABLE IF NOT EXISTS Исполнители (
	id SERIAL PRIMARY KEY,
	Имя VARCHAR(60)
);




CREATE TABLE IF NOT EXISTS жанр_исполнитель (
	id serial primary key,
	id_жанра  integer references Жанр(id),
	id_исполнителя integer references Исполнители(id)
);

CREATE TABLE IF NOT EXISTS альбом_исполнитель (
	id serial PRIMARY KEY,
	id_исполнителя INTEGER REFERENCES Исполнители(id),
	id_альбома INTEGER REFERENCES Альбомы(id)
	
);
CREATE TABLE IF NOT EXISTS треки_альбомы (
	id serial PRIMARY KEY,
	id_сборника  INTEGER REFERENCES Сборник(id),
	id_трека  INTEGER REFERENCES Треки(id)
);
