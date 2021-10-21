#pragma once
class Time {
public:
	Time(); //指定小时和分钟数为 0 构造 Time 对象
	Time(int h, int m); //通过指定 h 和 m 构造 Time 对象
	void setTime(int h, int m); //设置新的时间
	void output(); //以 hh:mm 规范格式输出时间
	int getHour(); //获得小时
	int getMinute(); //获得分钟
	int getTotalMinutes(); //获得从 0 点 0 分起的总分钟数
private:
	int hour;
	int minute;
	void normalizeTime(); //规范化小时为 0~23，分钟为 0~59
};
