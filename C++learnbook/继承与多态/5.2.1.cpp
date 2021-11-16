//#include<iostream>
//#include<iomanip>
//using namespace std;
//class point {
//public:
//	point(double newx = 0, double newy = 0);
//	point(const point& p);
//	~point();
//	void setvalue(double newx, double newy);
//	double getx() const;
//	double gety() const;
//	double getdistance(const point& p2) const;
//private:
//	double x, y;
//};
//point::point(double newx , double newy ) :x(newx), y(newy) {};
//point::point(const point& p) :x(p.getx()), y(p.gety()) {};
//point::~point() {};
//void point::setvalue(double newx, double newy) { x = newx, y = newy; };
//double point::getx() const { return x; }
//double point::gety() const { return y; }
//double point::getdistance(const point& p2)const
//{
//	return sqrt((x - p2.x) * (x - p2.x) + (y - p2.y) * (y - p2.y));
//}
//class point3d : public point {
//public:
//
//	point3d(double newx , double newy, double newz = 0);
//	point3d(const point& p);
//	double getz() const;
//	double getdistance(const point3d& p)const;
//private:
//	double z;
//};
//point3d::point3d(double newx, double newy, double newz ) :point(newx,newy),z(newz) {  };
//double point3d::getz()const { return z; }
//double point3d::getdistance(const point3d&p)const
//{
//	return sqrt((getx() - p.getx())* (getx() - p.getx()) + (gety() - p.gety())* (gety() - p.gety()) + (getz() - p.getz())* (getz() - p.getz()));
//}
//point3d::point3d(const point& p)
//{
//	z = 0;
//}
//int main() {
//	point p1(3, 4), p2(5, 3);
//	point3d p1_3D(3, 4, 6);
//	point3d  p2_3D(2, 6, 9);
//	double dis = p1.getdistance(p2); //计算二维点 p1 和 p2 的距离
//	cout << "Distance between p1 and p2: " << dis << endl;
//	dis = p1.getdistance(p2_3D); //计算 p1 和 p2_3D 的距离
//	cout << "Distance between p1 and p2_3D: " << dis << endl;
//	dis = p1_3D.getdistance(p2); //计算点 p1_3D 和 p2 的距离
//	cout << "Distance between p1_3D and p2: " << dis << endl;
//	return 0;
//}
