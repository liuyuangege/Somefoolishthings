#pragma once
#ifndef COMMODITY_H
#define COMMODITY_H
#include<string>
class Commodity {
public:
	virtual ~Commodity() {}
	Commodity() = default;
	virtual double getNetPrice()const;
	virtual void output()const;
	virtual int getType()const = 0; //���麯��
	virtual std::string getInfo()const;
	Commodity(long i, std::string n, double p, int nn);
	Commodity(std::string n, double p, int nn);
	void setPrice(double price) { this->price = price; }
	void setNum(int num) { this->num = num; }
	void setName(std::string name) { this->name = name; }
	std::string getName()const { return name; }
	double getPrice()const { return price; }
	int getNum()const { return num; }
	long getId()const { return id; }
	virtual void modifyInfo();
	static void setNextId(long id) { nextId = id; }
	static long getNextId() { return nextId; }
private:
	long id;
	std::string name;
	double price; //��Ʒ�۸�
	int num; //��������
	static long nextId;
	long autoNextId() { return nextId++; }
};
#endif // COMMODITY_H