//
// Created by prohor on 18.11.21.
//
#include <iostream>
#include "check.h"
#include<fstream>

using namespace std;

void check::checking(){
    int number;
    check chock;
    cout << "Enter your login" << endl;
    cin >> number;
    ifstream foutw;
    try
    {
        foutw.open("check.txt",ifstream::in);

    }
    catch (const std::exception& ex)
    {
        cout << ex.what() << endl;
        cout << "Error" << endl;
    }
    if (!foutw.is_open())
    {
        cout << "error" << endl;
    }
    else
    {
        try
        {
            while (foutw.read((char*)&chock, sizeof(check)))
            {
                if (chock.person_id == number)
                {
                    if (chock.operation == 1){
                        cout<<"RM-number: "<< chock.rm_number << " "<<" Вывод средств"<< endl;
                    }
                    if (chock.operation == 2){
                        cout<<"RM-number: "<< chock.rm_number << " "<<"  Пополнение средств"<<endl;
                    }
                    if (chock.operation == 3){
                        cout<<"RM-number: "<< chock.rm_number << " "<<"  Перевод с карты на карту"<<endl;
                    }
                    if (chock.operation == 4){
                        cout<<"RM-number: "<< chock.rm_number << " "<<"  Пополнение счёта телефона"<<endl;
                    }
                    if (chock.operation == 5){
                        cout<<"RM-number: "<< chock.rm_number << " "<<"  Просмотр средств"<<endl;
                    }
                    if (chock.operation == 6){
                        cout<<"RM-number: "<< chock.rm_number << " "<<"  Неудалась операция"<<endl;
                    }
                    if (chock.operation == 7){
                        cout<<"RM-number: "<< chock.rm_number << " "<<"  Новый пароль"<<endl;
                    }
                }
            }
        }
        catch (const std::exception& ex)
        {
            cout << ex.what() << endl;
            cout << "Error" << endl;
        }

    }
    foutw.close();
}
