//#include<iostream>
//#include<iomanip>
//using namespace std;
//class Time {
//public:
//	Time(); //ָ��Сʱ�ͷ�����Ϊ 0 ���� Time ����
//	Time(int h, int m); //ͨ��ָ�� h �� m ���� Time ����
//	Time(int minutes); //ͨ��ָ������������ Time ����
//	void setTime(int h, int m); //�����µ�ʱ��
//	void output()const; //�� hh:mm �淶��ʽ���ʱ��
//	int getHour()const; //���Сʱ
//	int getMinute()const; //��÷���
//	int getTotalMinutes()const; //��ô� 0 �� 0 ������ܷ�����
//	Time getTimeSpan(const Time& t)const; //����ʱ���
//	friend std::ostream& operator<<(std::ostream& out, const Time& t);
//	Time operator-(const Time& newTime)const; //����ʱ���
//private:
//	int hour;
//	int minute;
//	void normalizeTime(); //�淶��СʱΪ 0~23������Ϊ 0~59
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
//Time Time::operator-(const Time& newTime)const //����ʱ���
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