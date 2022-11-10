#pragma once
#include <iostream>

using namespace std;

class String {

public:
	//���ι��캯��
	String(const char* str = 0);
	//�������캯��
	String(const String& str);
	~String();
public:
	//��������
	String& operator = (const String& str);
	char* get_c_str() const { return pdata; };
private:
	char* pdata;
};

ostream& operator << (ostream& os, const String& str)
{
	return os << str.get_c_str();
}

inline String::String(const char* str)
{
	if (str)
	{
		pdata = new char[strlen(str) + 1];
		strcpy(pdata, str);
	}
	else
	{
		pdata = new char[1];
		*pdata = '\0';
	}
}

inline String::String(const String& str)
{
	pdata = new char[strlen(str.pdata) + 1];
	strcpy(pdata, str.pdata);

}

inline String::~String()
{
	delete[] pdata;
	cout << "Destructor created" << endl;
}

inline String& String::operator = (const String& str)
{
	//������Ҹ�ֵ
	if (&str == this)
		return *this;

	delete[] this->pdata;
	this->pdata = new char[strlen(str.pdata) + 1];
	strcpy(this->pdata, str.pdata);

	return *this;
}
