#include <iostream>
using namespace std;
class Complex {
public:
	Complex(); //ȱʡ���캯����ʵ�����鲿Ϊ 0
	Complex(double r); //ֻ�� 1 ���������鲿Ϊ 0
	Complex(double r, double i); //����ʵ�����鲿
	void setValue(double r, double i); //����ʵ�����鲿
	double getReal(); //��ȡʵ��ֵ
	double getImage(); //��ȡ�鲿ֵ
	double getDistance(); //��ȡ������ԭ�����
	void output(); //��������ʽ������� 3-5i
private:
	double real; //ʵ��
	double image; //�鲿
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
