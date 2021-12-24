#include"sort.h"
#include"header.h"
bool cmpbyjiage(CommodityInfo pCommodities1, CommodityInfo pCommodities2)
{
	return pCommodities1.price > pCommodities2.price;
}
bool cmpbyshuliang(CommodityInfo pCommodities1, CommodityInfo pCommodities2)
{
	return pCommodities1.num > pCommodities2.num;
}
bool cmpbyzhekou(CommodityInfo pCommodities1, CommodityInfo pCommodities2)
{
	return pCommodities1.discount > pCommodities2.discount;
}
bool cmpbymingcheng(CommodityInfo pCommodities1, CommodityInfo pCommodities2)
{
	return pCommodities1.name > pCommodities2.name;
}
bool cmpbyid(CommodityInfo pCommodities1, CommodityInfo pCommodities2)
{
	return pCommodities1.id > pCommodities2.id;
}
void sortbyJiaGe(CommodityInfo* pCommodities, int num)
{
	sort(pCommodities, pCommodities + num, cmpbyjiage);
}
void sortbyZheKou(CommodityInfo* pCommodities, int num)
{
	sort(pCommodities, pCommodities + num, cmpbyzhekou);
}
void sortbyShuLiang(CommodityInfo* pCommodities, int num)
{
	sort(pCommodities, pCommodities + num, cmpbyshuliang);
}
void sortbyMingCheng(CommodityInfo* pCommodities, int num)
{
	sort(pCommodities, pCommodities + num, cmpbymingcheng);
}
void sortbyId(CommodityInfo* pCommodities, int num)
{
	sort(pCommodities, pCommodities + num, cmpbyid);
}
void paixu(CommodityInfo* pCommodities, int num)
{
	cout << "按商品价格（1" << endl;
	cout << "按商品折扣（2" << endl;
	cout << "按商品数量（3" << endl;
	cout << "按商品名称(4" << endl;
	cout << "按商品ID(5" << endl;
	char a;
	cin >> a;
	switch (a)
	{
	case '3':
		cout << " 按商品数量:" << endl;
		sortbyShuLiang(pCommodities, num);
		displayCommodities(pCommodities, commodityNum);
		break;
	case'1':
		cout << " 按商品价格:" << endl;
		sortbyJiaGe(pCommodities, num);
		displayCommodities(pCommodities, commodityNum);
		break;
	case '2':
		cout << "按商品折扣:" << endl;
		sortbyZheKou(pCommodities, num);
		displayCommodities(pCommodities, commodityNum);
		break;
	case '4':
		cout << "按商品名称" << endl;
		sortbyMingCheng(pCommodities, commodityNum);
		displayCommodities(pCommodities, commodityNum);
		break;
	case '5':
		cout << "按商品ID" << endl;
		sortbyId(pCommodities, commodityNum);
		displayCommodities(pCommodities, commodityNum);
		break;
	default:
		cout << "输入错误,重新来过" << endl;
		break;
	}
}