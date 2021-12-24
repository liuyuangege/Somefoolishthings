#include <iostream>
#include "function.h"
using namespace std;
char menu() {
	cout << " 0) 退出系统\n";
	cout << " 1) 向购物篮添加商品\n";
	cout << " 2) 从购物篮移除商品\n";
	cout << " 3) 查看指定商品\n";
	cout << " 4) 查看所有商品\n";
	cout << " 5) 结算\n";
	cout << "请输入功能选项:";
	char choice;
	cin >> choice;
	return choice;
}
void doAddCommodity(CommodityManage& cm) {
	string name;
	double price, discount;
	int num;
	fflush(stdin);
	cout << "Input name:";
	getline(cin, name);
	cout << "Input price,num,discount:";
	cin >> price >> num >> discount;
	cm.addCommodity(Commodity(name, price, num, discount));
}
void doRemoveCommodity(CommodityManage& cm) {
	long id;
	cout << "Input id:";
	cin >> id;
	cm.removeCommodity(id);
}
void doViewCommodity(const CommodityManage& cm) {
	long id;
	cout << "Input id:";
	cin >> id;
	cm.viewCommodity(id);
}
void doViewAllCommodity(const CommodityManage& cm) {
	cm.viewAllCommodities();
}
void doCheckout(const CommodityManage& cm) {
	cm.checkOut();
}