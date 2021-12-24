#include <iostream>
#include "SpecialOffer.h"
using namespace std;
#include <sstream>
int SpecialOffer::getType()const {
	return 3; //3 表示特价商品
}
string SpecialOffer::getInfo()const {
	ostringstream ostr;
	ostr << getType() << " "; //先输出类型编码
	ostr << Commodity::getInfo(); //输出基类的信息
	ostr << specialdiscount << endl; //输出子类信息
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
	cout << "商品特价" << specialdiscount << ' ' << "商品数量" << getNum()
		<< ' ' << "商品净价" << getNetPrice() << endl;
}
void SpecialOffer::modifyInfo()
{
	cout << "请选择要修改的信息项" << endl;
	cout << "修改价格(1" << endl;
	cout << "修改数量(2" << endl;
	cout << "修改特价(3" << endl;
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
		double specialdiscount;
		cin >> specialdiscount;
		setSpecialDiscount(specialdiscount);
		cout << "修改成功!" << endl;
	}
	else
	{
		cout << "输入错误，返回主页" << endl;
		return;
	}
}