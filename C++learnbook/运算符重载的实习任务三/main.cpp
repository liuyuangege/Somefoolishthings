#include<iostream>
#include<cstring>
#include"head.h"
int main() {
	MyString s("Hello");
	cout << s << endl;
	MyString s2 = s + "World";
	cout << s2 << endl;
	cout << "Index 5:" << s2[5] << endl;
	MyString s3(move(s2));
	cout << s3 << endl;
	return 0;
}
