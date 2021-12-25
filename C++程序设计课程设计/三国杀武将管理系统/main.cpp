#include <iostream>
#include "Wujiang.h"
#include "WujiangManage.h"
#include "function.h"
using namespace std;
int main() {
	cout << "欢迎使用三国杀武将管理系统!\n";
	char choice;
	WujiangManage cm;
	while (true) {
		choice = menu();
		if (choice == '0')
			break;
		switch (choice) {
		case '1':
			doAddWujiang(cm);
			break;
		case '2':
			doRemoveWujiang(cm);
			break;
		case '3':
			doViewWujiang(cm);
			break;
		case '4':
			doViewAllWujiangs(cm);
			break;
		case'5':
			doModifyWujiangInfo(cm);
			break;
		case'6':
			doStartWar(cm);
			break;
		default:
			cout << "无效输入! 请重试!\n";
			break;
		}
	}
	cout << "再见!\n";
	return 0;
}