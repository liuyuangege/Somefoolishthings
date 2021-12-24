#ifndef COMMODITYMANAGE_H
#define COMMODITYMANAGE_H
#include"Commodity.h"
class CommodityManage {
public:
	CommodityManage();
	CommodityManage(int s);
	void readData(std::string filename);
	void saveData(std::string filename);
	~CommodityManage();
	CommodityManage(const CommodityManage& c) = delete;
	CommodityManage& operator=(const CommodityManage& c) = delete;
	void addCommodity(Commodity*p);
	void removeCommodity(int id);
	void viewCommodity(int id)const;
	void viewAllCommodities()const;
	void checkOut()const;
	void modifyCommodityInfo(int id);
private:
	Commodity** pCommodities; //ָ��̬��������Ʒ����
	int maxSize; //��ǰ����Ŀռ�����
	int size; //ʵ�ʵ���Ʒ����
	Commodity* findCommodityById(int id)const;
	void reAllocMemory();
};
#endif // COMMODITYMANAGE_H