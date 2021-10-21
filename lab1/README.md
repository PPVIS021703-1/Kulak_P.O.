# Теория матриц

Описать класс, реализующий тип данных "Вещественная матрица".<br/> 
Класс должен реализовывать следующие возможности:

- матрица произвольного размера с динамическим выделением памяти;
- пре- и постинкремент ( ++ ), пре- и постдекремент ( -- );

## Вещественная матрица
 
Класс должен реализовывать следующие дополнительные возможности:

- изменение числа строк и числа столбцов;
- загрузка матрицы из файла;
- извлечение подматрицы заданного размера;
- проверка типа матрицы (квадратная, диагональная, нулевая, единичная, симметрическая,<br/> 
верхняя треугольная, нижняя треугольная);
- транспонированние матрицы;

Использование библиотеки для unit-тестов [doctest.h](https://github.com/onqtam/doctest/releases)<br/> 
Файл ppvis.bak документация к самому коду