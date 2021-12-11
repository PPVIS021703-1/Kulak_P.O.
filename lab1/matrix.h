#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

/*!
    \author Кулак П.О.
	\brief Основной класс
	\date Сентябрь 2021 года
	\warning Данный класс создан только в учебных целях

	Обычный дочерний класс, который создаёт матрицу
*/
class MATRIX
{
private:
  float ** M; /* ... матрица ... */
  int m; /* ... количество строк ... */
  int n; /* ... количество столбцов ... */
public:
  MATRIX(); /* ... конструктор... */
  MATRIX(int, int); /* ... конструктор с двумя параметрами ... */
  MATRIX(const  MATRIX& );
  float GetMij(int, int); /* ... метод доступа ... */
  void SetMij(int, int, float); /* ... метод получение данных с матриц ... */
  void Print(const char* ); /* ... метод, выводящий матрицу ... */
  MATRIX operator=(const MATRIX&); /* ... оператор копирования - обязательный ... */
  void rowscols(int,int, int&,int&); /* ... метод изменение строк и столбцов в матрице ... */
  ~MATRIX();/*
   * ... Деструктор - освобождает память, выделенную для матрицы ...
   */
  float get_Matrix();
  int get_m();/* ... метод получение строк ... */
  int get_n(); /* ... метод получение столбцов  ... */
  void set_Matrix(float**, int, int);
  void set_m(int);
  void set_n(int);
  void menu();
  void Transpose();/* ... метод транспорнирования матрицы ... */
  MATRIX submatrix( MATRIX&, int, int,  int,  int); /* ... метод нахождения подматрицы ... */
  MATRIX whyMatrix();/* ... метод нахождения типа матрицы ... */
  bool diagonal();/* ... метод нахождения диагональной матрицы ... */
  bool square(); /* ... метод нахождения квадратичной матрицы ... */
  bool nullmatrix(); /* ... метод нахождения нулевой матрицы ... */
  bool unitmatrix(); /* ... метод нахождения единичной матрицы ... */
  bool simmetric(); /* ... метод нахождения симметрической матрицы ... */
  bool downtringle(); /* ... метод нахождения нижнетреугольной матрицы ... */
  bool uptringle(); /* ... метод нахождения верхнетреугольной матрицы ... */
  friend std::ostream& operator << (std::ostream &, const MATRIX &);
  friend std::istream& operator >> (std::istream &, MATRIX &);
  friend ifstream& operator >> (ifstream& , MATRIX& );
  friend ofstream& operator << (ofstream& , const MATRIX& );
  MATRIX& operator ++();
    /**
        * ... Перегрузка  предекримента оператора ++ ...
        */
  MATRIX& operator -- ();
    /**
        * ... Перегрузка  предекримента оператора -- ...
        */
  MATRIX operator ++ (int);
    /**
        * ... Перегрузка  постинкримента оператора ++ ...
        */
  MATRIX operator -- (int);
    /**
      * ... Перегрузка  постдекримента оператора -- ...
      */
  bool operator == (const MATRIX& m);/**
    * ... Перегрузка  бинарного оператора == ...
    */
  bool operator != (const MATRIX&);

};
#endif


