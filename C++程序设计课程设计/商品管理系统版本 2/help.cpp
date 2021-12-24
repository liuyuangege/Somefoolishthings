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
void setCommodityInfo(CommodityInfo* pCommodity) { //��ȡ��Ʒ��Ϣ
	fflush(stdin); //ȷ��֮ǰ�����Ļس���������Ʒ����ȡ����
	cout << " ������Ʒ����: ";
	cin.get();
	getline(cin, pCommodity->name);
	cout << " ������Ʒ�۸�: ";
	cin >> pCommodity->price;
	cout << " ������Ʒ����: ";
	cin >> pCommodity->num;
	cout << " ������Ʒ�ۿ�: ";
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
	cout << "��Ʒ���(id):" << pCommodity->id << endl;
	cout << " ��Ʒ����:" << pCommodity->name << endl;
	cout << " ��Ʒ�ܼ�:" << getCommodityPrice(pCommodity)
		<< " (�۸�:" << pCommodity->price << ", ����:"
		<< pCommodity->num << ", �ۿ�:" << pCommodity->discount << " )\n";
}
void changeCommodityInfo(CommodityInfo* pCommodity, int num, long id)
{
	int pos = findCommodityById(pCommodity, num, id);
	if (pos == -1)
	{
		cout << "��Ʒ������" << endl;
	}
	CommodityInfo* p = pCommodity;
	p += pos;
	while (true)
	{
		cout << "��ѡ���޸ĵ���Ϣ��" << endl;
		cout << "�޸���Ʒ������0" << endl;
		cout << "�޸���Ʒ�۸�1" << endl;
		cout << "�޸���Ʒ�ۿۣ�2" << endl;
		cout << "�����룺" << endl;
		char c;
		cin >> c;
		switch (c)
		{
		case '0':
			cout << "��������Ʒ����" << endl;
			int num;
			cin >> num;
			p->num = num;
			break;
		case '1':
			cout << "��������Ʒ�۸�" << endl;
			double price;
			cin >> price;
			p->price = price;
			break;
		case '2':
			cout << "��������Ʒ�ۿ�" << endl;
			double discount;
			cin >> discount;
			p->discount = discount;
			break;
		default:
			cout << "�����������" << endl;
			break;
		}
		cout << "�㻹�����" << endl;
		bool pd = 0;
		cin >> pd;
		if (!pd)break;
	}

}