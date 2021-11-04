#include "Recept.h"
#include <iostream>

using namespace std;
using namespace rcpt;
void Receipt::omlete(){
    cout << "\nОМЛЕТ\nяйца;\nмолоко;\nсоль; "<< endl << endl;
}

void Receipt::salad(){
    cout << "\nСАЛАТ\n огурец\n большой помидор\n болгарский перец" << endl << endl;
}

void Receipt::borsch(){
    cout << "\nБОРЩ\nМясо свиное\nКартофель\nЛук репчатый " << endl << endl;
}

void Receipt::pancakes(){
    cout << "\nБЛИНЫ\nЯйцо куриное\nМолоко\nСахар\nСоль\nМука" << endl << endl;
}

void Receipt::mousse(){
    cout << "\nМУСС\nШоколад черный\nСливки жирные \nСахар \nЯйца комнатной температуры" << endl << endl;
}

void Receipt::oysters(){
    cout << "\nУСТРИЦЫ\n\nУстрицы\nЛук шало\nЛистья шпината свежие\nПетрушка свежая\nЛистья сельдерея" << endl << endl;
}


void Simple::omlete(){
    Receipt::omlete();
}

void Simple::salad(){
    Receipt::salad();
}

void Middle::borsch(){
    Receipt::borsch();
}

void Middle::pancakes(){
    Receipt::pancakes();
}
