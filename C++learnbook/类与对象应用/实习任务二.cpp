//#include <iostream>
//using namespace std;
//class Complex {
//public:
//	Complex();
//	Complex(double r);
//	Complex(double r, double i);
//	void setValue(double r, double i);
//	double getReal() const;
//	double getImage() const;
//	double getDistance() const;
//	void output() const;
//	Complex add(const Complex& c)const;
//	Complex multiply(const Complex& c)const;
//private:
//	double real;
//	double image;
//};
//Complex::Complex() :real(0), image(0) {}
//Complex::Complex(double r) : real(r), image(1) {}
//Complex::Complex(double r, double i) : real(r), image(i) {}
//void Complex::setValue(double r, double i)
//{
//	real = r;
//	image = i;
//}
//double Complex::getReal() const
//{
//	return real;
//}
//double Complex::getImage() const
//{
//	return image;
//}
//double Complex::getDistance() const
//{
//	return sqrt(real * real + image * image);
//}
//void Complex::output() const
//{
//	if (image != 0)
//	{
//		if (real == 0)
//		{
//			if (image > 0)cout << image << 'i' << endl;
//			else cout << image << 'i' << endl;
//		}
//		else
//		{
//			cout << real;
//			if (image > 0)cout << '+' << image << 'i' << endl;
//			else cout << image << 'i' << endl;
//		}
//	}
//	else
//	{
//		cout << real << endl;
//	}
//}
//Complex Complex::add(const Complex& c)const
//{
//	double R = real;
//	double I = image;
//	Complex tmp(R + c.getReal(), I + c.getImage());
//	return tmp;
//}
//Complex Complex::multiply(const Complex& c)const
//{
//	double R = real;
//	double I = image;
//	//(a+bi)*(c+di)=(ac-bd)+(ad+bc)i
//	Complex tmp((R * c.getReal() - I * c.getImage()), (R * c.getImage() + I * c.getReal()));
//	return tmp;
//}
//
