//#include<iostream>
//#include<iomanip>
//using namespace std;
//#pragma region Mytime.h
//class Time {
//public:
//	Time(); //指定小时和分钟数为 0 构造 Time 对象
//	Time(int h, int m); //通过指定 h 和 m 构造 Time 对象
//	Time(int minutes); //通过指定分钟数构造 Time 对象
//	void setTime(int h, int m); //设置新的时间
//	//void output()const; //以 hh:mm 规范格式输出时间
//	int getHour()const; //获得小时
//	int getMinute()const; //获得分钟
//	int getTotalMinutes()const; //获得从 0 点 0 分起的总分钟数
//	//Time getTimeSpan(const Time& t)const; //计算时间差
//	friend std::ostream& operator<<(std::ostream& out, const Time& t);
//	Time operator-(const Time& newTime)const; //计算时间差
//private:
//	int hour;
//	int minute;
//	void normalizeTime(); //规范化小时为 0~23，分钟为 0~59
//};
//Time::Time()
//{
//	hour = 0;
//	minute = 0;
//}
//Time::Time(int h, int m)
//{
//	hour = h;
//	minute = m;
//	normalizeTime();
//}
//void Time::setTime(int h, int m)
//{
//	hour = h;
//	minute = m;
//	normalizeTime();
//}
//void Time::normalizeTime()
//{
//	if (minute >= 60)
//	{
//		while (minute >= 60)
//		{
//			hour += minute / 60;
//			minute %= 60;
//		}
//	}
//	if (hour >= 24)
//	{
//		while (hour >= 24)
//			hour %= 24;
//	}
//}
////void Time::output()const
////{
////	cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << endl;
////}
//int Time::getHour()const
//{
//	return hour;
//}
//int Time::getMinute()const
//{
//	return minute;
//}
//int Time::getTotalMinutes()const
//{
//	return hour * 60 + minute;
//}
//Time::Time(int minutes)
//{
//	hour = 0;
//	minute = minutes;
//	normalizeTime();
//}
////Time Time::getTimeSpan(const Time& t)const
////{
////	int spantime = 0;
////	spantime = getTotalMinutes() - t.getTotalMinutes();
////	spantime = spantime > 0 ? spantime : -spantime;
////	Time tmp(spantime);
////	return tmp;
////}
//Time Time::operator-(const Time& newTime)const //计算时间差
//{
//	int spantime = 0;
//	spantime = getTotalMinutes() - newTime.getTotalMinutes();
//	spantime = spantime > 0 ? spantime : -spantime;
//	Time tmp(spantime);
//	return tmp;
//}
//std::ostream& operator<<(std::ostream& out, const Time& t)
//{
//	out << setfill('0') << setw(2) << t.hour << ":" << setw(2) << t.minute << endl;
//	return out;
//}
//
//#pragma endregion
//class ParkingCard {
//public:
//	ParkingCard(double newRate) { rate = newRate; }
//	void setRate(double newRate) { rate = newRate; } //设置每小时费率
//	double getRate() const { return rate; }
//	void setParkingTime(const Time& time); //设置开始停车时间
//	void setLeavingTime(const Time& time); //设置离开时间
//	double getTotalExpenses() const; //计算停车费用
//	//停车时间分钟数不足半小时按半小时计算，不足 1 小时按 1 小时计算
//	void output() const; //输出停车起始时间、费率及总费用
//private:
//	double rate; //停车费率，按元/每小时计算
//	Time parkingTime; //开始停车时间
//	Time leavingTime; //离开时间
//};
//int main() {
//	ParkingCard card(5);
//	card.setParkingTime(Time(9, 20)); //构造临时时间对象并作为参数
//	card.setLeavingTime(Time(11, 35));
//	cout << "Expenses: " << card.getTotalExpenses() << endl;
//	cout << "Detailed info:\n";
//	card.output();
//	return 0;
//}
//void ParkingCard::setParkingTime(const Time& time) {
//	parkingTime = time;
//}
//void ParkingCard::setLeavingTime(const Time& time) {
//	leavingTime = time;
//}
//double ParkingCard::getTotalExpenses() const
//{
//	double cost=0;
//	Time totaltime;
//	totaltime = leavingTime-parkingTime;
//	//totaltime.output();
//	if (totaltime.getMinute() <= 30 && totaltime.getMinute() > 0)
//	{
//		cost += totaltime.getHour() * rate + 0.5 * rate;
//	}
//	else if (totaltime.getMinute() == 0)
//	{
//		cost += totaltime.getHour() * rate;
//	}
//	else
//		cost += totaltime.getHour() * rate+rate;
//	return cost;
//}
//void ParkingCard::output() const
//{
//	cout << "Total Expenses :" << getTotalExpenses() << endl;
//	cout << "Parking Time: ";
//	cout<<parkingTime;
//	cout << "Leaving Time:";
//	cout<<leavingTime;
//	cout << "Rate:" << rate << endl;
//}
