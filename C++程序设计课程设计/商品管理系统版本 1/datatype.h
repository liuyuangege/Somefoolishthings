#pragma once
#include <string> //使用标准库中的 string 处理字符串
#ifndef DATATYPE_HEADER
#define DATATYPE_HEADER
struct CommodityInfo {
	long id; //商品编号
	std::string name; //商品名称，头文件中避免使用 using namespace 命令
	double price; //定价
	int num; //数量
	double discount; //折扣
};
const int MAX_COMMODITY_NUM = 100; //允许的最大商品数量常量
#endif