#include<stdio.h>
#include<Windows.h>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
class CTime
{
public:
	CTime(int hour = 0, int min = 0, int sec = 0)
		:hour(hour)
		, minute(min)
		, second(sec)
	{
	}
	void AddTime(){
		while (true)
		{
			cout << hour << ':' << minute << ':' << second << endl;
			Sleep(1000);
			second++;
			if (second % 60 == 0)
			{
				second = 0;
				minute++;
				minute %= 60;
				if (minute % 60 == 0)
				{
					minute = 0;
					hour++;
					hour %= 24;
				}
			}
		}
	}
	void SubTime(){
		while (true)
		{
			cout << hour << ':' << minute << ':' << second << endl;
			Sleep(1000);
			if (!(minute < 0 && hour < 0 && second < 0)){
				second--;
				if (second % 60 < 0)
				{

					second = 59;
					minute--;
					minute %= 60;

					if (minute % 60 < 0)
					{
						if (hour == 0)
							break;
						minute = 59;
						hour--;
						hour %= 24;
					}
				}
			}
		}
	}
private:
	short hour;
	short minute;
	short second;
};


int main()
{
	int model;
	cout << "请选择计时方式 " << endl;
	cout << "  1.递增计时" << endl;
	cout << "  2.递减计时" << endl;
	scanf("%d", &model);
	CTime t(0, 1, 10);
	switch (model)
	{
	case 1:

		cout << "执行正计时" << endl;
		t.AddTime();
		break;
	case 2:
		cout << "执行倒计时" << endl;
		t.SubTime();
		break;
	default:
		cout << "" << endl;
		break;
	}

	system("pause");
}
