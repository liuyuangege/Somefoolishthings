#ifndef COMMODITY_H
#define COMMODITY_H
#include <string>
class Commodity {
public:
	static void setNextId(long id) { nextId = id; }
	static long getNextId() { return nextId; }
	Commodity() = default;
	Commodity(long i, std::string n, double p = 0, int nu = 0, double d = 0);
	Commodity(std::string n, double p = 0, int nu = 0, double d = 0);
	void setPrice(double price) { this->price = price; }
	void setNum(int num) { this->num = num; }
	void setDiscount(double discount) { this->discount = discount; }
	void setName(std::string name) { this->name = name; }
	std::string getName()const { return name; }
	long getId()const { return id; }
	double getPrice()const { return price; }
	int getNum()const { return num; }
	double getDiscount()const { return discount; }
	double getNetPrice()const;
	void output()const;
private:
	static long nextId;
	long autoNextId() { return nextId++; }
	long id;
	std::string name;
	double price;
	int num;
	double discount;
};
#endif // COMMODITY_H