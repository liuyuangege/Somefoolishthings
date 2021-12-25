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
	cout << "�佫���:" << id << endl;
	cout << "�佫����:" << country << endl;
	cout << "�佫����:" << name << endl;
	cout << "�佫Ѫ��:" << hp << endl;
	cout << "�佫ǿ��:" << level << endl;
}
void Wujiang::modifyInfo() {
	cout << "��ѡ��Ҫ�޸ĵ���Ϣ��" << endl;
	cout << "�޸Ĺ���(1" << endl;
	cout << "�޸�����(2" << endl;
	cout << "�޸�Ѫ��(3" << endl;
	cout << "�޸�ǿ��(4" << endl;
	char c;
	cin >> c;
	if (c == '1')
	{
		cout << "���������:";
		string country;
		cin >> country;
		setCountry(country);
		cout << "�޸ĳɹ�!" << endl;
	}
	else if (c == '2')
	{
		cout << "����������:";
		string name;
		cin >> name;
		setName(name);
		cout << "�޸ĳɹ�!" << endl;
	}
	else if (c == '3')
	{
		cout << "������Ѫ��" << endl;
		double hp;
		cin >> hp;
		setHp(hp);
		cout << "�޸ĳɹ���" << endl;
	}
	else if (c == '4')
	{
		cout << "������ǿ��" << endl;
		int level;
		cin >> level;
		setLevel(level);
		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "������󣬷�����ҳ" << endl;
		return;
	}
}