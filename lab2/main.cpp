#include <iostream>
#include "Recept.h"
using namespace std;
using namespace rcpt;

int main() {

    Simple a;
    Middle b;
    Hard c;
    All d;
    int k;

    while (true) {
        cout << "Показать рецепты:" << endl <<
             "1: все рецепты" << endl <<
             "2: по сложности" << endl <<
             "3: выход" << endl;
        cin >> k;
        switch (k) {
            case 1: {
                d.Print();
                d.Simple::omlete();
                d.Simple::salad();
                d.Middle::borsch();
                d.Middle::pancakes();
                d.Hard::mousse();
                d.Hard::oysters();
                break;
            }
            case 2: {
                a.Print();
                a.omlete();
                a.Print();
                a.salad();

                b.Print();
                b.borsch();
                b.Print();
                b.pancakes();

                c.Print();
                c.mousse();
                c.Print();
                c.oysters();

                break;
            }
            case 3:{
                return 0;
            }
        }
    }
}