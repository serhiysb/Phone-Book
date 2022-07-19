#include <iostream>
#include "PhoneBook.h"
using namespace std;

int main()
{
    int n = 10;
    char name[25];
    int num1, num2, num3;
    int n = 1;
 
    Abonent abonent[10];
    
    cout << "Name: ";
    cin >> name;
    abonent[0].SetName(name);
    cout << "Home number: ";
    cin >> num1;
    abonent[0].SetHphone(num1);
    cout << "Work number: ";
    cin >> num2;
    abonent[0].SetWphone(num2);
    cout << "Mobile: ";
    cin >> num3;
    abonent[0].SetMphone(num3);

    PhoneBook abonents(abonent, n);

    cout << "Add\nName: ";
    cin >> name;
    abonent[1].SetName(name);
    cout << "Home number: ";
    cin >> num1;
    abonent[1].SetHphone(num1);
    cout << "Work number: ";
    cin >> num2;
    abonent[1].SetWphone(num2);
    cout << "Mobile: ";
    cin >> num3;
    abonent[1].SetMphone(num3);
    abonents.AddAbonent(abonent, n);

    cout << "Add\nName: ";
    cin >> name;
    abonent[2].SetName(name);
    cout << "Home number: ";
    cin >> num1;
    abonent[2].SetHphone(num1);
    cout << "Work number: ";
    cin >> num2;
    abonent[2].SetWphone(num2);
    cout << "Mobile: ";
    cin >> num3;
    abonent[2].SetMphone(num3);
    abonents.AddAbonent(abonent, n);
    abonents.ShowAbonents();

    cout << "Find\nName: ";
    cin >> name;
    abonents.FindAbonent(name);

    cout << "Delete\nName: ";
    cin >> name;
    abonents.DeleteAbonent(abonent, name, n);
    abonents.ShowAbonents();

    abonents.ToFile();
    abonents.FromFile();
    cout << "File completed!\n";
}