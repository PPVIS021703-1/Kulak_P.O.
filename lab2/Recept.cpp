#include "Recept.h"
#include <iostream>

using namespace std;
using namespace rcpt;

void Receipt::sandwiches(){
    cout << "\n Бутерброд \n\n Хлеб\n Докторская колбаса"<< endl << endl;
}

void Receipt::khachapuri(){
    cout << "\n Хачапури\n Мука\n Молоко\n Яйца\n Сыр" << endl << endl;
}

void Receipt::pizza(){
    cout << "\nПицца\n Яйцо\nМука \nКолбаса \n Сыр \n Помидор  " << endl << endl;
}

void Receipt::noodles(){
    cout << "\n Лапша\n Чеснок\n Филе\n Морковь \n Соус \nПерец" << endl << endl;
}

void Receipt::julien(){
    cout << "\n Жюльен\n Грибы\n Лук\n Сливки\n Филе" << endl << endl;
}

void Receipt::roast(){
    cout << "\n Жаркое\n\n Картофель\n Укроп\n Паприка\n Морковь\n Лист лавровый" << endl << endl;
}


void Breakfast::sandwiches(){
    Receipt::sandwiches();
}

void Breakfast::khachapuri(){
    Receipt::khachapuri();
}

void Lunch::pizza(){
    Receipt::pizza();
}

void Lunch::noodles(){
    Receipt::noodles();
}
