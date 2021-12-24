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
	cout << " 商品编号(id):" << id << endl;
	cout << " 商品名称:" << name << endl;
}
void Commodity::modifyInfo()
{
	cout << "请选择要修改的信息项" << endl;
	cout << "修改价格(1" << endl;
	cout << "修改数量(2" << endl;
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
	else
	{
		cout << "输入错误，返回主页" << endl;
		return;
	}
}
