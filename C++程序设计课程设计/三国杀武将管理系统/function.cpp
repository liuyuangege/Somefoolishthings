#include <iostream>
#include<string>
#include "function.h"
#include "normalwar.h"
#include"wujiang.h"
using namespace std;
char menu() {
	cout << " 0) 退出系统\n";
	cout << " 1) 添加武将\n";
	cout << " 2) 移除武将\n";
	cout << " 3) 查看指定武将\n";
	cout << " 4) 查看所有武将\n";
	cout << "5)修改武将信息\n";
	cout << "6)开战！" << endl;
	cout << "请输入功能选项:";
	char choice;
	cin >> choice;
	return choice;
}
void doAddWujiang(WujiangManage& cm) {
	string name;
	string country;
	double hp;
	int level;
	cout << "请输入武将姓名和国籍";
	cin >> name >> country;
	cout << "请输入武将血量和强度";
	cin >> hp >> level;
	cm.addWujiang(new
		Wujiang(country,name,hp,level));
}

void doRemoveWujiang(WujiangManage& cm) {
	int ch = chooseFindMethod();
	if (ch == 1) {
		long id;
		cout << "Input id:";
		cin >> id;
		cm.removeWujiang(id);
	}
	else if (ch == 2) {
		string name;
		cout << "Input name:";
		cin >> name;
		cm.removeWujiang(name);
	}
}
void doViewWujiang(const WujiangManage& cm) {
	int ch = chooseFindMethod();
	if (ch == 1) {
		long id;
		cout << "Input id:";
		cin >> id;
		cm.viewWujiang(id);
	}
	else if (ch == 2) {
		string name;
		cout << "Input name:";
		cin >> name;
		cm.viewWujiang(name);
	}
}
void doViewAllWujiangs(const WujiangManage& cm) {
	cm.viewAllWujiangs();
}
void doModifyWujiangInfo(WujiangManage& cm) {
	long id;
	cout << "Input id:";
	cin >> id;
	cm.modifyWujiangInfo(id);
}
void doStartWar(WujiangManage& cm) {
	cout << "请选择两位武将" << endl;
	int t = 2;
	Wujiang* j1 =nullptr;
	Wujiang* j2 = nullptr;
		int ch = chooseFindMethod();
		if (ch == 1) {
			long id;
			cout << "请输入武将编号:";
			cin >> id;
			j1 = cm.findWujiangById(id);
			cout << "请输入武将编号:";
			cin >> id;
			j2 = cm.findWujiangById(id);
		}
		else if (ch == 2) {
			string name;
			cout << "请输入武将姓名:";
			cin >> name;
			j1 = cm.findWujiangByName(name);
			cout << "请输入武将姓名:";
			cin >> name;
			j2 = cm.findWujiangByName(name);
		}
	cm.startWar(j1,j2);
}
int chooseFindMethod() {
	cout << "请选择查找方式:" << endl;
	cout << "1)按武将编号" << endl;
	cout << "2)按武将名称" << endl;
	char c;
	cin >> c;
	if (c == '1')return 1;
	else if (c == '2')return 2;
}