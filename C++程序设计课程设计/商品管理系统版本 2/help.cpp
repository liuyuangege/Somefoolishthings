#include <iostream>
#include "header.h"
using namespace std;
void reAllocMemory(CommodityInfo*& pCommodities, int num) {
	maxCommodityNum *= 2;
	CommodityInfo* temp = pCommodities;
	pCommodities = new CommodityInfo[maxCommodityNum];
	for (int i = 0; i < num; ++i)
		pCommodities[i] = temp[i];
	delete[] temp;
}
void setCommodityInfo(CommodityInfo* pCommodity) { //读取商品信息
	fflush(stdin); //确保之前残留的回车被清理，商品名称取整行
	cout << " 输入商品名称: ";
	cin.get();
	getline(cin, pCommodity->name);
	cout << " 输入商品价格: ";
	cin >> pCommodity->price;
	cout << " 输入商品数量: ";
	cin >> pCommodity->num;
	cout << " 输入商品折扣: ";
	cin >> pCommodity->discount;
}
int findCommodityById(CommodityInfo* pCommodities,
	int num, long id) {
	CommodityInfo* pCommodity = pCommodities;
	for (int i = 0; pCommodity < pCommodities + num; pCommodity++, i++) {
		if (pCommodity->id == id) {
			return i;
		}
	}
	return -1;
}
double getCommodityPrice(CommodityInfo* pCommodity) {
	return pCommodity->price * pCommodity->num * pCommodity->discount;
}
void showCommodityInfo(CommodityInfo* pCommodity) {
	cout << "商品编号(id):" << pCommodity->id << endl;
	cout << " 商品名称:" << pCommodity->name << endl;
	cout << " 商品总价:" << getCommodityPrice(pCommodity)
		<< " (价格:" << pCommodity->price << ", 数量:"
		<< pCommodity->num << ", 折扣:" << pCommodity->discount << " )\n";
}
void changeCommodityInfo(CommodityInfo* pCommodity, int num, long id)
{
	int pos = findCommodityById(pCommodity, num, id);
	if (pos == -1)
	{
		cout << "商品不存在" << endl;
	}
	CommodityInfo* p = pCommodity;
	p += pos;
	while (true)
	{
		cout << "请选择修改的信息项" << endl;
		cout << "修改商品数量（0" << endl;
		cout << "修改商品价格（1" << endl;
		cout << "修改商品折扣（2" << endl;
		cout << "请输入：" << endl;
		char c;
		cin >> c;
		switch (c)
		{
		case '0':
			cout << "请输入商品数量" << endl;
			int num;
			cin >> num;
			p->num = num;
			break;
		case '1':
			cout << "请输入商品价格" << endl;
			double price;
			cin >> price;
			p->price = price;
			break;
		case '2':
			cout << "请输入商品折扣" << endl;
			double discount;
			cin >> discount;
			p->discount = discount;
			break;
		default:
			cout << "参数输入错误" << endl;
			break;
		}
		cout << "你还想改吗" << endl;
		bool pd = 0;
		cin >> pd;
		if (!pd)break;
	}

}