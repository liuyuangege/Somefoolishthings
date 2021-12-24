#include <iostream>
#include "header.h"
#include<fstream>
using namespace std;
char menu() {
	cout << " 0) �˳�ϵͳ\n";
	cout << " 1) �����������Ʒ\n";
	cout << " 2) �ӹ������Ƴ���Ʒ\n";
	cout << " 3) �鿴ָ����Ʒ\n";
	cout << " 4) �鿴������Ʒ\n";
	cout << " 5) ����\n";
	cout << "6)��ѡ�����������\n";
	cout << "�����빦��ѡ��:";
	char choice;
	cin >> choice;
	return choice;
}
void displayCommodities(CommodityInfo* pCommodities, int num) {
	int i;
	cout << "��Ʒ����: " << num << endl;
	for (i = 0; i < num; i++) {
		showCommodityInfo(&pCommodities[i]);
	}
	cout << endl;
}
void addCommodity(CommodityInfo*& pCommodities, int& num) {
	int id;
	cout << " ������Ʒ���(id): ";
	cin >> id;
	int pos =
		findCommodityById(pCommodities, num, id);
	CommodityInfo* pCommodity=pCommodities;
	if (pos != -1) {
		cout << "���Ϊ" << id << "����Ʒ�Ѿ�����!\n";
		cout << "���������ӵ���Ʒ����: ";
		int number;
		cin >> number;
		pCommodity=pCommodities+pos;
		pCommodity->num += number;
		return;
	}
	if (num == maxCommodityNum) {
		reAllocMemory(pCommodities, num);
	}
	pCommodity = &pCommodities[num];
	pCommodity->id = id;
	setCommodityInfo(pCommodity);
	num++;
	cout << "��Ʒ��ӳɹ�!\n\n";
}
void removeCommodity(CommodityInfo* pCommodities, int& num) {
	int id;
	cout << " ������Ʒ���(id): ";
	cin >> id;
	int pos =
		findCommodityById(pCommodities, num, id);
	CommodityInfo* pCommodity=pCommodities;
	if (pos == -1) {
		cout << "���Ϊ" << id << "����Ʒ������!\n\n";
		return;
	}
	pCommodity += pos;
	num--;
	CommodityInfo* pNext = pCommodity + 1;

	while (pCommodity < pCommodities + num) {
		pCommodity->id = pNext->id;
		pCommodity->name = pNext->name;
		pCommodity->price = pNext->price;
		pCommodity->num = pNext->num;
		pCommodity->discount = pNext->discount;
		pCommodity++;
		pNext++;
	}
	cout << "��Ʒ�Ƴ��ɹ�!\n\n";
}
void viewCommodity(CommodityInfo* pCommodities, int num) {
	int id;
	cout << " ������Ʒ�ı��(id): ";
	cin >> id;
	int pos =
		findCommodityById(pCommodities, num, id);
	CommodityInfo* pCommodity=pCommodities;
	if (pos == -1) {
		cout << "���Ϊ" << id << "����Ʒ������!\n\n";
		return;
	}
	pCommodity += pos;
	showCommodityInfo(pCommodity);
}
void checkOut(CommodityInfo* pCommodities, int num) {
	double totalPrice = 0;
	int totalNum = 0;
	cout << "��Ʒ����: " << num << endl;
	cout << " ��Ʒ����\t\t" << "�۸�\t" << "����\t" << "�ۿ�\t" << "�ܼ�\n";
	for (int i = 0; i < num; ++i) {
		double price = getCommodityPrice(pCommodities + i);
		cout << " " << pCommodities[i].name << "\t";
		cout << pCommodities[i].price << "\t"
			<< pCommodities[i].num << "\t"
			<< pCommodities[i].discount << "\t"
			<< price << endl;
		totalPrice += price;
		totalNum += pCommodities[i].num;
	}
	cout << "��������Ʒ�ܼ���: " << totalNum << "\n";
	cout << "�����������ܼ�: " << totalPrice << endl;
}
void readData(std::string filename) {
	ifstream in(filename);
	if (in) {
		in >> maxCommodityNum;
		pCommodities = new CommodityInfo[maxCommodityNum];
		in >> commodityNum;
		if (commodityNum > maxCommodityNum)
			commodityNum = maxCommodityNum;
		string buf;
		for (int i = 0; i < commodityNum; ++i) {
			in >> pCommodities[i].id;
			getline(in, buf);
			getline(in, pCommodities[i].name);
			in >> pCommodities[i].price >> pCommodities[i].num
				>> pCommodities[i].discount;
		}
	}
	else
		pCommodities = new CommodityInfo[maxCommodityNum];
}
void writeData(std::string filename) {
	ofstream out(filename);
	if (out) {
		out << maxCommodityNum << endl;
		out << commodityNum << endl;
		for (int i = 0; i < commodityNum; ++i) {
			out << pCommodities[i].id << endl;
			out << pCommodities[i].name << endl;
			out << pCommodities[i].price << " " << pCommodities[i].num
				<< " " << pCommodities[i].discount << endl;
		}
	}
}