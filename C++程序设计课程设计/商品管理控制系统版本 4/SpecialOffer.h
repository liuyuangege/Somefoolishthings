#pragma once
#ifndef SpecialOffer_H
#define SpecialOffer_H
#include <string>
#include "commodity.h"
class SpecialOffer : public Commodity {
public:
	virtual ~SpecialOffer() {}
	SpecialOffer(long id, std::string name,
		double p = 0, int n = 0, double d = 1.0);
	SpecialOffer(std::string name, double p = 0,
		int n = 0, double d = 1.0);
	void setSpecialDiscount(double specialdiscount) { this->specialdiscount = specialdiscount; }
	double getSpecialDiscount(double specialdiscount) { this->specialdiscount = specialdiscount; }
	virtual double getNetPrice()const;
	virtual void output()const;
	virtual int getType()const;
	virtual std::string getInfo()const;
	virtual void modifyInfo();
private:
	double specialdiscount;
};
#endif // SpecialOffer_H