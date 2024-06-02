SELECT Название, Длительность FROM Треки
WHERE Длительность = (SELECT MAX(Длительность) FROM Треки)
ORDER BY Название;

SELECT Название, Длительность FROM Треки
WHERE Длительность >= 3.5
ORDER BY Название;

SELECT Название, Год_выпуска FROM Сборник
WHERE Год_выпуска between 2018 and 2020
ORDER BY Название;

SELECT Имя FROM Исполнители
WHERE Имя Not Like '% %';

insert into Треки (id_альбома, Название, Длительность) 
values
(3, 'Ты не мой',2.5),
(1, 'My love',2.5)
;

SELECT Название 
FROM Треки
WHERE Название Like '%my%' 
or Название like 'My%' 
or Название like '%мой' 
or Название like 'Мой%'
ORDER BY Название;
-----------------------------------------------
--Количество исполнителей в каждом жанре.
SELECT id_жанра, COUNT(id_исполнителя) FROM жанр_исполнитель
GROUP BY id_жанра
ORDER BY COUNT(id_исполнителя) DESC; 


--Количество треков, вошедших в альбомы 2019–2020 годов
SELECT Треки.Название, COUNT(Треки.Название) FROM Альбомы
LEFT JOIN Треки ON Альбомы.id = Треки.id_альбома 
WHERE Альбомы.Год_выпуска between 2019 and 2020
GROUP BY Треки.Название;

--Средняя продолжительность треков по каждому альбому
SELECT Альбомы.Название, AVG( Треки.Длительность) FROM Альбомы
LEFT JOIN Треки ON Альбомы.id = Треки.id_альбома 
GROUP BY Альбомы.Название
ORDER BY AVG(Длительность) DESC;

--Все исполнители, которые не выпустили альбомы в 2020 году
select  альбом_исполнитель.id_исполнителя FROM Альбомы
LEFT JOIN альбом_исполнитель ON альбом_исполнитель.id_альбома = Альбомы.id
WHERE Альбомы.Год_выпуска != 2020
GROUP BY альбом_исполнитель.id_исполнителя
ORDER BY альбом_исполнитель.id_исполнителя 
;

--Названия сборников, в которых присутствует конкретный исполнитель (выберите его сами)
SELECT Сборник.Название FROM Сборник 
JOIN треки_сборники on Сборник.id = треки_сборники.id_сборника
JOIN Треки ON треки_сборники.id_трека = Треки.id
JOIN Альбомы ON Треки.id_альбома = Альбомы.id
JOIN альбом_исполнитель ON альбом_исполнитель.id_альбома = Альбомы.id
JOIN Исполнители ON Исполнители.id = альбом_исполнитель.id_исполнителя
WHERE Исполнители.Имя = 'Баста'
GROUP BY Сборник.Название
;

