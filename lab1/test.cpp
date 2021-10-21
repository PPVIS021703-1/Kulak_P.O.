#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL
#include "doctest.h"
#include "matrix.h"

using namespace std;

TEST_CASE("1st test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test.txt");
    in>>n1>>m1;
    MATRIX E(m,n);
    in>>E;
    CHECK(M==E);
}

TEST_CASE("2nd test") {
    int n,m,x,y;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input2.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    fin>>x>>y;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test2.txt");
    in>>m1>>n1;

    MATRIX E(m1,n1);
    MATRIX X(m1, n1);
    in>>E;
    M.submatrix(X,m1,n1,x,y);
    CHECK(X==E);
}

TEST_CASE("3rd test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input3.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test3.txt");
    in>>m1>>n1;
    MATRIX E(m1,n1);
    in>>E;
    M.rowscols(m1,n1,m,n);
    CHECK(M==E);
}
TEST_CASE("4th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input4.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test4.txt");
    in>>m1>>n1;
    MATRIX E(m1,n1);
    in>>E;
    M.Transpose();
    CHECK(M==E);
}

TEST_CASE("5th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input5.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test5.txt");
    in>>m1>>n1;
    MATRIX E(m1,n1);
    in>>E;
    M.Transpose();
    CHECK(M != E);
}

TEST_CASE("6th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input6.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test6.txt");
    in>>m1>>n1;
    MATRIX E(m1,n1);
    in>>E;
    M.rowscols(m1,n1,m,n);
    CHECK(M==E);
}

TEST_CASE("7th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input7.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test7.txt");
    bool y;
    in>>y;
    bool x;
    x=M.diagonal();
    CHECK( x == y);
}

TEST_CASE("8th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input8.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test8.txt");
    bool y;
    in>>y;
    bool x;
    x=M.square();
    CHECK( x == y);
}

TEST_CASE("9th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input9.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test9.txt");
    bool y;
    in>>y;
    bool x;
    x=M.nullmatrix();
    CHECK( x != y);
}

TEST_CASE("10th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input10.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test10.txt");
    bool y;
    in>>y;
    bool x;
    x=M.simmetric();
    CHECK( x == y);
}
TEST_CASE("11th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input11.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    fin.close();
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test11.txt");
    bool y;
    in>>y;
    bool x;
    x = M.downtringle();
    CHECK( x == y);
}

TEST_CASE("12th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input12.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test12.txt");
    in>>m1>>n1;
    MATRIX E(m1,n1);
    in>>E;
    M.Transpose();
    CHECK(M==E);
}

TEST_CASE("13th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input13.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test13.txt");
    bool y;
    in>>y;
    bool x;
    x=M.uptringle();
    CHECK( x == y);
}


TEST_CASE("14th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input14.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test14.txt");
    in>>m1>>n1;
    MATRIX E(m1,n1);
    in>>E;
    M++;
    CHECK(M==E);
}


TEST_CASE("15th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input15.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test15.txt");
    in>>m1>>n1;
    MATRIX E(m1,n1);
    in>>E;
    M--;
    CHECK(M==E);
}

TEST_CASE("1st test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test.txt");
    in>>n1>>m1;
    MATRIX E(m,n);
    in>>E;
    CHECK_FALSE(M!=E);
}

TEST_CASE("2nd test") {
    int n,m,x,y;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input2.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    fin>>x>>y;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test2.txt");
    in>>m1>>n1;

    MATRIX E(m1,n1);
    MATRIX X(m1, n1);
    in>>E;
    M.submatrix(X,m1,n1,x,y);
    CHECK_FALSE(X!=E);
}

TEST_CASE("3rd test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input3.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test3.txt");
    in>>m1>>n1;
    MATRIX E(m1,n1);
    in>>E;
    M.rowscols(m1,n1,m,n);
    CHECK_FALSE(M!=E);
}
TEST_CASE("4th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input4.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test4.txt");
    in>>m1>>n1;
    MATRIX E(m1,n1);
    in>>E;
    M.Transpose();
    CHECK_FALSE(M != E);
}

TEST_CASE("5th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input5.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test5.txt");
    in>>m1>>n1;
    MATRIX E(m1,n1);
    in>>E;
    M.Transpose();
    CHECK_FALSE(M==E);
}

TEST_CASE("6th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input6.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test6.txt");
    in>>m1>>n1;
    MATRIX E(m1,n1);
    in>>E;
    M.rowscols(m1,n1,m,n);
    CHECK_FALSE(M!=E);
}

TEST_CASE("7th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input7.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test7.txt");
    bool y;
    in>>y;
    bool x;
    x=M.diagonal();
    CHECK_FALSE( x != y);
}

TEST_CASE("8th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input8.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test8.txt");
    bool y;
    in>>y;
    bool x;
    x=M.square();
    CHECK_FALSE( x != y);
}

TEST_CASE("9th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input9.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test9.txt");
    bool y;
    in>>y;
    bool x;
    x=M.nullmatrix();
    CHECK_FALSE( x == y);
}

TEST_CASE("10th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input10.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test10.txt");
    bool y;
    in>>y;
    bool x;
    x=M.simmetric();
    CHECK_FALSE( x != y);
}
TEST_CASE("11th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input11.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    fin.close();
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test11.txt");
    bool y;
    in>>y;
    bool x;
    x = M.downtringle();
    CHECK_FALSE( x != y);
}

TEST_CASE("12th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input12.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test12.txt");
    in>>m1>>n1;
    MATRIX E(m1,n1);
    in>>E;
    M.Transpose();
    CHECK_FALSE(M!=E);
}

TEST_CASE("13th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input13.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test13.txt");
    bool y;
    in>>y;
    bool x;
    x=M.uptringle();
    CHECK_FALSE( x != y);
}


TEST_CASE("14th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input14.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test14.txt");
    in>>m1>>n1;
    MATRIX E(m1,n1);
    in>>E;
    M++;
    CHECK_FALSE(M!=E);
}


TEST_CASE("15th test") {
    int n,m;
    fstream fin;
    fin.open("/home/prohor/CLionProjects/ppvis1/test/input15.txt");
    fin>>m>>n;
    MATRIX M(m, n);
    fin>>M;
    int n1,m1;
    fstream in;
    in.open("/home/prohor/CLionProjects/ppvis1/test/input_test15.txt");
    in>>m1>>n1;
    MATRIX E(m1,n1);
    in>>E;
    M--;
    CHECK_FALSE(M!=E);
}