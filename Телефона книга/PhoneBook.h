#pragma once

class Abonent
{
private:
	char* name;
	int homePhone;
	int mobilePhone;
	int workPhone;
public:
	Abonent();
	Abonent(const char* name, int hPhone, int mPhone, int wPhone);

	void ShowAbonent();
	void SetName(const char* name);
	void SetHphone(int hPhone);
	void SetMphone(int mPhone);
	void SetWphone(int wPhone);
	char* GetName();
	int GetHphone();
	int GetMphone();
	int GetWphone();
};


class PhoneBook
{
private:
	Abonent* abonents;
	int n;
public:
	PhoneBook();
	PhoneBook(Abonent* abonent, int& n);

	void AddAbonent(Abonent abonent[], int& n);
	void DeleteAbonent(Abonent abonent[], const char* name, int& n);
	void FindAbonent(const char* name);
	void ShowAbonents();
	void ToFile();
	void FromFile();
};