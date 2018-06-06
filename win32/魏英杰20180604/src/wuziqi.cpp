#include <stdio.h>  
#include <windows.h> 
#include <graphics.h> //ͼ�ο�ͷ�ļ�
#include <mmsystem.h>//��������ͷ�ļ�
#pragma comment (lib,"winmm.lib")// ����������Ҫ�Ŀ��ļ�



int flag = 0;//��¼˭������

static HWND hwndDlg;
int board[20][20] = { 0 }; //0��ʾû����

void intGame()
{
	//����һ������
	initgraph(640, 480); //����ͼ�ߴ�

	loadimage(NULL, L"../src/beijing.jpg");      //����ͼ   ���� ��Ŀ¼ǰ�ӡ�L��

	mciSendString(L"open ../src/ebody.mp3", 0, 0, 0);//������
	mciSendString(L"play ../src/ebody.mp3", 0, 0, 0); //��������

	setlinecolor(BLACK); //������ɫ

	//��������
	for (int i = 1; i < 20; i++)
	{
		line(i * 24, 0, i * 24, 480);
		line(0, i * 24, 480, i * 24);

	}
	line(481, 0, 481, 480);               //���ұ߿���
	line(480, 0, 480, 480);

	settextcolor(RED);              //������ɫ
	setbkmode(0);                    //���屳��
	outtextxy(520, 60, L"���1:����");
	outtextxy(520, 100, L"���2:����");
	outtextxy(520, 160, L"��Ϸ����");
	outtextxy(520, 180, L"���ͬ��ɫ����");
	outtextxy(520, 200, L"�������ڵ�ֱ��");
	outtextxy(520, 220, L"���ɻ��ʤ��");
	outtextxy(520, 240, L"(PS:�����±�Ե");
	outtextxy(520, 260, L"��������)");
	HINSTANCE hinst = GetModuleHandle(NULL); //�߿���
	CreateWindow(TEXT("BUTTON"), TEXT("frame"),
		WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		190, 5, 100, 190, hwndDlg, (HMENU)5000,
		hinst, NULL);

}






//�ж���Ӯ
int whowin(int a, int b)
{  //a-4 a-3 a-2 a-1 a
	//a-3 a-2 a-1 a a+1
	//a-2.......
	//a ......a+4
	int i, j;
	int t = 2 - flag % 2;
	//�����ж���Ӯ
	for (i = a - 4, j = b; i <= a; i++)
	{
		if (i >= 1 && i <= 15 && t == board[i][j] && t == board[i + 1][j] && t == board[i + 2][j] && t == board[i + 3][j] && t == board[i + 4][j])
			return 1;
	}
	//�����ж���Ӯ
	for (j = b - 4, i = a; j <= b; j++)
	{
		if (j >= 1 && j <= 15 /* 20�����Ӽ�ȥ4�� �����Ե*/ && t == board[i][j] && t == board[i][j + 1] && t == board[i][j + 2] && t == board[i][j + 3] && t == board[i][j + 4])
			return 1;
	}
	//б��һ��
	for (i = a - 4, j = b - 4; i <= a, j <= b; i++, j++)
	{
		if (i >= 1 && i <= 15 && j >= 1 && j <= 15 && t == board[i][j] && t == board[i + 1][j + 1] && t == board[i + 2][j + 2] && t == board[i + 3][j + 3] && t == board[i + 4][j + 4])
			return 1;
	}
	//б����һ��
	for (i = a - 4, j = b + 4; i <= a, j >= 1; i++, j--)
	{
		if (i >= 1 && i <= 15 && j >= 1 && j <= 15 && t == board[i][j] && t == board[i + 1][j - 1] && t == board[i + 2][j - 2] && t == board[i + 3][j - 3] && t == board[i + 4][j - 4])
			return 1;
	}
	return 0;

}

//����
void playChess()
{
	//�����
	MOUSEMSG m;
	int a = 0, b = 0;
	int x = 0, y = 0;
	HWND hwnd;              //���ھ��  һ�������ָ��-�����й���  ��־����  ���֤�ţ�
	hwnd = GetHWnd();       //������ǰ
	while (1)
	{
		m = GetMouseMsg(); //��ȡ�����Ϣ
		//����ֵ �ٽ�����
		for (int i = 1; i < 20; i++)
		{
			for (int j = 1; j < 20; j++)
			{
				if (abs(m.x - i * 24) < 10 && abs(m.y - j * 24) < 10)   //abs�����ֵ  һ�����Ӵ�Լ24 һ�뷶ΧС����ж���ȡ10
				{
					a = i; //���к�
					b = j;
					x = i * 24; // ����
					y = j * 24;
				}
			}

		}


		if (m.uMsg == WM_LBUTTONDOWN)//�жϵ�ǰ�����Ϣ�ǲ�������������
		{
			if (board[a][b] != 0)                //������
			{
				MessageBox(hwnd, L"��Ϲ�������������ˣ��ұ�ĵض���", L"��ʾ", MB_OK);   //����������ʾ 
				//�˳�ѭ��
				continue;
			}
			if (flag % 2 == 0)                //ȡ����
			{
				setfillcolor(BLACK);       //��������
				solidcircle(x, y, 8);  //������ĵط�  m.x / 24 * 24 =x  m.y / 24 * 24=y
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
		if (whowin(a, b)) //�ҵ�������������
		{
			if (flag % 2 == 1)
			{
				MessageBox(hwnd, L"���1ʤ��", L"��Ϸ����", MB_OK);
				exit(0);  //�˳�����
			}
			else
			{
				MessageBox(hwnd, L"���2ʤ��", L"��Ϸ����", MB_OK);
				exit(0);  //�˳�����
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


