#include <iostream>
#include <fstream>
#include "PhoneBook.h"
using namespace std;

Abonent::Abonent()
{

}

Abonent::Abonent(const char* name, int hPhone, int mPhone, int wPhone)
{	
	this->name = new char[strlen(name)+1];
	SetName(name);
	SetHphone(hPhone);
	SetMphone(mPhone);
	SetWphone(wPhone);
}

void Abonent::ShowAbonent()
{
	cout << GetName() << " " << GetHphone() << " " << GetMphone() << " " << GetWphone() << endl;
}

void Abonent::SetName(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name)+1, name);
}

char* Abonent::GetName()
{
	return this->name;
}

void Abonent::SetHphone(int hPhone)
{
	this->homePhone = hPhone;
}

int Abonent::GetHphone()
{
	return this->homePhone;
}

void Abonent::SetMphone(int mPhone)
{
	this->mobilePhone = mPhone;
}

int Abonent::GetMphone()
{
	return this->mobilePhone;
}

void Abonent::SetWphone(int wPhone)
{
	this->workPhone = wPhone;
}

int Abonent::GetWphone()
{
	return this->workPhone;
}
	
PhoneBook::PhoneBook()
{

}

PhoneBook::PhoneBook(Abonent* abonent, int& n)
{
	this->abonents = new Abonent[n];
	this->n = n;
	for (size_t i = 0; i < n; i++)
	{
		this->abonents[i] = abonent[i];
	}
}

void PhoneBook::AddAbonent(Abonent abonent[], int& n)
{
	this->abonents = new Abonent[n + 1];
	for (size_t i = 0; i < n; i++)
	{
		abonents[i] = abonent[i];
	}
	this->abonents[n] = abonent[n];
	n++;
	this->n = n;
}
void PhoneBook::DeleteAbonent(Abonent abonent[], const char* name, int& n)
{
	delete[] abonents;
	this->abonents = new Abonent[n - 1];
	for (size_t i = 0,j=0; i < n; i++)
	{
		if (!strstr(abonent[i].GetName(), name))
		{
			this->abonents[j] = abonent[i];
			j++;
		}
	}
	n--;
	this->n = n;
}

void PhoneBook::ShowAbonents()
{
	for (size_t i = 0; i < this->n; i++)
	{
		abonents[i].ShowAbonent();
	}
}

void PhoneBook::FindAbonent(const char* name)
{
	for (size_t i = 0; i < this->n; i++)
	{
		if (strstr(this->abonents[i].GetName(), name))
			abonents[i].ShowAbonent();
	}
}

void PhoneBook::ToFile()
{
	ofstream fin("File.txt");
	for (size_t i = 0; i < this->n; i++)
	{
		fin << abonents[i].GetName() << " " << abonents[i].GetHphone() << " " << abonents[i].GetMphone() << " " << abonents[i].GetWphone() << endl;
	}
	fin.close();
}

void PhoneBook::FromFile()
{
	ifstream fout("File.txt");
	char name[25];
	int h, m, w;
	for (size_t i = 0; i < this->n; i++)
	{
		fout >> name >> h >> m >> w;
		abonents[i].SetName(name);
		abonents[i].SetHphone(h);
		abonents[i].SetMphone(m);
		abonents[i].SetWphone(w);
	}
	fout.close();
}