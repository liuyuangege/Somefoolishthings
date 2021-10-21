#include <iostream>
using namespace std;
class Complex {
public:
	Complex(); //缺省构造函数，实部和虚部为 0
	Complex(double r); //只有 1 个参数，虚部为 0
	Complex(double r, double i); //设置实部和虚部
	void setValue(double r, double i); //设置实部和虚部
	double getReal(); //获取实部值
	double getImage(); //获取虚部值
	double getDistance(); //获取复数和原点距离
	void output(); //按复数形式输出，如 3-5i
private:
	double real; //实部
	double image; //虚部
};
int main() {
	Complex c1, c2(2), c3(3, 4);
	c1.output();
	c2.output();
	c3.output();
	c1.setValue(6, 4);
	c1.output();
	cout << c1.getDistance() << endl;
	return 0;
}
Complex::Complex()
{
	real = 0;
	image = 0;
}
Complex::Complex(double r)
{
	real = r;
	image = 0;
}
Complex::Complex(double r, double i)
{
	real = r;
	image = i;
}
void Complex::setValue(double r, double i)
{
	real = r;
	image = i;
}
double Complex::getReal()
{
	return real;
}
double Complex::getImage()
{
	return image;
}
double Complex::getDistance()
{
	return sqrt(real * real + image * image);
}
void Complex::output()
{
	if (image != 0)
	{
		if (real == 0)
		{
			if (image > 0)cout << image << 'i' << endl;
			else cout << image << 'i' << endl;
		}
		else
		{
			cout << real;
			if (image > 0)cout << '+'<<image << 'i' << endl;
			else cout << image << 'i' << endl;
		}
	}
	else
	{
		cout << real << endl;
	}
}
