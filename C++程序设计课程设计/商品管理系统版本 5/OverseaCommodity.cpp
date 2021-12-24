#include <iostream>
#include "overseacommodity.h"
using namespace std;
#include <sstream>
int OverseaCommodity::getType()const {
	return 1; //1 表示海外购商品
}
string OverseaCommodity::getInfo()const {
	ostringstream ostr;
	ostr << getType() << " "; //先输出类型编码
	ostr << Commodity::getInfo(); //输出基类的信息
	ostr << discount << " " << tariff << endl; //输出子类信息
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
	cout << " 商品总价:" << getNetPrice() << " (价格:"
		<< getPrice() << ", 数量:" << getNum() << ", 折扣:"
		<< discount << ", 关税:" << tariff << " )\n";
}
void OverseaCommodity::modifyInfo()
{
	cout << "请选择要修改的信息项" << endl;
	cout << "修改价格(1" << endl;
	cout << "修改数量(2" << endl;
	cout << "修改折扣(3" << endl;
	cout << "修改关税(4" << endl;
	char c;
	cin >> c;
	if (c == '1')
	{
		cout << "请输入价格:";
		double price;
		cin >> price;
		setPrice(price);
		cout << "修改成功!" << endl;
	}
	else if (c == '2')
	{
		cout << "请输入数量:";
		int num;
		cin >> num;
		setNum(num);
		cout << "修改成功!" << endl;
	}
	else if (c == '3')
	{
		cout << "请输入折扣:";
		double discount;
		cin >> discount;
		setDiscount(discount);
		cout << "修改成功!" << endl;
	}
	else if (c == '4')
	{
		cout << "请输入关税:";
		double tariff;
		cin >> tariff;
		setTariff(tariff);
		cout << "修改成功!" << endl;
	}
	else
	{
		cout << "输入错误，返回主页" << endl;
		return;
	}
}