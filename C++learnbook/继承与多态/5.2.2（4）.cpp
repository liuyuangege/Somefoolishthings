//#include<iostream>
//#include<cmath>
//using namespace std;
//const double PI = 3.14;
//class Shape {
//public:
//
//	virtual double getArea()const=0;
//	virtual double getPerimeter()const=0;
//	virtual ~Shape() {};
//};
//class Triangle : public Shape {
//public:
//	Triangle(double newA, double newB, double newC);
//	virtual double getArea()const;
//	virtual double getPerimeter()const;
//private:
//	double a, b, c;
//};
//Triangle::Triangle(double newA, double newB, double newC)
//{
//	a = newA;
//	b = newB;
//	c = newC;
//}
//double Triangle::getPerimeter()const
//{
//	return a + b + c;
//}
//double Triangle::getArea()const
//{
//	double p = (a + b + c) / 2.0;
//	return sqrt(p * (p - a) * (p - b) * (p - c));
//}
//class Circle : public Shape {
//public:
//	Circle(double r) : radius(r) {}
//	double getArea() const;
//	double getPerimeter() const;
//private:
//	double radius;
//};
//double Circle::getArea()const {
//	return PI * radius * radius;
//}
//double Circle::getPerimeter()const {
//	return 2 * PI * radius;
//}
//class Rectangle : public Shape {
//public:
//	Rectangle(double w, double h) : width(w), height(h) {}
//	double getArea()const;
//	double getPerimeter()const;
//private:
//	double width;
//	double height;
//};
//double Rectangle::getArea()const {
//	return width * height;
//}
//double Rectangle::getPerimeter()const {
//	return 2 * (width + height);
//
//}
//int main() {
//	Shape* pShapes[3]; //定义基类指针数组
//	pShapes[0] = new Rectangle(3, 4);
//	pShapes[1] = new Circle(1.0);
//	pShapes[2] = new Triangle(3, 4, 5);
//	double totalArea = 0, totalPerimeter = 0;
//	for (int i = 0; i < 3; ++i) {
//		totalArea += pShapes[i]->getArea();
//		totalPerimeter += pShapes[i]->getPerimeter();
//	}
//	cout << "Total Area: " << totalArea << endl;
//	cout << "Total Perimeter: " << totalPerimeter << endl;
//	for (int i = 0; i < 3; ++i)
//		delete pShapes[i];
//}