#include <iostream>
#include "SpecialOffer.h"
using namespace std;
#include <sstream>
int SpecialOffer::getType()const {
	return 3; //3 ��ʾ�ؼ���Ʒ
}
string SpecialOffer::getInfo()const {
	ostringstream ostr;
	ostr << getType() << " "; //��������ͱ���
	ostr << Commodity::getInfo(); //����������Ϣ
	ostr << specialdiscount << endl; //���������Ϣ
	return ostr.str();
}

SpecialOffer::SpecialOffer(long id, std::string name,
	double p, int n, double d)
	:Commodity(id, name, p, n), specialdiscount(d) {}
SpecialOffer::SpecialOffer(std::string name, double p,
	int n, double d)
	: Commodity(name, p, n), specialdiscount(d) {}
double SpecialOffer::getNetPrice()const {
	return Commodity::getNum()*specialdiscount;
}
void SpecialOffer::output()const {
	Commodity::output();
	cout << "��Ʒ�ؼ�" << specialdiscount << ' ' << "��Ʒ����" << getNum()
		<< ' ' << "��Ʒ����" << getNetPrice() << endl;
}
void SpecialOffer::modifyInfo()
{
	cout << "��ѡ��Ҫ�޸ĵ���Ϣ��" << endl;
	cout << "�޸ļ۸�(1" << endl;
	cout << "�޸�����(2" << endl;
	cout << "�޸��ؼ�(3" << endl;
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
		double specialdiscount;
		cin >> specialdiscount;
		setSpecialDiscount(specialdiscount);
		cout << "�޸ĳɹ�!" << endl;
	}
	else
	{
		cout << "������󣬷�����ҳ" << endl;
		return;
	}
}