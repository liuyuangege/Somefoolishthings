#include <iostream>
#include "header.h"
using namespace std;
int main() {
	cout << "��ӭʹ�ù���������ϵͳ!\n";
	readData("commodity.dat");
	cout << " 0) �˳�ϵͳ\n";
	cout << " 1) �����������Ʒ\n";
	cout << " 2) �ӹ������Ƴ���Ʒ\n";
	cout << " 3) �鿴ָ����Ʒ\n";
	cout << " 4) �鿴������Ʒ\n";
	cout << " 5) ����\n";
	cout << "�����빦��ѡ��:";
	char choice;
	while (true) {
		choice = menu();
		if (choice == '0')
			break;
		switch (choice) {
		case '1':
			addCommodity(commodities, commodityNum);
			break;
		case '2':
			removeCommodity(commodities, commodityNum);
			break;
		case '3':
			viewCommodity(commodities, commodityNum);
			break;
		case '4':
			displayCommodities(commodities, commodityNum);
			break;
		case '5':
			checkOut(commodities, commodityNum);
			break;
		default:
			cout << "��Ч����! ������!\n";
			break;
		}
	}
	writeData("commodity.dat");
	cout << "�ټ�!\n";
	return 0;
}