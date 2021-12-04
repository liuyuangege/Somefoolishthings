//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include<functional>
//#include<fstream>
//using namespace std;
//class Student {
//private:
//	string name;
//	string specialty;//专业
//	long id;// 学号
//	double creditPoint; //学分积点
//public:
//	Student() = default;
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
//class StudentManage {
//public:
//	enum SortType {
//		BY_NAME, BY_ID,
//		BY_SPECIALTY, BY_CRDITPOINT
//	};
//	StudentManage() = default;
//	void addStudent();
//	void removeStudent();
//	void setSortType(SortType st);
//	void findStudent();
//	void loadData(string filename); //从文件中加载数据
//	void saveData(string filename); //将数据保存到磁盘文件中
//	int size()const { return students.size(); }
//	friend std::ostream& operator<<(std::ostream& out,
//		const StudentManage& sm);
//private:
//	vector<Student> students;
//	SortType sortType = BY_ID;
//};
//void StudentManage::addStudent()
//{
//	string n, s; long i; double c;
//	cin >> n >> s >> i >> c;
//	Student stu(n,s,i,c);
//	if (students.empty())
//	{
//		students.push_back(stu);
//		return;
//	}
//	for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it)
//	{
//		if (it->getId() == i)return;
//	}
//	students.push_back(stu);
//	int st;
//	cin >> st;
//	setSortType((SortType)st);
//}
//void StudentManage::removeStudent()
//{
//	int id,pos=0; bool judge = 0;
//	cin >> id;
//	for (auto e =students.begin();e!= students.end();++e)
//	{
//		pos++;
//		if (e->getId() == id)
//		{
//			judge = 1;
//			break;
//		}
//	}
//	if (judge)students.erase(students.begin() + pos - 1);
//}
//void StudentManage::findStudent()
//{
//	int id, pos = 0; bool judge = 0;
//	cin >> id;
//	for (auto e = students.begin(); e != students.end(); ++e)
//	{
//		pos++;
//		if (e->getId() == id)
//		{
//			judge = 1;
//			break;
//		}
//	}
//	if (judge)cout << "this is student " << pos << endl;
//	else cout << "there is not " << id << "in students" << endl;
//}
//ostream& operator<<(std::ostream& out,
//	const StudentManage& sm)
//{
//	for (auto e = sm.students.begin(); e != sm.students.end(); ++e)
//	{
//		out <<"姓名" << e->getName() << endl;
//		out << "学号" << e->getId() << endl;
//		out << "专业" << e->getSpecialty() << endl;
//		out << "学分绩点" << e->getCreditPoint() << endl;
//	}
//	return out;
//}
//void StudentManage:: setSortType(SortType st) {
//	function<bool(const Student&, const Student&)> f;
//	switch (st) {
//	case BY_ID: f = [](const Student& s1, const Student& s2)
//	{return s1.getName() < s2.getName(); }; break;
//	case BY_NAME:f = [](const Student& s1, const Student& s2)
//	{return s1.getId() < s2.getId(); }; break;
//	case BY_SPECIALTY:f = [](const Student& s1, const Student& s2)
//	{return s1.getSpecialty() < s2.getSpecialty(); }; break;
//	case BY_CRDITPOINT:f = [](const Student& s1, const Student& s2)
//	{return s1.getCreditPoint() < s2.getCreditPoint(); }; break;
//	}
//	sort(students.begin(), students.end(), f);
//}
//int main() {
//	StudentManage sm;
//	sm.loadData("d:\\students.txt"); //从文件中加载数据
//	if (sm.size() == 0) {
//		sm.addStudent();
//		sm.addStudent();
//		sm.addStudent();
//		sm.addStudent();
//	}
//	cout << "sort type(0-name,1-id,2-specialty,3-creditpoint):";
//	int choice;
//	cin >> choice;
//	sm.setSortType(static_cast<StudentManage::SortType>(choice));
//	cout << sm;
//	sm.findStudent();
//	sm.removeStudent();
//	cout << sm;
//	sm.saveData("d:\\students.txt"); //将数据保存到文件中
//	return 0;
//}
//void StudentManage::loadData(string filename)
//{
//	ifstream infile;
//	infile.open(filename);
//	if (!infile)
//	{
//		cout << "文件打开失败" << endl;
//		exit(0);
//	}
//	int num;
//	infile >> num;
//	string n;
//	string s;//专业
//	long i;// 学号
//	double c;
//	while (infile >> n >> i >> s >> c)
//	{
//		Student stu(n, s, i, c);
//		if (students.empty())
//		{
//			students.push_back(stu);
//			return;
//		}
//		for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it)
//		{
//			if (it->getId() == i)return;
//		}
//		students.push_back(stu);
//		int st;
//		cin >> st;
//		setSortType((SortType)st);
//	}
//	infile.close();
//}
//void StudentManage::saveData(string filename)
//{
//	ofstream outfile;
//	outfile.open(filename);
//	if (!outfile.good())
//	{
//		cout << "文件输出失败" << endl;
//		exit(0);
//	}
//	outfile << students.size();
//	outfile << endl;
//	for (auto it = students.begin(); it != students.end(); ++it)
//	{
//		outfile<< "Name:" << it->getName() << " Id:" << it->getId() << " Specialty:" << it->getSpecialty() << " CreditPoint:" << it->getCreditPoint()  << endl;
//	}
//	outfile.close();
//}