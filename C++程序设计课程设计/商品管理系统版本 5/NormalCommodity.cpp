#include <iostream>
#include "normalcommodity.h"
using namespace std;
#include <sstream>
int NormalCommodity::getType()const {
	return 0; //0 表示普通商品
}
string NormalCommodity::getInfo()const {
	ostringstream ostr;
	ostr << getType() << " "; //先输出类型编码
	ostr << Commodity::getInfo(); //输出基类的信息
	ostr << discount << endl; //输出子类信息
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
	cout << " 商品总价:" << getNetPrice() << " (价格:"
		<< getPrice() << ", 数量:" << getNum() << ", 折扣:"
		<< discount << " )\n";
}
void NormalCommodity::modifyInfo()
{
	cout << "请选择要修改的信息项" << endl;
	cout << "修改价格(1" << endl;
	cout << "修改数量(2" << endl;
	cout << "修改折扣(3" << endl;
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
	else
	{
		cout << "输入错误，返回主页" << endl;
		return;
	}
}