#pragma once
#include"user.h"
class operation:public user                    //класс выполнения операций пользователем
{
public:
	void addordeletemoneytofromdepozit();  //метод добавления или снятия денег с депозита
	void printbalance();//метод просмотра баланса депозита
};

