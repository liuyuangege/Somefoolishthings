#include <iostream>
#include "SecondhandCommodity.h"
using namespace std;
#include <sstream>
int SecondhandCommodity::getType()const {
	return 2; //2 ��ʾ������Ʒ
}
string SecondhandCommodity::getInfo()const {
	ostringstream ostr;
	ostr << getType() << " "; //��������ͱ���
	ostr << Commodity::getInfo(); //����������Ϣ
	ostr << discount << " " << zhejiu << endl; //���������Ϣ
	return ostr.str();
}

SecondhandCommodity::SecondhandCommodity(long id, std::string name,
	double p, int n, double d, double t)
	:Commodity(id, name, p, n), discount(d), zhejiu(t) {}
SecondhandCommodity::SecondhandCommodity(std::string name, double p,
	int n, double d, double t)
	: Commodity(name, p, n), discount(d), zhejiu(t) {}
double SecondhandCommodity::getNetPrice()const {
	return Commodity::getNetPrice() * discount *zhejiu;
}
void SecondhandCommodity::output()const {
	Commodity::output();
	cout << " ��Ʒ�ܼ�:" << getNetPrice() << " (�۸�:"
		<< getPrice() << ", ����:" << getNum() << ", �ۿ�:"
		<< discount << ", �۾ɳ̶�:" << zhejiu << " )\n";
}
void SecondhandCommodity::modifyInfo()
{
	cout << "��ѡ��Ҫ�޸ĵ���Ϣ��" << endl;
	cout << "�޸ļ۸�(1" << endl;
	cout << "�޸�����(2" << endl;
	cout << "�޸��ۿ�(3" << endl;
	cout << "�޸��۾ɳ̶�(4" << endl;
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
		cout << "�������۾ɳ̶�:";
		double zhejiu;
		cin >> zhejiu;
		setZhejiu(zhejiu);
		cout << "�޸ĳɹ�!" << endl;
	}
	else
	{
		cout << "������󣬷�����ҳ" << endl;
		return;
	}
}