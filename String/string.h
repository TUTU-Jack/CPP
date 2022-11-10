#pragma once
#include <iostream>

using namespace std;

class String {

public:
	//带参构造函数
	String(const char* str = 0);
	//拷贝构造函数
	String(const String& str);
	~String();
public:
	//拷贝复制
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
	//检测自我赋值
	if (&str == this)
		return *this;

	delete[] this->pdata;
	this->pdata = new char[strlen(str.pdata) + 1];
	strcpy(this->pdata, str.pdata);

	return *this;
}
