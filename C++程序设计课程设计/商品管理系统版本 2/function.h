#pragma once
#ifndef FUNCTION_HEADER
#define FUNCTION_HEADER
#include "datatype.h"
char menu();
void displayCommodities(CommodityInfo* pCommodities, int num);
void addCommodity(CommodityInfo*& pCommodities, int& num);
void removeCommodity(CommodityInfo* pCommodities, int& num);
void viewCommodity(CommodityInfo* pCommodities, int num);
void checkOut(CommodityInfo* pCommodities, int num);
void readData(std::string filename);
void writeData(std::string filename);
#endif
