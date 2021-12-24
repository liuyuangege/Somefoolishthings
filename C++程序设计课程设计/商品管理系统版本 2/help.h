#pragma once
#ifndef HELP_HEADER
#define HELP_HEADER
#include "datatype.h"
int findCommodityById(CommodityInfo* pCommodities,
	int num, long id);
void showCommodityInfo(CommodityInfo* pCommodity);
void setCommodityInfo(CommodityInfo* pCommodity);
double getCommodityPrice(CommodityInfo* pCommodity);
void reAllocMemory(CommodityInfo*& pCommodities, int num);
void changeCommodityInfo(CommodityInfo* pCommodity);
#endif