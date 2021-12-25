#include<iostream>
#include"wujiang.h"
#include<sstream>
using namespace std;
long Wujiang::nextId = 1;
string Wujiang::getInfo()const {
	ostringstream ostr;
	ostr << getId() << endl;
	ostr << getCountry() << endl;
	ostr << getName() << endl;
	ostr << getHp() << endl;
	ostr << getLevel() << endl;
	return ostr.str();
}
Wujiang::Wujiang(long id, std::string country, std::string name, double hp, int level)
	:id(id), country(country), name(name), hp(hp), level(level) {}
Wujiang::Wujiang(std::string country, std::string name, double hp, int level)
	:Wujiang(autoNextId(),country,name,hp,level){}
void Wujiang::output()const {
	cout << "武将编号:" << id << endl;
	cout << "武将国籍:" << country << endl;
	cout << "武将姓名:" << name << endl;
	cout << "武将血量:" << hp << endl;
	cout << "武将强度:" << level << endl;
}
void Wujiang::modifyInfo() {
	cout << "请选择要修改的信息项" << endl;
	cout << "修改国籍(1" << endl;
	cout << "修改姓名(2" << endl;
	cout << "修改血量(3" << endl;
	cout << "修改强度(4" << endl;
	char c;
	cin >> c;
	if (c == '1')
	{
		cout << "请输入国籍:";
		string country;
		cin >> country;
		setCountry(country);
		cout << "修改成功!" << endl;
	}
	else if (c == '2')
	{
		cout << "请输入姓名:";
		string name;
		cin >> name;
		setName(name);
		cout << "修改成功!" << endl;
	}
	else if (c == '3')
	{
		cout << "请输入血量" << endl;
		double hp;
		cin >> hp;
		setHp(hp);
		cout << "修改成功！" << endl;
	}
	else if (c == '4')
	{
		cout << "请输入强度" << endl;
		int level;
		cin >> level;
		setLevel(level);
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "输入错误，返回主页" << endl;
		return;
	}
}