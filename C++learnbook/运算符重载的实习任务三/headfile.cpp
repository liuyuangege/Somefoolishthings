#include "head.h"
MyString::MyString(const MyString& s)
{
	char* tmp = new char[strlen(s.str) + 1];
	str = tmp;
}
MyString::MyString(MyString&& s)
{
	str = s.str;
}
MyString::~MyString()
{
	if(str!=nullptr)
	delete str;
}
MyString& MyString::operator=(const MyString& s)
{
	if (this == &s)
		return *this;
	str = new char[strlen(s.str) + 1];
	strcpy(str, s.str);
	return *this;
}
MyString& MyString::operator=(MyString&& s)
{
	if (this == &s)
		return *this;
	str = new char[strlen(s.str) + 1];
	strcpy(str, s.str);
	return *this;
}
int MyString::size()const
{
	return strlen(str);
}
MyString MyString::operator+(const MyString& s)const
{
	MyString tmp;
	tmp.str = new char[size() + s.size() + 1];
	for(int i=0;i<size();i++)
	{
		tmp.str[i]=str[i];
	}
	for(int i=0;i<s.size();i++)
	{
		tmp.str[size()+i]=s.str[i];
	}
	tmp.str[size() + s.size()]='\0';
	return tmp;
}
MyString MyString::operator+(const char* s)const
{
	MyString tmp;
	tmp.str = new char[size() + strlen(s) + 1];
	for(int i=0;i<size();i++)
	{
		tmp.str[i]=str[i];
	}
	for(int i=0;i<strlen(s);i++)
	{
		tmp.str[size()+i]=s[i];
	}
	tmp.str[size() + strlen(s)]='\0';
	return tmp;
}
char& MyString::operator[](int index)
{
	return str[index];
}
const char& MyString:: operator[](int index) const
{
	return str[index];
}
std::ostream& operator<<(std::ostream& out, const MyString& s)
{
	for(int i=0;i<s.size();i++)
	{
		out<<s.str[i]; 
	} 
	//out<<endl;
	return out;
}

