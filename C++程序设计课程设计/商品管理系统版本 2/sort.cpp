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
	cout << "����Ʒ�۸�1" << endl;
	cout << "����Ʒ�ۿۣ�2" << endl;
	cout << "����Ʒ������3" << endl;
	cout << "����Ʒ����(4" << endl;
	cout << "����ƷID(5" << endl;
	char a;
	cin >> a;
	switch (a)
	{
	case '3':
		cout << " ����Ʒ����:" << endl;
		sortbyShuLiang(pCommodities, num);
		displayCommodities(pCommodities, commodityNum);
		break;
	case'1':
		cout << " ����Ʒ�۸�:" << endl;
		sortbyJiaGe(pCommodities, num);
		displayCommodities(pCommodities, commodityNum);
		break;
	case '2':
		cout << "����Ʒ�ۿ�:" << endl;
		sortbyZheKou(pCommodities, num);
		displayCommodities(pCommodities, commodityNum);
		break;
	case '4':
		cout << "����Ʒ����" << endl;
		sortbyMingCheng(pCommodities, commodityNum);
		displayCommodities(pCommodities, commodityNum);
		break;
	case '5':
		cout << "����ƷID" << endl;
		sortbyId(pCommodities, commodityNum);
		displayCommodities(pCommodities, commodityNum);
		break;
	default:
		cout << "�������,��������" << endl;
		break;
	}
}