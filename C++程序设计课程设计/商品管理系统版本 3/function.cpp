#include <iostream>
#include "function.h"
using namespace std;
char menu() {
	cout << " 0) �˳�ϵͳ\n";
	cout << " 1) �����������Ʒ\n";
	cout << " 2) �ӹ������Ƴ���Ʒ\n";
	cout << " 3) �鿴ָ����Ʒ\n";
	cout << " 4) �鿴������Ʒ\n";
	cout << " 5) ����\n";
	cout << "�����빦��ѡ��:";
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