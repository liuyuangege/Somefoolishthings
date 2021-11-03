//#include<iostream>
//#include<iomanip>
//using namespace std;
//class Time {
//public:
//	Time(); //指定小时和分钟数为 0 构造 Time 对象
//	Time(int h, int m); //通过指定 h 和 m 构造 Time 对象
//	Time(int minutes); //通过指定分钟数构造 Time 对象
//	void setTime(int h, int m); //设置新的时间
//	void output()const; //以 hh:mm 规范格式输出时间
//	int getHour()const; //获得小时
//	int getMinute()const; //获得分钟
//	int getTotalMinutes()const; //获得从 0 点 0 分起的总分钟数
//	Time getTimeSpan(const Time& t)const; //计算时间差
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
//void Time::output()const
//{
//	cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << endl;
//}
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
//Time Time::getTimeSpan(const Time& t)const
//{
//	int spantime = 0;
//	spantime = getTotalMinutes() - t.getTotalMinutes();
//	spantime = spantime > 0 ? spantime : -spantime;
//	Time tmp(spantime);
//	return tmp;
//}
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