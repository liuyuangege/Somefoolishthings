#include "wujiangmanage.h"
#include "wujiang.h"
#include "normalwar.h"
#include<iostream>
#include<string>
using namespace std;
WujiangManage::~WujiangManage() {
	for (auto e : pWujiangs)
		delete e;
}
Wujiang* WujiangManage::findWujiangById(int id) {
	vector<Wujiang*>::iterator it = find_if(pWujiangs.begin(),
		pWujiangs.end(), [=](Wujiang* p) {return p->getId() == id; });
	if (it != pWujiangs.end())
		return *it;
	return nullptr;
}
Wujiang* WujiangManage::findWujiangByName(string name) {
	vector<Wujiang*>::iterator it = find_if(pWujiangs.begin(),
		pWujiangs.end(), [=](Wujiang* p) {return p->getName() == name; });
	if (it != pWujiangs.end())
		return *it;
	return nullptr;
}
const Wujiang* WujiangManage::findWujiangById(int id)const {
	vector<Wujiang*>::const_iterator it = find_if(pWujiangs.begin(),
		pWujiangs.end(), [=](const Wujiang* p) {return p->getId() == id; });
	if (it != pWujiangs.end())
		return *it;
	return nullptr;
}
const Wujiang* WujiangManage::findWujiangByName(string name)const {
	vector<Wujiang*>::const_iterator it = find_if(pWujiangs.begin(),
		pWujiangs.end(), [=](const Wujiang* p) {return p->getName() == name; });
	if (it != pWujiangs.end())
		return *it;
	return nullptr;
}
vector<Wujiang*>::iterator WujiangManage::getIterator(Wujiang* p) {
	for (auto it = pWujiangs.begin(); it != pWujiangs.end(); ++it)
		if (*it == p)
			return it;
	return pWujiangs.end();
}
void WujiangManage::addWujiang(Wujiang* p) {
	cout << "��ѡ����ӷ�ʽ:" << endl;
	cout << "1)���佫������" << endl;
	cout << "2)���佫�������" << endl;
	char c;
	cin >> c;
	Wujiang* pWujiang = NULL;
	if (c == '1')
		pWujiang = findWujiangById(p->getId());
	else if (c == '2')
		pWujiang = findWujiangByName(p->getName());
	if (pWujiang != nullptr) {
		if (c == '1')
			cout << "���Ϊ" << p->getId() << "���佫�Ѿ�����!��Ч���\n";
		else if (c == '2')
			cout << "����Ϊ" << p->getName() << "���佫�Ѿ�����!��Ч���\n";
		return;
	}
	pWujiangs.push_back(p);
	sortWujiangs(); //�����Ʒ����ݵ�ǰ������������
}
void WujiangManage::removeWujiang(int id) {
	Wujiang* pWujiang = const_cast<Wujiang * >(findWujiangById(id));
	if (pWujiang == nullptr) {
		cout << "���Ϊ" << id << "���佫������!\n";
		return;
	}
	delete pWujiang;
	pWujiangs.erase(getIterator(pWujiang));
}
void WujiangManage::removeWujiang(string name) {
	Wujiang* pWujiang = findWujiangByName(name);
	if (pWujiang == nullptr) {
		cout << "�佫����Ϊ" << name << "���佫������!\n";
		return;
	}
	delete pWujiang;
	pWujiangs.erase(getIterator(pWujiang));
}
void WujiangManage::viewWujiang(int id)const {
	const Wujiang* pWujiang = findWujiangById(id);
	if (pWujiang == nullptr) {
		cout << "���Ϊ" << id << "���佫������!\n";
		return;
	}
	pWujiang->output();
}
void WujiangManage::viewWujiang(string name)const {
	const Wujiang* pWujiang = findWujiangByName(name);
	if (pWujiang == nullptr) {
		cout << "�佫����Ϊ" << name << "���佫������!\n";
		return;
	}
	pWujiang->output();
}
void WujiangManage::viewAllWujiangs()const {
	cout << "�佫����:" << pWujiangs.size() << endl;
	if (pWujiangs.size() == 0)
		return;
	cout << "ָ������ʽ(0-�佫���,1-�佫����,2-�佫Ѫ����3-�佫ǿ��):";
	int type;
	cin >> type;
	const_cast<WujiangManage*>(this)->sortWujiangByType(type);

	for (auto e : pWujiangs)
		e->output();
}
void WujiangManage::modifyWujiangInfo(int id) {
	Wujiang* pWujiang = const_cast<Wujiang*>(findWujiangById(id));
	if (pWujiang == nullptr) {
		cout << "���Ϊ" << id << "���佫������!\n";
		return;
	}
	pWujiang->modifyInfo();
}
void WujiangManage::sortWujiangs() {
	switch (sortType) {
	case 0: //���ݱ������
		sort(pWujiangs.begin(), pWujiangs.end(),
			[=](Wujiang* p1, Wujiang* p2) {
				return p1->getId() < p2->getId(); });
		break;
	case 1: //�����佫��������
		sort(pWujiangs.begin(), pWujiangs.end(),
			[=](Wujiang* p1, Wujiang* p2) {
				if (p1->getName() != p2->getName())return p1->getName() < p2->getName();
				else return p1->getId() < p2->getId(); });
		break;
	case 2: //�����佫Ѫ������
		sort(pWujiangs.begin(), pWujiangs.end(),
			[=](Wujiang* p1, Wujiang* p2) {
				return p1->getHp() < p2->getHp(); });
		break;
	case 3://�����佫ǿ������
		sort(pWujiangs.begin(), pWujiangs.end(),
			[=](Wujiang* p1, Wujiang* p2) {
				return p1->getLevel() < p2->getLevel(); });
		break;
	}
}
void WujiangManage::sortWujiangByType(int type) {
	if (type == sortType) //�Ѿ���ָ����������ֱ�ӷ���
		return;
	sortType = type;
	sortWujiangs();
}
void WujiangManage::startWar(Wujiang *j1,Wujiang* j2)const
{
	cout << "�佫" << j1->getName() << "��" <<"�佫" <<j2->getName()<<" 1v1��" << endl;
	Normalwar war(j1, j2);
	bool result = war.getResult();
	if (result) {
		cout << "�佫" << j1->getName() << "��ʤ��" << endl;
	}
	else cout << "�佫" << j2->getName() << "��ʤ��" << endl;

}