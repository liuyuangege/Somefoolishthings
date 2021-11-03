//#include<iostream>
//#include<iomanip>
//using namespace std;
//#pragma region Mytime.h
//class Time {
//public:
//	Time(); //ָ��Сʱ�ͷ�����Ϊ 0 ���� Time ����
//	Time(int h, int m); //ͨ��ָ�� h �� m ���� Time ����
//	Time(int minutes); //ͨ��ָ������������ Time ����
//	void setTime(int h, int m); //�����µ�ʱ��
//	//void output()const; //�� hh:mm �淶��ʽ���ʱ��
//	int getHour()const; //���Сʱ
//	int getMinute()const; //��÷���
//	int getTotalMinutes()const; //��ô� 0 �� 0 ������ܷ�����
//	//Time getTimeSpan(const Time& t)const; //����ʱ���
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
//
//#pragma endregion
//class ParkingCard {
//public:
//	ParkingCard(double newRate) { rate = newRate; }
//	void setRate(double newRate) { rate = newRate; } //����ÿСʱ����
//	double getRate() const { return rate; }
//	void setParkingTime(const Time& time); //���ÿ�ʼͣ��ʱ��
//	void setLeavingTime(const Time& time); //�����뿪ʱ��
//	double getTotalExpenses() const; //����ͣ������
//	//ͣ��ʱ������������Сʱ����Сʱ���㣬���� 1 Сʱ�� 1 Сʱ����
//	void output() const; //���ͣ����ʼʱ�䡢���ʼ��ܷ���
//private:
//	double rate; //ͣ�����ʣ���Ԫ/ÿСʱ����
//	Time parkingTime; //��ʼͣ��ʱ��
//	Time leavingTime; //�뿪ʱ��
//};
//int main() {
//	ParkingCard card(5);
//	card.setParkingTime(Time(9, 20)); //������ʱʱ�������Ϊ����
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
