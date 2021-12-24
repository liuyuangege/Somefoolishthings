#include <iostream>
#include "commodity.h"
#include <sstream>
using namespace std;
long Commodity::nextId = 100;
string Commodity::getInfo()const {
	ostringstream ostr;
	ostr << getId() << endl;
	ostr << getName() << endl;
		ostr << price << " " << num << " ";
	return ostr.str();
}
Commodity::Commodity(string n, double p, int nu)
	:Commodity(autoNextId(), n, p, nu) {}
Commodity::Commodity(long i, std::string n, double p, int nu)
	: id(i), name(n), price(p), num(nu) {}
double Commodity::getNetPrice()const {
	return price * num;
}
void Commodity::output()const {
	cout << " ��Ʒ���(id):" << id << endl;
	cout << " ��Ʒ����:" << name << endl;
}
void Commodity::modifyInfo()
{
	cout << "��ѡ��Ҫ�޸ĵ���Ϣ��" << endl;
	cout << "�޸ļ۸�(1" << endl;
	cout << "�޸�����(2" << endl;
	char c;
	cin >> c;
	if (c == '1')
	{
		cout << "������۸�:";
		double price;
		cin >> price;
		setPrice(price);
		cout << "�޸ĳɹ�!" << endl;
	}
	else if (c == '2')
	{
		cout << "����������:";
		int num;
		cin >> num;
		setNum(num);
		cout << "�޸ĳɹ�!" << endl;
	}
	else
	{
		cout << "������󣬷�����ҳ" << endl;
		return;
	}
}
