#include "CommodityManage.h"
#include "Commodity.h"
#include "normalcommodity.h"
#include "overseacommodity.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
CommodityManage::CommodityManage()
	:CommodityManage(100) {}
CommodityManage::CommodityManage(int s)
	: maxSize(s), size(0) {
	pCommodities = new Commodity * [maxSize];
}
CommodityManage::~CommodityManage() {
	for (int i = 0; i < size; ++i)
		delete pCommodities[i];
	delete[] pCommodities;
	pCommodities = nullptr;
}
Commodity* CommodityManage::findCommodityById(int id)const {
	for (int i = 0; i < size; ++i)
		if (pCommodities[i]->getId() == id)
			return pCommodities[i];
	return nullptr;
}
void CommodityManage::addCommodity(Commodity* p) {
	if (size == maxSize) {
		reAllocMemory();
	}
	Commodity* pCommodity = findCommodityById(p->getId());
	if (pCommodity != nullptr) {
		cout << "编号为" << p->getId() << "的商品已经存在!累加其数量\n";
		pCommodity->setNum(pCommodity->getNum() + p->getNum());
		return;
	}
	pCommodities[size] = p;
	size++;
}
void CommodityManage::removeCommodity(int id) {
	Commodity* pCommodity = findCommodityById(id);
	if (pCommodity == nullptr) {
		cout << "编号为" << id << "的商品不存在!\n";
		return;
	}
	delete pCommodity;
	size--;
	Commodity** pos = pCommodities + size;
	while (*pos != pCommodity) {
		pos--;
	}
	while (pos < pCommodities + size) { //移动指针数组中的元素
		*pos = *(pos + 1);
		pos++;
	}
}
void CommodityManage::viewCommodity(int id)const {
	Commodity* pCommodity = findCommodityById(id);
	if (pCommodity == nullptr) {
		cout << "编号为" << id << "的商品不存在!\n";
		return;
	}
	pCommodity->output();
}
void CommodityManage::viewAllCommodities()const {
	cout << "商品种类:" << size << endl;
	for (int i = 0; i < size; ++i)
		pCommodities[i]->output();
}
void CommodityManage::checkOut()const {
	double totalPrice = 0;
	int totalNum = 0;
	cout << "商品种类: " << size << endl;
	cout << " 商品名称\t\t" << "价格\t" << "件数\t" << "折扣\t" << "总价\n";
	for (int i = 0; i < size; ++i) {
		double price = pCommodities[i]->getNetPrice();
		cout << " " << pCommodities[i]->getName() << "\t";
		cout << pCommodities[i]->getPrice() << "\t"
			<< pCommodities[i]->getNum() << "\t"
			<< price << endl;
		totalPrice += price;
		totalNum += pCommodities[i]->getNum();
	}
	cout << "购物篮商品总件数: " << totalNum << "\n";
	cout << "购物篮结算总价: " << totalPrice << endl;
}
void CommodityManage::modifyCommodityInfo(int id) {
	Commodity* pCommodity = findCommodityById(id);
	if (pCommodity == nullptr) {
		cout << "编号为" << id << "的商品不存在!\n";
		return;
	}
	pCommodity->modifyInfo();
}
void CommodityManage::reAllocMemory() {
	maxSize *= 2;
	int i;
	Commodity** temp = pCommodities;
	pCommodities = new Commodity * [maxSize];
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
			out << pCommodities[i]->getInfo();
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
		int type;
		long id;
		string name, buf;
		double price, discount;
		double tariff;
		int num;
		for (int i = 0; i < fileSize; ++i) {
			in >> type;
			in >> id;
			getline(in, buf);
			getline(in, name);
			in >> price >> num;
			if (type == 0) {
				in >> discount;
				addCommodity(new
					NormalCommodity(id, name, price, num, discount));
			}
			else if (type == 1) {
				in >> discount >> tariff;
				addCommodity(new
					OverseaCommodity(id, name, price, num, discount, tariff));
			}
		}
	}
}