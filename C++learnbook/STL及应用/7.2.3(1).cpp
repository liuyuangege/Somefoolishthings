//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//class Student {
//private:
//	string name;
//	string specialty;//专业
//	long id;// 学号
//	double creditPoint; //学分积点
//public:
//	Student(string n, string s, long i, double c)
//		:name(n), specialty(s), id(i), creditPoint(c) {}
//	void setCreditPoint(double c) { creditPoint = c; }
//	double getCreditPoint()const { return creditPoint; }
//	string getName()const { return name; }
//	long getId()const { return id; }
//	string getSpecialty()const { return specialty; }
//	friend std::ostream& operator<<(std::ostream& out, const Student& s);
//};
//ostream& operator<<(ostream& out, const Student& s) {
//	out << "Name:" << s.name << endl;
//	out << " Id:" << s.id << endl;
//	out << " Specialty:" << s.specialty << endl;
//	out << " CreditPoint:" << s.creditPoint << endl;
//	return out;
//}
//int main() {
//	vector<Student> vec{
//	{"zhang","Computer",11001,4.2},
//	{"wang","Computer",11002,3.8},
//	{"Li","English",12001,4.1},
//	{"Tang","English",12002,3.9},
//	{"Qian","Computer",11003,4.0},
//	{"Song","Geology",10001,4.1}
//	};
//	for (auto e : vec)
//		cout << e;
//	return 0;
//}