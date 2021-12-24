#include "CommodityManage.h"
#include "Commodity.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
CommodityManage::CommodityManage()
	:CommodityManage(100) {}
CommodityManage::CommodityManage(int s)
	: maxSize(s), size(0) {
	pCommodities = new Commodity[maxSize];
}
Commodity* CommodityManage::findCommodityById(int id)const {
	for (int i = 0; i < size; ++i)
		if (pCommodities[i].getId() == id)
			return pCommodities + i;
	return nullptr;
}
void CommodityManage::addCommodity(const Commodity& c) {
	if (size == maxSize) {
		reAllocMemory();
	}
	Commodity* pCommodity = findCommodityById(c.getId());
	if (pCommodity != nullptr) {
		cout << "���Ϊ" << c.getId() << "����Ʒ�Ѿ�����!�ۼ�������\n";
		pCommodity->setNum(pCommodity->getNum() + c.getNum());
		return;
	}
	pCommodities[size] = c;
	size++;
}
void CommodityManage::removeCommodity(int id) {
	Commodity* pCommodity = findCommodityById(id);
	if (pCommodity == nullptr) {
		cout << "���Ϊ" << id << "����Ʒ������!\n";
		return;
	}
	Commodity* pNext;
	size--;
	while (pCommodity < pCommodities + size) {//�������Ʒ��ǰ�ƶ�
		pNext = pCommodity + 1;
		*pCommodity = *pNext;
		pCommodity++;
	}
}
void CommodityManage::viewCommodity(int id)const {
	Commodity* pCommodity = findCommodityById(id);
	if (pCommodity == nullptr) {
		cout << "���Ϊ" << id << "����Ʒ������!\n";
		return;
	}
	pCommodity->output();
}
void CommodityManage::viewAllCommodities()const {
	cout << "��Ʒ����:" << size << endl;
	for (int i = 0; i < size; ++i)
		pCommodities[i].output();
}
void CommodityManage::checkOut()const {
	double totalPrice = 0;
	int totalNum = 0;
	cout << "��Ʒ����: " << size << endl;
	cout << " ��Ʒ����\t\t" << "�۸�\t" << "����\t" << "�ۿ�\t" << "�ܼ�\n";
	for (int i = 0; i < size; ++i) {
		double price = (pCommodities + i)->getNetPrice();
		cout << " " << pCommodities[i].getName() << "\t";
		cout << pCommodities[i].getPrice() << "\t"
			<< pCommodities[i].getNum() << "\t"
			<< pCommodities[i].getDiscount() << "\t"
			<< price << endl;
		totalPrice += price;
		totalNum += pCommodities[i].getNum();
	}
	cout << "��������Ʒ�ܼ���: " << totalNum << "\n";
	cout << "�����������ܼ�: " << totalPrice << endl;
}
void CommodityManage::reAllocMemory() {
	maxSize *= 2;
	int i;
	Commodity* temp = pCommodities;
	pCommodities = new Commodity[maxSize];
	for (i = 0; i < size; ++i)
		pCommodities[i] = temp[i];
	delete[] temp;
}
void CommodityManage::saveData(string filename) {
	ofstream out(filename);
	if (out) {
		out << maxSize << endl;
		out << size << endl;
		out << Commodity::getNextId() << endl;
		for (int i = 0; i < size; ++i) {
			out << pCommodities[i].getId() << endl;
			out << pCommodities[i].getName() << endl;
			out << pCommodities[i].getPrice() << " "
				<< pCommodities[i].getNum() << " "
				<< pCommodities[i].getDiscount() << endl;
		}
	}
}
void CommodityManage::readData(string filename) {
	ifstream in(filename);
	if (in) {
		int fileMax, fileSize;
		long nextId;
		in >> fileMax >> fileSize >> nextId;
		Commodity::setNextId(nextId);
		long id;
		string name, buf;
		double price, discount;
		int num;
		for (int i = 0; i < fileSize; ++i) {
			in >> id;
			getline(in, buf); //��ȡ id ������Ļس�Ҫ���� buf ��
			getline(in, name);
			in >> price >> num >> discount;
			addCommodity(Commodity(id, name, price, num, discount));
		}
	}
}