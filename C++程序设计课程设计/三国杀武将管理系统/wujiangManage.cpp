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
	cout << "请选择添加方式:" << endl;
	cout << "1)按武将编号添加" << endl;
	cout << "2)按武将姓名添加" << endl;
	char c;
	cin >> c;
	Wujiang* pWujiang = NULL;
	if (c == '1')
		pWujiang = findWujiangById(p->getId());
	else if (c == '2')
		pWujiang = findWujiangByName(p->getName());
	if (pWujiang != nullptr) {
		if (c == '1')
			cout << "编号为" << p->getId() << "的武将已经存在!无效添加\n";
		else if (c == '2')
			cout << "姓名为" << p->getName() << "的武将已经存在!无效添加\n";
		return;
	}
	pWujiangs.push_back(p);
	sortWujiangs(); //添加商品后根据当前规则重新排序
}
void WujiangManage::removeWujiang(int id) {
	Wujiang* pWujiang = const_cast<Wujiang * >(findWujiangById(id));
	if (pWujiang == nullptr) {
		cout << "编号为" << id << "的武将不存在!\n";
		return;
	}
	delete pWujiang;
	pWujiangs.erase(getIterator(pWujiang));
}
void WujiangManage::removeWujiang(string name) {
	Wujiang* pWujiang = findWujiangByName(name);
	if (pWujiang == nullptr) {
		cout << "武将姓名为" << name << "的武将不存在!\n";
		return;
	}
	delete pWujiang;
	pWujiangs.erase(getIterator(pWujiang));
}
void WujiangManage::viewWujiang(int id)const {
	const Wujiang* pWujiang = findWujiangById(id);
	if (pWujiang == nullptr) {
		cout << "编号为" << id << "的武将不存在!\n";
		return;
	}
	pWujiang->output();
}
void WujiangManage::viewWujiang(string name)const {
	const Wujiang* pWujiang = findWujiangByName(name);
	if (pWujiang == nullptr) {
		cout << "武将名称为" << name << "的武将不存在!\n";
		return;
	}
	pWujiang->output();
}
void WujiangManage::viewAllWujiangs()const {
	cout << "武将数量:" << pWujiangs.size() << endl;
	if (pWujiangs.size() == 0)
		return;
	cout << "指定排序方式(0-武将编号,1-武将姓名,2-武将血量，3-武将强度):";
	int type;
	cin >> type;
	const_cast<WujiangManage*>(this)->sortWujiangByType(type);

	for (auto e : pWujiangs)
		e->output();
}
void WujiangManage::modifyWujiangInfo(int id) {
	Wujiang* pWujiang = const_cast<Wujiang*>(findWujiangById(id));
	if (pWujiang == nullptr) {
		cout << "编号为" << id << "的武将不存在!\n";
		return;
	}
	pWujiang->modifyInfo();
}
void WujiangManage::sortWujiangs() {
	switch (sortType) {
	case 0: //根据编号排序
		sort(pWujiangs.begin(), pWujiangs.end(),
			[=](Wujiang* p1, Wujiang* p2) {
				return p1->getId() < p2->getId(); });
		break;
	case 1: //根据武将姓名排序
		sort(pWujiangs.begin(), pWujiangs.end(),
			[=](Wujiang* p1, Wujiang* p2) {
				if (p1->getName() != p2->getName())return p1->getName() < p2->getName();
				else return p1->getId() < p2->getId(); });
		break;
	case 2: //根据武将血量排序
		sort(pWujiangs.begin(), pWujiangs.end(),
			[=](Wujiang* p1, Wujiang* p2) {
				return p1->getHp() < p2->getHp(); });
		break;
	case 3://根据武将强度排序
		sort(pWujiangs.begin(), pWujiangs.end(),
			[=](Wujiang* p1, Wujiang* p2) {
				return p1->getLevel() < p2->getLevel(); });
		break;
	}
}
void WujiangManage::sortWujiangByType(int type) {
	if (type == sortType) //已经按指定规则排序，直接返回
		return;
	sortType = type;
	sortWujiangs();
}
void WujiangManage::startWar(Wujiang *j1,Wujiang* j2)const
{
	cout << "武将" << j1->getName() << "与" <<"武将" <<j2->getName()<<" 1v1！" << endl;
	Normalwar war(j1, j2);
	bool result = war.getResult();
	if (result) {
		cout << "武将" << j1->getName() << "获胜了" << endl;
	}
	else cout << "武将" << j2->getName() << "获胜了" << endl;

}