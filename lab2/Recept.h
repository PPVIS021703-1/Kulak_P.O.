#ifndef Receipt_h
#define Receipt_h

#include <iostream>
#include <string>

using namespace std;

namespace rcpt {
//базовый класс
    class Receipt {
    public:
        virtual void Print(string) = 0;

        void omlete();
        void salad();
        void borsch();
        void pancakes();
        void mousse();
        void oysters();
    };

//простые рецепты
    class Simple : private Receipt {
    public:
        void Print(string n = "----- ПРОСТЫЕ РЕЦЕПТЫ ----- \n\n") override {
            cout << n << endl;
        }
        void omlete();
        void salad();

    };

//рецепты средней сложности
    class Middle : protected Receipt {
    public:
        void Print(string n = "\n----- РЕЦЕПТЫ СРЕДНЕЙ СЛОЖНОСТИ -----\n") override {
            cout << n << endl;
        }
        void borsch();
        void pancakes();
    };

//сложные рецепты
    class Hard : virtual public Receipt {
    public:
        void Print(string n = "\n----- СЛОЖНЫЕ РЕЦЕПТЫ -----\n") override {
            cout << n << endl;
        };
    };

//все рецепты
    class All : public Simple, public Middle, public Hard {
    public:
        void Print(string n = "----- ВСЕ РЕЦЕПТЫ ----- \n") override {
            cout << n << endl;
        }

    };
}
#endif /* Receipt_h */