#include<iostream>
#include<ctime>
using namespace std;
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int multiply(int a, int b)
{
	return a * b;
}
int divixion(int a, int b)
{
	return a / b;
}
char menu()
{
	char choice;
	cout << "1)add two number\n";
	cout << " 2)sub two number\n";
	cout << "3)multiply two number\n";
	cout << "4)division two number\n";
	cout << "0)quit\n";
	cout << "Enter your choice:\n";
	cin >> choice;
	return choice;
}
bool answerQuestion(int num1, int num2, int(*f)(int, int), int answer)
{
	return f(num1, num2) == answer;
}
int main()
{
	int totalnum = 0;
	double correctlv=0;
	srand((unsigned)time(NULL));
	while (true)
	{
		char choice = menu();
		if (choice == '0')
			break;
		int num1, num2;
		while (true)
		{
			num1 = rand() % 90 + 10;
			num2 = rand() % 90 + 10;
			//std::cout << num1 << "****" << num2 << endl;
			if (num1 % num2 == 0)break;
		}
		decltype(add)* pf;
		char op;
		switch (choice)
		{
		case'1':
			pf = add;
			op = '+';
			break;
		case'2':
			pf = sub;
			op = '-';
			break;
		case'3':
			pf = multiply;
			op = '*';
			break;
		case'4':
			pf = divixion;
			op = '/';
			break;
		default:continue;
		}
		int answer;
		cout << num1 << op << num2 << "=?";
		int cnt = 0;
		while (1)
		{
			cin >> answer;
			totalnum++;
			if (answerQuestion(num1, num2, pf, answer) == true)
			{
				cout << "Correct!" << endl;
				correctlv++;
				break;
			}

			else
			{
				cout << "Wrong!" << endl;
				cnt++;
				if (cnt >= 3)
				{
					cout << "你没机会了" << endl;
					//totalnum = 0;
					break;
				}
					
				cout << "你错了,还有" << 3 - cnt << "次" << endl;
			}
		}
		if (totalnum == 0) { cout << "正确率为" << 0 << endl; continue; }
		cout << "正确率为" << correctlv / totalnum << endl;
	}
	return 0;
}