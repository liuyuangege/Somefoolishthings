#include "CommodityManage.h"
#include "Commodity.h"
#include "normalcommodity.h"
#include "overseacommodity.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
CommodityManage::~CommodityManage() {
	for (auto e : pCommodities)
		delete e;
}
Commodity* CommodityManage::findCommodityById(int id) {
	vector<Commodity*>::iterator it = find_if(pCommodities.begin(),
		pCommodities.end(), [=](Commodity* p) {return p->getId() == id; });
	if (it != pCommodities.end())
		return *it;
	return nullptr;
}
Commodity* CommodityManage::findCommodityByName(string name) {
	vector<Commodity*>::iterator it = find_if(pCommodities.begin(),
		pCommodities.end(), [=](Commodity* p) {return p->getName() == name; });
	if (it != pCommodities.end())
		return *it;
	return nullptr;
}
const Commodity* CommodityManage::findCommodityById(int id)const {
	vector<Commodity*>::const_iterator it = find_if(pCommodities.begin(),
		pCommodities.end(), [=](const Commodity* p) {return p->getId() == id; });
	if (it != pCommodities.end())
		return *it;
	return nullptr;
}
const Commodity* CommodityManage::findCommodityByName(string name)const {
	vector<Commodity*>::const_iterator it = find_if(pCommodities.begin(),
		pCommodities.end(), [=](const Commodity* p) {return p->getName() == name; });
	if (it != pCommodities.end())
		return *it;
	return nullptr;
}
vector<Commodity*>::iterator CommodityManage::getIterator(Commodity* p) {
	for (auto it = pCommodities.begin(); it != pCommodities.end(); ++it)
		if (*it == p)
			return it;
	return pCommodities.end();
}
void CommodityManage::addCommodity(Commodity* p) {
	cout << "请选择查找方式:" << endl;
	cout << "1)按ID添加" << endl;
	cout << "2)按商品名称添加" << endl;
	char c;
	cin >> c;
	Commodity* pCommodity=NULL;
	if (c == '1')
		pCommodity = findCommodityById(p->getId());
	else if (c == '2')
		pCommodity = findCommodityByName(p->getName());
	if (pCommodity != nullptr) {
		if(c=='1')
		cout << "编号为" << p->getId() << "的商品已经存在!累加其数量\n";
		else if(c=='2')
		cout << "名称为" << p->getName() << "的商品已经存在!累加其数量\n";
		pCommodity->setNum(pCommodity->getNum() + p->getNum());
		return;
	}
	pCommodities.push_back(p);
	sortCommodities(); //添加商品后根据当前规则重新排序
}
void CommodityManage::removeCommodity(int id) {
	Commodity* pCommodity = findCommodityById(id);
	if (pCommodity == nullptr) {
		cout << "编号为" << id << "的商品不存在!\n";
		return;
	}
	delete pCommodity;
	pCommodities.erase(getIterator(pCommodity));
}
void CommodityManage::removeCommodity(string name) {
	Commodity* pCommodity = findCommodityByName(name);
	if (pCommodity == nullptr) {
		cout << "商品名称为" << name << "的商品不存在!\n";
		return;
	}
	delete pCommodity;
	pCommodities.erase(getIterator(pCommodity));
}
void CommodityManage::viewCommodity(int id)const {
	const Commodity* pCommodity = findCommodityById(id);
	if (pCommodity == nullptr) {
		cout << "编号为" << id << "的商品不存在!\n";
		return;
	}
	pCommodity->output();
}
void CommodityManage::viewCommodity(string name)const {
	const Commodity* pCommodity = findCommodityByName(name);
	if (pCommodity == nullptr) {
		cout << "商品名称为" << name << "的商品不存在!\n";
		return;
	}
	pCommodity->output();
}
void CommodityManage::viewAllCommodities()const {
	cout << "商品数量:" << pCommodities.size() << endl;
	if (pCommodities.size() == 0)
		return;
		cout << "指定排序方式(0-商品 id,1-商品名称,2-商品净价):";
	int type;
	cin >> type;
	const_cast<CommodityManage*>(this)->sortCommoditiesByType(type);

	for (auto e : pCommodities)
		e->output();
}
void CommodityManage::checkOut()const {
	double totalPrice = 0;
	int totalNum = 0;
	cout << "商品种类: " << pCommodities.size() << endl;
	cout << " 商品名称\t\t" << "价格\t" << "件数\t" << "折扣\t" << "总价\n";
	for (auto e : pCommodities) {
		double price = e->getNetPrice();
		cout << " " << e->getName() << "\t";
		cout << e->getPrice() << "\t"
			<< e->getNum() << "\t"
			<< price << endl;
		totalPrice += price;
		totalNum += e->getNum();
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
void CommodityManage::saveData(string filename) {
	ofstream out(filename);
	if (out) {
		out << pCommodities.size() << endl;
		out << Commodity::getNextId() << endl;
		for (auto e : pCommodities) {
			out << e->getInfo();
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
	sortCommodities();
}
void CommodityManage::sortCommodities() {
	switch (sortType) {
	case 0: //根据 id 排序
		sort(pCommodities.begin(), pCommodities.end(),
			[=](Commodity* p1, Commodity* p2) {
				return p1->getId() < p2->getId(); });
		break;
	case 1: //根据名称排序
		sort(pCommodities.begin(), pCommodities.end(),
			[=](Commodity* p1, Commodity* p2) {
				if (p1->getName() != p2->getName())return p1->getName() < p2->getName();
				else return p1->getId() < p2->getId(); });
		break;
	case 2: //根据净价排序
		sort(pCommodities.begin(), pCommodities.end(),
			[=](Commodity* p1, Commodity* p2) {
				return p1->getNetPrice() < p2->getNetPrice(); });
		break;
	case 3://根据购买数量排序
		sort(pCommodities.begin(), pCommodities.end(),
			[=](Commodity* p1, Commodity* p2) {
				return p1->getNum() < p2->getNum(); });
		break;
	case 4://根据商品价格
		sort(pCommodities.begin(), pCommodities.end(),
			[=](Commodity* p1, Commodity* p2) {
				return p1->getPrice() < p2->getPrice(); });
		break;
	}
}
void CommodityManage::sortCommoditiesByType(int type) {
	if (type == sortType) //已经按指定规则排序，直接返回
		return;
	sortType = type;
	sortCommodities();
}