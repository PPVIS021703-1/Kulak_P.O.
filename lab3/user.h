#include <iostream>
#pragma once
class user               //класс с данными пользователя
{
public:
	int numberuser;  //логин пользователя      
	int password;//пароль пользователя
    int data;//количество денег депозита пользователя
    int year; // год истечения
    int mouth; //месяц истечния
	void database(); //метод для записи логина пользователя в текстовый документ
};

