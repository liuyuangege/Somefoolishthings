#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
class RandomNum {
public:
	RandomNum(); //��ϵͳ��ǰʱ���������������
	RandomNum(unsigned int seed); //�ô���� seed �������������
	void setSeed(unsigned int seed); //���ò�ͬ�����������
	int random(); //���� 0~RAND_MAX ������
	int random(int max); //���� 0~max ֮�������������� max��
	double frandom(); //���� 0~1.0 ֮��� double ������������� 1.0��
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