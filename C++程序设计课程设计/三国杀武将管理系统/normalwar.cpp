#include"normalwar.h"
#include<iostream>
using namespace std;
Normalwar::Normalwar(Wujiang *j1, Wujiang *j2)
{
	result = (j1->getHp() * j1->getLevel()) > (j2->getHp() * j2->getLevel()) ? 1 : 0;
}
bool Normalwar::getResult()
{
	if (result) {
		return 1;
	}
	return 0;
}