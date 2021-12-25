#pragma once
#ifndef _normalwar_h
#define _normalwar_h
#include<string>
#include"wujiang.h"
class Normalwar  {
public:
	Normalwar() = default;
	~Normalwar() {}
	Normalwar(Wujiang *j1, Wujiang* j2);
	bool getResult();
private:
	bool result;
};
#endif // normalwar.h
