#include <iostream>
#include<string>
#include "function.h"
#include "normalwar.h"
#include"wujiang.h"
using namespace std;
char menu() {
	cout << " 0) �˳�ϵͳ\n";
	cout << " 1) ����佫\n";
	cout << " 2) �Ƴ��佫\n";
	cout << " 3) �鿴ָ���佫\n";
	cout << " 4) �鿴�����佫\n";
	cout << "5)�޸��佫��Ϣ\n";
	cout << "6)��ս��" << endl;
	cout << "�����빦��ѡ��:";
	char choice;
	cin >> choice;
	return choice;
}
void doAddWujiang(WujiangManage& cm) {
	string name;
	string country;
	double hp;
	int level;
	cout << "�������佫�����͹���";
	cin >> name >> country;
	cout << "�������佫Ѫ����ǿ��";
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
	cout << "��ѡ����λ�佫" << endl;
	int t = 2;
	Wujiang* j1 =nullptr;
	Wujiang* j2 = nullptr;
		int ch = chooseFindMethod();
		if (ch == 1) {
			long id;
			cout << "�������佫���:";
			cin >> id;
			j1 = cm.findWujiangById(id);
			cout << "�������佫���:";
			cin >> id;
			j2 = cm.findWujiangById(id);
		}
		else if (ch == 2) {
			string name;
			cout << "�������佫����:";
			cin >> name;
			j1 = cm.findWujiangByName(name);
			cout << "�������佫����:";
			cin >> name;
			j2 = cm.findWujiangByName(name);
		}
	cm.startWar(j1,j2);
}
int chooseFindMethod() {
	cout << "��ѡ����ҷ�ʽ:" << endl;
	cout << "1)���佫���" << endl;
	cout << "2)���佫����" << endl;
	char c;
	cin >> c;
	if (c == '1')return 1;
	else if (c == '2')return 2;
}