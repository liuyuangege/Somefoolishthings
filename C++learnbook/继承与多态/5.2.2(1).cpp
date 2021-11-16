//#include <iostream>
//using namespace std;
//const double PI = 3.14;
//class Shape {
//public:
//
//	virtual double getArea()const=0;
//	virtual double getPerimeter()const=0;
//	virtual ~Shape() {};
//};
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
//	pShapes[2] = new Rectangle(2, 1);
//	double totalArea = 0, totalPerimeter = 0;
//	for (int i = 0; i < 3; ++i) {
//		totalArea += pShapes[i]->getArea();
//		totalPerimeter += pShapes[i]->getPerimeter();
//	}
//	cout << "Total Area: " << totalArea << endl;
//	cout << "Total Perimeter: " << totalPerimeter << endl;
//	for (int i = 0; i < 3; ++i)
//		delete pShapes[i];
//	return 0;
//}