#include <iostream>
#include<string>
#include "function.h"
#include "normalcommodity.h"
#include "overseacommodity.h"
using namespace std;
char menu() {
	cout << " 0) �˳�ϵͳ\n";
	cout << " 1) �����������Ʒ\n";
	cout << " 2) �ӹ������Ƴ���Ʒ\n";
	cout << " 3) �鿴ָ����Ʒ\n";
	cout << " 4) �鿴������Ʒ\n";
	cout << " 5) ����\n";
	cout << "6)�޸���Ʒ��Ϣ\n";
	cout << "�����빦��ѡ��:";
	char choice;
	cin >> choice;
	return choice;
}
void doAddCommodity(CommodityManage& cm) {
	string name;
	double price, discount;
	double tariff, zhejiu, specialdiscount;
	int num, type;
	cout << "ѡ����Ʒ����(0-��ͨ��Ʒ��1-���⹺��Ʒ)";
	cin >> type;
	fflush(stdin);
	cout << "������Ʒ����:";
	cin.get();
	getline(cin, name);
	cout << "����۸����Ʒ����:";
	cin >> price >> num;
	if (type == 0) {
		cout << "������Ʒ�ۿ�:";
		cin >> discount;
		cm.addCommodity(new
			NormalCommodity(name, price, num, discount));
	}
	else if (type == 1) {
		cout << "������Ʒ�ۿۺ͹�˰:";
		cin >> discount >> tariff;
		cm.addCommodity(new
			OverseaCommodity(name, price, num, discount, tariff));
	}
}

void doRemoveCommodity(CommodityManage& cm) {
	int ch = chooseFindMethod();
	if (ch == 1) {
		long id;
		cout << "Input id:";
		cin >> id;
		cm.removeCommodity(id);
	}
	else if (ch == 2) {
		string name;
		cout << "Input name:";
		cin >> name;
		cm.removeCommodity(name);
	}
}
void doViewCommodity(const CommodityManage& cm) {
	int ch = chooseFindMethod();
	if (ch == 1) {
		long id;
		cout << "Input id:";
		cin >> id;
		cm.viewCommodity(id);
	}
	else if (ch == 2) {
		string name;
		cout << "Input name:";
		cin >> name;
		cm.viewCommodity(name);
	}
}
void doViewAllCommodity(const CommodityManage& cm) {
	cm.viewAllCommodities();
}
void doCheckout(const CommodityManage& cm) {
	cm.checkOut();
}
void doModifyCommodityInfo(CommodityManage& cm) {
	long id;
	cout << "Input id:";
	cin >> id;
	cm.modifyCommodityInfo(id);
}
int chooseFindMethod() {
	cout << "��ѡ����ҷ�ʽ:" << endl;
	cout << "1)��ID" << endl;
	cout << "2)����Ʒ����" << endl;
	char c;
	cin >> c;
	if (c == '1')return 1;
	else if (c == '2')return 2;
}