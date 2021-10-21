#pragma once
class Time {
public:
	Time(); //ָ��Сʱ�ͷ�����Ϊ 0 ���� Time ����
	Time(int h, int m); //ͨ��ָ�� h �� m ���� Time ����
	void setTime(int h, int m); //�����µ�ʱ��
	void output(); //�� hh:mm �淶��ʽ���ʱ��
	int getHour(); //���Сʱ
	int getMinute(); //��÷���
	int getTotalMinutes(); //��ô� 0 �� 0 ������ܷ�����
private:
	int hour;
	int minute;
	void normalizeTime(); //�淶��СʱΪ 0~23������Ϊ 0~59
};
