#include <iostream>
#include "normalcommodity.h"
using namespace std;
#include <sstream>
int NormalCommodity::getType()const {
	return 0; //0 ��ʾ��ͨ��Ʒ
}
string NormalCommodity::getInfo()const {
	ostringstream ostr;
	ostr << getType() << " "; //��������ͱ���
	ostr << Commodity::getInfo(); //����������Ϣ
	ostr << discount << endl; //���������Ϣ
	return ostr.str();
}
NormalCommodity::NormalCommodity(long id, std::string name,
	double p, int n, double d)
	:Commodity(id, name, p, n), discount(d) {}
NormalCommodity::NormalCommodity(std::string name, double p,
	int n, double d)
	: Commodity(name, p, n), discount(d) {}
double NormalCommodity::getNetPrice()const {
	return Commodity::getNetPrice() * discount;
}
void NormalCommodity::output()const {
	Commodity::output();
	cout << " ��Ʒ�ܼ�:" << getNetPrice() << " (�۸�:"
		<< getPrice() << ", ����:" << getNum() << ", �ۿ�:"
		<< discount << " )\n";
}
void NormalCommodity::modifyInfo()
{
	cout << "��ѡ��Ҫ�޸ĵ���Ϣ��" << endl;
	cout << "�޸ļ۸�(1" << endl;
	cout << "�޸�����(2" << endl;
	cout << "�޸��ۿ�(3" << endl;
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
	else
	{
		cout << "������󣬷�����ҳ" << endl;
		return;
	}
}