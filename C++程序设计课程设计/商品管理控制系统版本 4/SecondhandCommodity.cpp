#include <iostream>
#include "SecondhandCommodity.h"
using namespace std;
#include <sstream>
int SecondhandCommodity::getType()const {
	return 2; //2 表示二手商品
}
string SecondhandCommodity::getInfo()const {
	ostringstream ostr;
	ostr << getType() << " "; //先输出类型编码
	ostr << Commodity::getInfo(); //输出基类的信息
	ostr << discount << " " << zhejiu << endl; //输出子类信息
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
	cout << " 商品总价:" << getNetPrice() << " (价格:"
		<< getPrice() << ", 数量:" << getNum() << ", 折扣:"
		<< discount << ", 折旧程度:" << zhejiu << " )\n";
}
void SecondhandCommodity::modifyInfo()
{
	cout << "请选择要修改的信息项" << endl;
	cout << "修改价格(1" << endl;
	cout << "修改数量(2" << endl;
	cout << "修改折扣(3" << endl;
	cout << "修改折旧程度(4" << endl;
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
		cout << "请输入折旧程度:";
		double zhejiu;
		cin >> zhejiu;
		setZhejiu(zhejiu);
		cout << "修改成功!" << endl;
	}
	else
	{
		cout << "输入错误，返回主页" << endl;
		return;
	}
}