#ifndef Receipt_h
#define Receipt_h

#include <iostream>
#include <string>

using namespace std;

namespace rcpt {
//базовый класс
    class Receipt {
    public:
        virtual void print(string) = 0;// Декларация метода

        void sandwiches();
        void khachapuri();
        void pizza();
        void noodles();
        void julien();
        void roast();

    };

//Класс завтрак. Просходит приватное наследование
    class Breakfast : private Receipt {
    public:
        void print(string n = "\n Завтрак\n") override {
            cout << n << endl;
        }
        void sandwiches();
        void khachapuri();

    };

//Класс обед. Происходит защитное наследование
    class Lunch : protected Receipt {
    public:
        void print(string n = "\nОбед \n") override {
            cout << n << endl;
        }
        void pizza();
        void noodles();
    };

//Класс ужин. Проиходит виртуальное наследование
    class Dinner : virtual public Receipt {
    public:
        void print(string n = "\nУжин \n") override {
            cout << n << endl;
        };
    };

//все рецепты
    class All : public Breakfast, public Lunch, public Dinner {
    public:
        void print(string n = "----- ВСЕ РЕЦЕПТЫ ----- \n") override {
            cout << n << endl;
        }

    };
}
#endif /* Receipt_h */