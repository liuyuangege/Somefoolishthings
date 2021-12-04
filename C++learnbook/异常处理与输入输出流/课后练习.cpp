//#include <iostream>
//#include <sstream>
//using namespace std;
//string writeString(int a, int b, char op) {
//	ostringstream ostr;
//	ostr << a << op << b;
//	return (ostr.str());
//}
//int calString(const string& s) {
//	int a, b, result;
//	char op;
//	istringstream istr(s);
//	istr >> a >> op >> b;
//	switch (op) {
//	case '+':result = a + b; break;
//	case '-':result = a - b; break;
//	case '*':result = a * b; break;
//	default:result = 0;
//	}
//	return result;
//}
//int main() {
//	cout << calString(writeString(3, 4, '+'));
//	cout << calString(writeString(3, 5, '-'));
//	cout << calString(writeString(3, 4, '*'));
//	cout << calString(writeString(4, 2, '/'));
//	return 0;
//}