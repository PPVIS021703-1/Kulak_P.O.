#include <iostream>
#include "Recept.h"
using namespace std;
using namespace rcpt;

int main() {

    Breakfast morning;
    Lunch daytime;
    Dinner evening;
    All all_recept;
    int k;

    while (true) {
        cout << "Показать рецепты:" << endl <<
             "1: все рецепты" << endl <<
             "2: Трапеза" << endl <<
             "3: выход" << endl;
        cin >> k;
        switch (k) {
            case 1: {
                all_recept.print();
                all_recept.Breakfast::sandwiches();
                all_recept.Breakfast::khachapuri();
                all_recept.Lunch::pizza();
                all_recept.Lunch::noodles();
                all_recept.Dinner::julien();
                all_recept.Dinner::roast();
                break;
            }
            case 2: {
                morning.print();
                morning.sandwiches();
                morning.print();
                morning.khachapuri();

                daytime.print();
                daytime.pizza();
                daytime.print();
                daytime.noodles();

                evening.print();
                evening.noodles();
                evening.print();
                evening.julien();

                break;
            }
            case 3:{
                return 0;
            }
        }
    }
}