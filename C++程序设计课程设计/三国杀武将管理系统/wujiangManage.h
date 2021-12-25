#pragma once
#ifndef _wujiangManage_h
#define _wujiangManage_h
#include"wujiang.h"
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
class WujiangManage :public Wujiang{
public:
	WujiangManage() = default;
	~WujiangManage();
	WujiangManage(const WujiangManage& c) = delete;
	WujiangManage& operator=(const WujiangManage& c) = delete;
	void addWujiang(Wujiang* p);
	void removeWujiang(int id);
	void removeWujiang(string name);
	void viewWujiang(int id)const;
	void viewWujiang(string name)const;
	void viewAllWujiangs()const;
	void startWar(Wujiang* j1, Wujiang *j2)const;
	void modifyWujiangInfo(int id);
	Wujiang* findWujiangById(int id);
	Wujiang* findWujiangByName(string name);
	const Wujiang* findWujiangById(int id)const;
	const Wujiang* findWujiangByName(string name)const;
private:
	std::vector<Wujiang*> pWujiangs;
	std::vector<Wujiang*>::iterator getIterator(Wujiang* p);
	int sortType = 0; //记录当前排序类型
	void sortWujiangs();
	void sortWujiangByType(int type);
};
#endif // wujiangManage.h