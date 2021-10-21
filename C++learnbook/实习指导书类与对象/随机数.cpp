#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
class RandomNum {
public:
	RandomNum(); //用系统当前时间设置随机数种子
	RandomNum(unsigned int seed); //用传入的 seed 设置随机数种子
	void setSeed(unsigned int seed); //重置不同的随机数种子
	int random(); //产生 0~RAND_MAX 的整数
	int random(int max); //产生 0~max 之间的随机数（不含 max）
	double frandom(); //产生 0~1.0 之间的 double 型随机数（不含 1.0）
};
int main() {
	RandomNum randomGenerator;
	int i;
	for (i = 0; i < 100; ++i)
		cout << randomGenerator.random(100) << ' ';
	cout << "\n";
	for (i = 0; i < 100; ++i)
		cout << randomGenerator.frandom() << ' ';
	cout << "\n";
	return 0;
}

RandomNum::RandomNum()
{
	srand((unsigned int)time(NULL));
}
RandomNum::RandomNum(unsigned int seed)
{
	srand(seed);
}
void RandomNum::setSeed(unsigned int seed)
{
	srand(seed);
}
int RandomNum::random()
{
	return rand()% RAND_MAX;
}
int RandomNum::random(int max)
{
	return rand() % max;
}
double RandomNum::frandom()
{
	return 1.0 * rand() / RAND_MAX;
}