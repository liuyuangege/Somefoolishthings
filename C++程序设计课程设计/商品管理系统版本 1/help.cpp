#include <iostream>
#include "datatype.h"
using namespace std;
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
CommodityInfo* findCommodityById(CommodityInfo* pCommodities,
	int num, long id) {
	CommodityInfo* pCommodity = pCommodities;
	for (; pCommodity < pCommodities + num; pCommodity++) {
		if (pCommodity->id == id) {
			return pCommodity;
		}
	}
	return nullptr;
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