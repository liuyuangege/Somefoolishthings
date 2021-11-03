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
//	Complex operator+(const Complex& f)const;
//	Complex operator*(const Complex& f)const;
//	Complex& operator+=(const Complex& f);
//	Complex& operator*=(const Complex& f);
//	Complex& operator ++(); //前置++，实部加 1
//	Complex operator++(int); //后置++，实部加 1
//	friend std::ostream& operator<<(std::ostream& out,const Complex& f);
//	Complex& operator-=(const Complex& f);
//	friend Complex operator-(const Complex& f1, const Complex& f2);
//
//private:
//	double real;
//	double image;
//};
//#pragma region MyRegion
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
//#pragma endregion
//Complex Complex::operator+(const Complex& f)const
//{
//	Complex tmp;
//	tmp.real = real + f.real;
//	tmp.image = image + f.image;
//	return tmp;
//}
//Complex& Complex::operator+=(const Complex& f)
//{
//	real += f.real;
//	image += f.image;
//	return *this;
//}
//Complex Complex::operator*(const Complex& f)const
//{
//	double R = real;
//	double I = image;
//	//(a+bi)*(c+di)=(ac-bd)+(ad+bc)i
//	Complex tmp((R * f.getReal() - I * f.getImage()), (R * f.getImage() + I * f.getReal()));
//	return tmp;
//}
//Complex& Complex::operator*=(const Complex& f)
//{
//	real = f.real * real - image * f.image;
//	image = f.image * real + image * f.real;
//	return *this;
//}
//Complex& Complex::operator ++() //前置++，实部加 1
//{
//	real += 1;
//	return *this;
//}
//Complex Complex:: operator ++(int) //前置++，实部加 1
//{
//	Complex tmp(real + 1, image);
//	return tmp;
//}
//Complex& Complex::operator-=(const Complex& f)
//{
//	real -= f.real;
//	image -= f.image;
//	return *this;
//}
//Complex operator-(const Complex& f1, const Complex& f2)
//{
//	Complex tmp(f1.real - f2.real, f1.image - f2.image);
//	return tmp;
//}
//std::ostream& operator<<(std::ostream& out, const Complex& f)
//{
//	if (f.image != 0)
//	{
//		if (f.real == 0)
//		{
//			if (f.image > 0)out << f.image << 'i' << endl;
//			else out << f.image << 'i' << endl;
//		}
//		else
//		{
//			out << f.real;
//			if (f.image > 0)out << '+' << f.image << 'i' << endl;
//			else out << f.image << 'i' << endl;
//		}
//	}
//	else
//	{
//		out << f.real<<endl ;
//	}
//	return out;
//}
//int main()
//{
//
//}
//
