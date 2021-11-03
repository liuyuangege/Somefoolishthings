#include <iostream>
#include <cstring>
using namespace std;
class MyString {
public:
	MyString(const char* s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	MyString(char* s) {
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	MyString() {
		str = nullptr;
	}
	MyString(const MyString& s);
	MyString(MyString&& s);
	~MyString();
	MyString& operator=(const MyString& s);
	MyString& operator=(MyString&& s);
	int size()const;
	MyString operator+(const MyString& s)const;
	MyString operator+(const char* s)const;
	char& operator[](int index);
	const char& operator[](int index) const;
	friend std::ostream& operator<<(std::ostream& out, const MyString& s);
private:
	char* str;
};





