#include <iostream>
#include "overseacommodity.h"
using namespace std;
#include <sstream>
int OverseaCommodity::getType()const {
	return 1; //1 ��ʾ���⹺��Ʒ
}
string OverseaCommodity::getInfo()const {
	ostringstream ostr;
	ostr << getType() << " "; //��������ͱ���
	ostr << Commodity::getInfo(); //����������Ϣ
	ostr << discount << " " << tariff << endl; //���������Ϣ
	return ostr.str();
}

OverseaCommodity::OverseaCommodity(long id, std::string name,
	double p, int n, double d, double t)
	:Commodity(id, name, p, n), discount(d), tariff(t) {}
OverseaCommodity::OverseaCommodity(std::string name, double p,
	int n, double d, double t)
	: Commodity(name, p, n), discount(d), tariff(t) {}
double OverseaCommodity::getNetPrice()const {
	return Commodity::getNetPrice() * discount + tariff;
}
void OverseaCommodity::output()const {
	Commodity::output();
	cout << " ��Ʒ�ܼ�:" << getNetPrice() << " (�۸�:"
		<< getPrice() << ", ����:" << getNum() << ", �ۿ�:"
		<< discount << ", ��˰:" << tariff << " )\n";
}
void OverseaCommodity::modifyInfo()
{
	cout << "��ѡ��Ҫ�޸ĵ���Ϣ��" << endl;
	cout << "�޸ļ۸�(1" << endl;
	cout << "�޸�����(2" << endl;
	cout << "�޸��ۿ�(3" << endl;
	cout << "�޸Ĺ�˰(4" << endl;
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
	else if (c == '3')
	{
		cout << "�������ۿ�:";
		double discount;
		cin >> discount;
		setDiscount(discount);
		cout << "�޸ĳɹ�!" << endl;
	}
	else if (c == '4')
	{
		cout << "�������˰:";
		double tariff;
		cin >> tariff;
		setTariff(tariff);
		cout << "�޸ĳɹ�!" << endl;
	}
	else
	{
		cout << "������󣬷�����ҳ" << endl;
		return;
	}
}