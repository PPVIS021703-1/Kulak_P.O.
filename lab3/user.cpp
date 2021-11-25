#include "user.h"
#include <iostream>
#include <fstream>
using namespace std;
void user::database()
{
	user person;
	ifstream fin;
	try
	{
		fin.open("person.txt", ofstream::app);
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
		cout << "Error" << endl;
	}	
	if (!fin.is_open())
	{
		cout << "error" << endl;
	}
	else
	{
		try
		{
		while (fin.read((char*)&person, sizeof(user)))
		{
			cout << "User Number is " << person.numberuser << endl;
            if (person.mouth < 10 && person.year < 10) {
                cout << "User Date of Death is " << "0" <<person.mouth << "/" <<"0"<<person.year << endl;
            }else if (person.mouth < 10){
                cout << "User Date of Death is " << "0" <<person.mouth << "/" <<person.year << endl;
            }else if (person.year < 10){
                cout << "User Date of Death is " <<person.mouth << "/" <<"0"<<person.year << endl;
            } else{
                cout << "User Date of Death is " <<person.mouth << "/" <<person.year << endl;
            }
		}
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
			cout << "Error" << endl;
		}

	}
	fin.close();
}

