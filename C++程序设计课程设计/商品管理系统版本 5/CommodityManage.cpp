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
	cout << "��ѡ����ҷ�ʽ:" << endl;
	cout << "1)��ID���" << endl;
	cout << "2)����Ʒ�������" << endl;
	char c;
	cin >> c;
	Commodity* pCommodity=NULL;
	if (c == '1')
		pCommodity = findCommodityById(p->getId());
	else if (c == '2')
		pCommodity = findCommodityByName(p->getName());
	if (pCommodity != nullptr) {
		if(c=='1')
		cout << "���Ϊ" << p->getId() << "����Ʒ�Ѿ�����!�ۼ�������\n";
		else if(c=='2')
		cout << "����Ϊ" << p->getName() << "����Ʒ�Ѿ�����!�ۼ�������\n";
		pCommodity->setNum(pCommodity->getNum() + p->getNum());
		return;
	}
	pCommodities.push_back(p);
	sortCommodities(); //�����Ʒ����ݵ�ǰ������������
}
void CommodityManage::removeCommodity(int id) {
	Commodity* pCommodity = findCommodityById(id);
	if (pCommodity == nullptr) {
		cout << "���Ϊ" << id << "����Ʒ������!\n";
		return;
	}
	delete pCommodity;
	pCommodities.erase(getIterator(pCommodity));
}
void CommodityManage::removeCommodity(string name) {
	Commodity* pCommodity = findCommodityByName(name);
	if (pCommodity == nullptr) {
		cout << "��Ʒ����Ϊ" << name << "����Ʒ������!\n";
		return;
	}
	delete pCommodity;
	pCommodities.erase(getIterator(pCommodity));
}
void CommodityManage::viewCommodity(int id)const {
	const Commodity* pCommodity = findCommodityById(id);
	if (pCommodity == nullptr) {
		cout << "���Ϊ" << id << "����Ʒ������!\n";
		return;
	}
	pCommodity->output();
}
void CommodityManage::viewCommodity(string name)const {
	const Commodity* pCommodity = findCommodityByName(name);
	if (pCommodity == nullptr) {
		cout << "��Ʒ����Ϊ" << name << "����Ʒ������!\n";
		return;
	}
	pCommodity->output();
}
void CommodityManage::viewAllCommodities()const {
	cout << "��Ʒ����:" << pCommodities.size() << endl;
	if (pCommodities.size() == 0)
		return;
		cout << "ָ������ʽ(0-��Ʒ id,1-��Ʒ����,2-��Ʒ����):";
	int type;
	cin >> type;
	const_cast<CommodityManage*>(this)->sortCommoditiesByType(type);

	for (auto e : pCommodities)
		e->output();
}
void CommodityManage::checkOut()const {
	double totalPrice = 0;
	int totalNum = 0;
	cout << "��Ʒ����: " << pCommodities.size() << endl;
	cout << " ��Ʒ����\t\t" << "�۸�\t" << "����\t" << "�ۿ�\t" << "�ܼ�\n";
	for (auto e : pCommodities) {
		double price = e->getNetPrice();
		cout << " " << e->getName() << "\t";
		cout << e->getPrice() << "\t"
			<< e->getNum() << "\t"
			<< price << endl;
		totalPrice += price;
		totalNum += e->getNum();
	}
	cout << "��������Ʒ�ܼ���: " << totalNum << "\n";
	cout << "�����������ܼ�: " << totalPrice << endl;
}
void CommodityManage::modifyCommodityInfo(int id) {
	Commodity* pCommodity = findCommodityById(id);
	if (pCommodity == nullptr) {
		cout << "���Ϊ" << id << "����Ʒ������!\n";
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
	case 0: //���� id ����
		sort(pCommodities.begin(), pCommodities.end(),
			[=](Commodity* p1, Commodity* p2) {
				return p1->getId() < p2->getId(); });
		break;
	case 1: //������������
		sort(pCommodities.begin(), pCommodities.end(),
			[=](Commodity* p1, Commodity* p2) {
				if (p1->getName() != p2->getName())return p1->getName() < p2->getName();
				else return p1->getId() < p2->getId(); });
		break;
	case 2: //���ݾ�������
		sort(pCommodities.begin(), pCommodities.end(),
			[=](Commodity* p1, Commodity* p2) {
				return p1->getNetPrice() < p2->getNetPrice(); });
		break;
	case 3://���ݹ�����������
		sort(pCommodities.begin(), pCommodities.end(),
			[=](Commodity* p1, Commodity* p2) {
				return p1->getNum() < p2->getNum(); });
		break;
	case 4://������Ʒ�۸�
		sort(pCommodities.begin(), pCommodities.end(),
			[=](Commodity* p1, Commodity* p2) {
				return p1->getPrice() < p2->getPrice(); });
		break;
	}
}
void CommodityManage::sortCommoditiesByType(int type) {
	if (type == sortType) //�Ѿ���ָ����������ֱ�ӷ���
		return;
	sortType = type;
	sortCommodities();
}