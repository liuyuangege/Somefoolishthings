#pragma once
#ifndef _wujiang_h
#define _wujiang_h
#include<string>
class Wujiang {
public:
	Wujiang() = default;
	~Wujiang() {};
	Wujiang(long id, std::string country, std::string name, double hp, int level);
	Wujiang(std::string country, std::string name, double hp, int level);
	void output()const;
	std::string getInfo()const;
	void setCountry(std::string country) { this->country = country; }
	void setName(std::string name) { this->name = name; }
	void setHp(double hp) { this->hp = hp; }
	void setLevel(int level) { this->level = level; }
	void modifyInfo();
	long getId()const { return id; }
	std::string getName()const { return name; }
	std::string getCountry()const { return country; }
	double getHp()const { return hp; }
	int getLevel()const { return level; }
	static void setNextId(long id) { nextId = id; }
	static long getNextId() { return nextId; }
private:
	long id;//武将编号
	std::string name;//姓名
	std::string country;//国籍
	double hp;//血量
	int level;//强度
	static long nextId;
	long autoNextId() { return nextId++; }
};
#endif // wujiang.h
