#include "matrix.h"
#include <iostream>


using namespace std;

MATRIX::MATRIX()
{
    n = m = 0;
    M = nullptr;
}

MATRIX::MATRIX(int _m, int _n){
    m = _m;
    n = _n;

    // Выделить память для матрицы
    // Выделить память для массива указателей
    M = (float**) new float*[m]; // количество строк, количество указателей

    // Выделить память для каждого указателя
    for (int i = 0; i < m; i++)
        M[i] = (float*)new float[n];

    // заполнить массив M нулями
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = 0;
}
MATRIX::MATRIX(const  MATRIX& _M) {
    /*
     * ... Создается новый объект для которого виделяется память ...
     * ... Копирование данных *this <= _M ...
     */
    m = _M.m;
    n = _M.n;

    // Выделить память для M
    M = (float**) new float*[m]; // количество строк, количество указателей

    for (int i = 0; i < m; i++)
        M[i] = (float*) new float[n];

    // заполнить значениями
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = _M.M[i][j];
}

float MATRIX::GetMij(int i, int j)
{
    if ((m > 0) && (n > 0))
        /*!
         Получаем элементы с матрицы
         \return элементы с матрицы
        */
        return M[i][j];
    else
        return 0;
}

void MATRIX::SetMij(int i, int j, float value)
{
    if ((i < 0) || (i >= m))
        return;
    if ((j < 0) || (j >= n))
        return;
    M[i][j] = value;
}

void MATRIX::Print(const char* ObjName)
{
    cout << "Object: " << ObjName << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << M[i][j] << "\t";
        cout << endl;
    }
    cout << "---------------------" << endl << endl;
}

MATRIX MATRIX::operator=(const MATRIX& _M) {
    if (n > 0)
    {
        /* ... освободить память, выделенную ранее для объекта *this ... */
        for (int i = 0; i < m; i++)
            delete[] M[i];
    }

    if (m > 0)
    {
        delete[] M;
    }

    // Копирование данных M <= _M
    m = _M.m;
    n = _M.n;

    // Выделить память для M опять
    M = (float**) new float *[m]; // количество строк, количество указателей
    for (int i = 0; i < m; i++)
        M[i] = (float*) new float[n];

    // заполнить значениями
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = _M.M[i][j];
    return *this;
}
/*!
 Изменения  строк и столбцов из исходной матрицы
 \param y исходное кол-во строк матрицы
 \param int х исходное кол-во столбцов матрицы
 \param int& b исходные столбцы матрицы
 \param int&v задаваемые строки матрицы
*/

void MATRIX::rowscols(int y,int x,int& b,int&v){
    MATRIX K(y, x); ///< Временная матрица с помощью которой происходит изменение строк и столбцов

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            K.SetMij(i, j, M[i][j]);
    b=y;
    v=x;
    *this = std::move(K);

}

int MATRIX::get_m(){
    return m;
}
int MATRIX::get_n(){
    return n;
}
float MATRIX::get_Matrix() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            return **M;
        }
    }
}

void MATRIX::set_Matrix(float **K, int _m, int _n){
    for (int i = 0; i < _m; ++i) {
        for (int j = 0; j < _n ; ++j) {
            M = K;
        }
    }
}

void MATRIX::set_m(int _m){
    m = _m;
}

void MATRIX::set_n(int _n){
    n = _n;
}

MATRIX::~MATRIX() {
    if (n > 0) {
        // освободить выделенную память для каждой столбцы
        for (int i = 0; i < m; i++)
            delete[] M[i];
    }
    if (m > 0)
        delete[] M;
}
/*!
 Получение транспонированой матрицы
 */
void MATRIX::Transpose(){
    float ** K = new float *[n];
    for (int i = 0; i < n; i++) {
        K[i] = new float [m];
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            K[j][i]=M[i][j];
        }
    }
    int temp;
    temp = m; m = n; n = temp;
    this->set_Matrix(K, m, n);
    this->set_m(m);
    this->set_n(n);
   // *this=move(X);
}

/*!
 Получение подматрицы из исходной матрицы
 \param MATRIX &A исходная матрица
 \param int rows исходные строки матрицы
 \param int cols исходные столбцы матрицы
 \param int x задаваемые строки матрицы
 \param int y задаваемые столбцы матрицы
 */

MATRIX MATRIX::submatrix( MATRIX &A, int rows, int cols,int x,int y )
{
    MATRIX result( rows,  cols);
    float MAT[rows][cols]; /* ... матрица ... */
    if ((x<=m-rows)&&(y<=n-cols))
    {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                MAT[i][j] = M[x + i][y + j];
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.SetMij(i, j, MAT[i][j]);
            }
        }
    }
   A = move(result);
    return A;
}
/*!
 Получение типа матрицы
 */

MATRIX MATRIX::whyMatrix() {
    MATRIX temp=*this;
            cout << "Диагональная матрица" << " " << temp.diagonal() << "\n";
            cout << "Квадратная матрица" << " " << temp.square() << "\n";
            cout << "Нулевая матрица" << " " << temp.nullmatrix() << "\n";
            cout << "Единичная матрица" << " " << temp.unitmatrix() << "\n";
            cout << "Симметричная матрица" << " " << temp.simmetric() << "\n";
            cout << "Нижне-треугольная матрица"<< " "<<temp.downtringle()<< "\n";
            cout << "Верхне-треугольная матрица " << " "<< temp.uptringle()<< "\n";
    return temp;

}

MATRIX& MATRIX::operator++()
{
    /**
    * ... Перегрузка  пре инкремента ...
    */
    for (int i = 0; i < m ; ++i) {
        for (int j = 0; j < n; ++j) {
            M[i][j]=++M[i][j];
        }
    }
    return *this;
}
MATRIX& MATRIX::operator--()
{
    /**
      * ... Перегрузка  пре декремента ...
      */
    for (int i = 0; i < m ; ++i) {
        for (int j = 0; j < n; ++j) {
            M[i][j]=--M[i][j];
        }
    }
    return *this;
}
//префиксная версия возвращает значение после декремента
MATRIX MATRIX::operator++(int)
{
    /**
    * ... Перегрузка  пост инкремента ...
    */
// Создаем временный объект класса MATRIX с текущим значением переменной temp
MATRIX temp = *this;
            ++(*this);
    return temp;
}

//постфиксная версия возвращает значение до декремента
MATRIX MATRIX::operator--(int)
{
    /**
      * ... Перегрузка  пост декремента ...
      */
    // Создаем временный объект класса MATRIX с текущим значением переменной temp
    MATRIX temp = *this;
    --(*this);

    return temp;
}


ostream& operator<< (std::ostream &out, const MATRIX &point)
{
    for (int i = 0; i < point.m; ++i) {
        for (int j = 0; j < point.n; ++j) {
            out<<point.M[i][j]<<" ";
        }
        out<<endl;
    }

    return out;
}
istream& operator>> (std::istream &in, MATRIX &point)
{
    // Поскольку operator>> является другом класса MATRIX, то мы имеем прямой доступ к членам MATRIX
    for (int i = 0; i < point.m; ++i) {
        for (int j = 0; j <point.n ; ++j) {
            in>>point.M[i][j];
        }
    }
    return in;
}
ifstream& operator>> (ifstream& fin, MATRIX& matrix){
    for (int i = 0; i < matrix.m; ++i) {
        for (int j = 0; j < matrix.n; ++j) {
            fin>>matrix.M[i][j];
        }
        return fin;
    }
}

ofstream& operator<< (ofstream& fs, const MATRIX& matrix){
    for (int i = 0; i <matrix.m; ++i) {
        for (int j = 0; j <matrix.n; ++j) {
            fs<<matrix.M[i][j]<<" ";
        }
        fs <<endl;
    }
    return fs;
}

bool MATRIX::operator==(const MATRIX& A){
    if(n==A.n && m == A.m){
        for (int i=0 ; i<m ; i++){
            for (int j=0 ; j<m ; j++){
                if(M[i][j]!=A.M[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

/*!
Перегрузка оператора !=
\param[in] const MATRIX& A Исходная матрица
*/
bool MATRIX::operator!=(const MATRIX& A){
    if(n==A.n && m == A.m){
        for (int i=0 ; i<m ; i++){
            for (int j=0 ; j<m ; j++){
                if(M[i][j]!=A.M[i][j]){
                    return true;
                }
            }
        }
        return false;
    }
    return true;
}
/*!
Проверка на диагональность матрицы
*/
bool MATRIX::diagonal() {
    MATRIX temp = *this;
    bool diag = true;
    for (int i = 0; i < temp.m; i++) {
        for (int j = 0; j < temp.n; j++) {
            if ((i != j) && (temp.M[i][j] != 0)) {
                diag = false;
            } else if ((i == j) && (temp.M[i][j] == 0)) {
                diag = false;
            }
        }
    }
    return diag;
}
/*!
Проверка на квадратичность матрицы
*/
bool MATRIX::square(){
    bool sq=true;
    MATRIX temp = *this;
    if (temp.m != temp.n) {
        sq = false; // не квадратичная
    }
    return sq;
}

/*!
Проверка на нулёвую матрицу
*/

bool MATRIX::nullmatrix() {
    MATRIX temp = *this;
    bool nullm = true;
    for (int i = 0; i < temp.m; i++)
        for (int j = 0; j < temp.n; j++) {
            if (temp.M[i][j] != 0) {
                nullm = false; // не нулевая
            }
        }
    return nullm;
}

/*!
Проверка на единость матрицы
*/

bool MATRIX::unitmatrix() {
    MATRIX temp = *this;
    bool unitm = true;
    for (int i = 0; i < temp.m; i++){
        for (int j = 0; j < temp.n; j++) {
            if (i == j && temp.M[i][j] != 1 ) {
                unitm = false;
            }
            else if(temp.M[i][j]!=0 && i!=j){
                unitm=false;
            }

        }
}
    return unitm;
}

/*!
Проверка на симметричность матрицы
*/

bool MATRIX::simmetric() {
    bool simm = false;
    MATRIX temp = *this;
    if(temp.n == temp.m) {
        for (int i = 0; i < temp.n; i++) {
            for (int j = i+1; j < temp.m; j++) {
                if (temp.M[i][j] != temp.M[j][i]) {
                    simm = false;
                    break;// не симметрична
                }
                else{
                    simm = true;
                }
            }
        }
    }
    return simm;
}


/*!
Проверка на нижнетреугольную матрицу
*/

bool MATRIX::downtringle(){
    bool downt = true;
    MATRIX temp = *this;
    if(temp.n == temp.m) {
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < m; j++)
                if (temp.M[i][j]!= 0)
                    downt = false;
    } else{
        downt = false;
    }
    return downt;
}

/*!
Проверка на верхнетреугольную матрицу
*/

bool MATRIX::uptringle(){
    bool uptr = true;
    MATRIX temp = *this;
    if(temp.n == temp.m) {
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (temp.M[i][j] != 0)
                    uptr = false;
    } else{
        uptr = false;
    }
    return uptr;
}


/*!
Вызов меню
*/
void MATRIX::menu(){
    cout<<"1. пре- и постинкремент (++), пре- и постдекремент (--);\n";
    cout<<"2. изменение числа строк и числа столбцов;\n";
    cout<<"3. извлечение подматрицы заданного размера;\n";
    cout<<"4. транспонированние матрицы;\n";
    cout<<"5. проверка типа матрицы (квадратная, диагональная, нулевая, единичная, симметрическая,\n"
          "верхняя треугольная, нижняя треугольная);\n";
    cout<<"6. вывод матрицы\n";
}
