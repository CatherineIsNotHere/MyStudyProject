#include <stdio.h>  
#include <windows.h> 
#include <graphics.h> //图形库头文件
#include <mmsystem.h>//播放音乐头文件
#pragma comment (lib,"winmm.lib")// 播放音乐需要的库文件



int flag = 0;//记录谁在下棋

static HWND hwndDlg;
int board[20][20] = { 0 }; //0表示没下棋

void intGame()
{
	//创建一个窗口
	initgraph(640, 480); //背景图尺寸

	loadimage(NULL, L"../src/beijing.jpg");      //背景图   必须 在目录前加“L”

	mciSendString(L"open ../src/ebody.mp3", 0, 0, 0);//打开音乐
	mciSendString(L"play ../src/ebody.mp3", 0, 0, 0); //播放音乐

	setlinecolor(BLACK); //线条颜色

	//绘制棋盘
	for (int i = 1; i < 20; i++)
	{
		line(i * 24, 0, i * 24, 480);
		line(0, i * 24, 480, i * 24);

	}
	line(481, 0, 481, 480);               //最右边宽线
	line(480, 0, 480, 480);

	settextcolor(RED);              //字体颜色
	setbkmode(0);                    //字体背景
	outtextxy(520, 60, L"玩家1:黑棋");
	outtextxy(520, 100, L"玩家2:白棋");
	outtextxy(520, 160, L"游戏规则：");
	outtextxy(520, 180, L"五个同颜色的棋");
	outtextxy(520, 200, L"连成相邻的直线");
	outtextxy(520, 220, L"即可获得胜利");
	outtextxy(520, 240, L"(PS:上左下边缘");
	outtextxy(520, 260, L"不可下棋)");
	HINSTANCE hinst = GetModuleHandle(NULL); //边框线
	CreateWindow(TEXT("BUTTON"), TEXT("frame"),
		WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		190, 5, 100, 190, hwndDlg, (HMENU)5000,
		hinst, NULL);

}






//判断输赢
int whowin(int a, int b)
{  //a-4 a-3 a-2 a-1 a
	//a-3 a-2 a-1 a a+1
	//a-2.......
	//a ......a+4
	int i, j;
	int t = 2 - flag % 2;
	//横向判断输赢
	for (i = a - 4, j = b; i <= a; i++)
	{
		if (i >= 1 && i <= 15 && t == board[i][j] && t == board[i + 1][j] && t == board[i + 2][j] && t == board[i + 3][j] && t == board[i + 4][j])
			return 1;
	}
	//纵向判断输赢
	for (j = b - 4, i = a; j <= b; j++)
	{
		if (j >= 1 && j <= 15 /* 20个格子减去4个 不算边缘*/ && t == board[i][j] && t == board[i][j + 1] && t == board[i][j + 2] && t == board[i][j + 3] && t == board[i][j + 4])
			return 1;
	}
	//斜着一个
	for (i = a - 4, j = b - 4; i <= a, j <= b; i++, j++)
	{
		if (i >= 1 && i <= 15 && j >= 1 && j <= 15 && t == board[i][j] && t == board[i + 1][j + 1] && t == board[i + 2][j + 2] && t == board[i + 3][j + 3] && t == board[i + 4][j + 4])
			return 1;
	}
	//斜着另一个
	for (i = a - 4, j = b + 4; i <= a, j >= 1; i++, j--)
	{
		if (i >= 1 && i <= 15 && j >= 1 && j <= 15 && t == board[i][j] && t == board[i + 1][j - 1] && t == board[i + 2][j - 2] && t == board[i + 3][j - 3] && t == board[i + 4][j - 4])
			return 1;
	}
	return 0;

}

//下棋
void playChess()
{
	//鼠标点击
	MOUSEMSG m;
	int a = 0, b = 0;
	int x = 0, y = 0;
	HWND hwnd;              //窗口句柄  一个特殊的指针-》（中国人  标志代表  身份证号）
	hwnd = GetHWnd();       //窗口置前
	while (1)
	{
		m = GetMouseMsg(); //获取鼠标消息
		//绝对值 临近点点击
		for (int i = 1; i < 20; i++)
		{
			for (int j = 1; j < 20; j++)
			{
				if (abs(m.x - i * 24) < 10 && abs(m.y - j * 24) < 10)   //abs求绝对值  一个格子大约24 一半范围小点的判定我取10
				{
					a = i; //行列号
					b = j;
					x = i * 24; // 坐标
					y = j * 24;
				}
			}

		}


		if (m.uMsg == WM_LBUTTONDOWN)//判断当前鼠标消息是不是鼠标左键按下
		{
			if (board[a][b] != 0)                //有棋子
			{
				MessageBox(hwnd, L"你瞎啊，这有棋子了，找别的地儿下", L"提示", MB_OK);   //弹出窗口提示 
				//退出循环
				continue;
			}
			if (flag % 2 == 0)                //取余数
			{
				setfillcolor(BLACK);       //填满操作
				solidcircle(x, y, 8);  //鼠标点击的地方  m.x / 24 * 24 =x  m.y / 24 * 24=y
				board[a][b] = 1;
			}
			else
			{
				setfillcolor(WHITE);
				solidcircle(x, y, 8);
				board[a][b] = 2;
			}

			flag++; //  1 3 5    2 4 6 
		}
		if (whowin(a, b)) //找到了五子连成线
		{
			if (flag % 2 == 1)
			{
				MessageBox(hwnd, L"玩家1胜利", L"游戏结束", MB_OK);
				exit(0);  //退出程序
			}
			else
			{
				MessageBox(hwnd, L"玩家2胜利", L"游戏结束", MB_OK);
				exit(0);  //退出程序
			}
		}
	}

}
int main()
{
	intGame();
	playChess();
	getchar();

	return 0;
}


