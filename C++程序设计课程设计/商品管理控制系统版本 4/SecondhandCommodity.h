#pragma once
#ifndef SecondhandCommodity_H
#define SecondhandCommodity_H
#include <string>
#include "commodity.h"
class SecondhandCommodity : public Commodity {
public:
	virtual ~SecondhandCommodity() {}
	SecondhandCommodity(long id, std::string name,
		double p = 0, int n = 0, double d = 1.0, double t = 0);
	SecondhandCommodity(std::string name, double p = 0,
		int n = 0, double d = 1.0, double t = 0);
	void setDiscount(double discount) { this->discount = discount; }
	void setZhejiu(double zhejiu) { this->zhejiu = zhejiu; }
	double getDiscount()const { return discount; }
	double getZhejiu()const { return zhejiu; }
	virtual double getNetPrice()const;
	virtual void output()const;
	virtual int getType()const;
	virtual std::string getInfo()const;
	virtual void modifyInfo();
private:
	double discount;
	double zhejiu;
};
#endif // SecondhandCommodity_H