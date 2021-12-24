#ifndef FUNCTION_H
#define FUNCTION_H
#include "CommodityManage.h"
char menu();
void doAddCommodity(CommodityManage& cm);
void doRemoveCommodity(CommodityManage& cm);
void doViewCommodity(const CommodityManage& cm);
void doViewAllCommodity(const CommodityManage& cm);
void doCheckout(const CommodityManage& cm);
#endif // FUNCTION_H