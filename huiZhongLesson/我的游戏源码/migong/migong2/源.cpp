#include<stdio.h>//基本库
#include<stdlib.h>//系统库
#include<windows.h>//光标定位、字符颜色函数库
#include<time.h>//时间函数库
#include<conio.h>//键值读入函数库
#define width 40
#define height 40
#define OK 1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW 0
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef bool Status;
unsigned char map[] = {
	0xFF, 0xFF, 0xB0, 0x41, 0x97, 0x5D, 0x94, 0x55, 0x84, 0x05, 0xA4, 0x77, 0xA4, 0x41, 0xBC, 0x41,
	0x87, 0xEF, 0xA0, 0x29, 0xA7, 0xA9, 0xA0, 0xA9, 0xA0, 0xA1, 0xBF, 0xBF, 0x80, 0x81, 0xFF, 0xFF,
};
char pel[] = "  ☆★●□■";

struct xy
{
	int x;
	int y;
	bool flag;
	bool no_entry;
}zuobiao[256] = { 0 };


typedef struct
{
	int ord;
	int dir;
	struct xy pos;
}SElemType;
SElemType foot[50] = { 0 };
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

void color(int b)         //颜色函数 
{
	HANDLE hConsole = GetStdHandle((STD_OUTPUT_HANDLE));
	SetConsoleTextAttribute(hConsole, b);
}
void HideCursor()//隐藏光标
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(hOut, &cursor_info);
}

void gotoxy(int x, int y)//设置字符显示位置
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD loc = { x, y };
	SetConsoleCursorPosition(hOut, loc);

}

void MarkPrint(struct xy curpos)
{
	curpos.no_entry = 1;
}


void drawmap()
{//画场景

	unsigned char draw;
	system("mode con cols=60 lines=32");
	HideCursor();
	gotoxy(10, 5);
	color(14);
	for (int i = 0; i < 32; i++)
	{
		draw = map[i];
		for (int j = 0; j < 8; j++)
		{
			zuobiao[i * 8 + j].x = 10 + (i % 2) * 16 + j * 2;
			zuobiao[i * 8 + j].y = 5 + i / 2;
			if ((draw & 0x80) == 0x80)
			{
				zuobiao[i * 8 + j].no_entry = 1;
				printf("%c%c", pel[10], pel[11]);
			}

			else
				printf("%c%c", pel[8], pel[9]);
			draw <<= 1;

		}
		if (i % 2)
			gotoxy(10, 5 + (i + 1) / 2);
	}

}

void drawstart(struct xy &startpos, struct xy &endpos)
{
	gotoxy(12, 6);
	color(15);
	printf("%c%c", pel[2], pel[3]);
	gotoxy(38, 19);
	printf("%c%c", pel[4], pel[5]);
	gotoxy(10, 22);
	startpos.x = 12, startpos.y = 6;
	startpos.flag = 0; startpos.no_entry = 0;
	endpos.x = 38, endpos.y = 19;
}

Status InitStack(SqStack &S)
{
	S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!S.base)exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status Push(SqStack &S, SElemType e)
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (!S.base)exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack &S, SElemType &e)
{
	if (S.top == S.base)return ERROR;
	e = *--S.top;
	return OK;
}

Status StackEmpty(SqStack S)
{
	if (S.top == S.base)return TRUE;
	return FALSE;
}

Status Pass(struct xy curpos)
{
	if (curpos.flag == 1 || curpos.no_entry == 1)return FALSE;
	else return TRUE;
}

void FootPrint(struct xy curpos)
{
	zuobiao[(curpos.y - 5) * 16 + (curpos.x - 10) / 2].no_entry = 1;
}

struct xy Nextpos(struct xy curpos, int dir)
{
	struct xy pos;
	if (dir == 1)
	{
		pos.x = curpos.x + 2;
		pos.y = curpos.y;
	}

	else if (dir == 2)
	{
		pos.y = curpos.y + 1;
		pos.x = curpos.x;
	}

	else if (dir == 3)
	{
		pos.x = curpos.x - 2;
		pos.y = curpos.y;
	}

	else if (dir == 4)
	{
		pos.y = curpos.y - 1;
		pos.x = curpos.x;
	}
	pos.flag = zuobiao[(pos.y - 5) * 16 + (pos.x - 10) / 2].no_entry;
	pos.no_entry = 0;
	return pos;
}

SElemType step(int i, struct xy curpos, int dir)
{
	SElemType e;
	e.dir = dir;
	e.ord = i;
	e.pos.x = curpos.x;
	e.pos.y = curpos.y;
	e.pos.flag = 1;
	return e;
}

int main()
{
	SqStack S;
	int i = 0;
	struct xy startpos, endpos, curpos = { 0 };
	drawmap();
	drawstart(startpos, endpos);
	InitStack(S);
	curpos = startpos;
	do{
		if (Pass(curpos))
		{
			FootPrint(curpos);
			foot[i] = step(i, curpos, 1);
			Push(S, foot[i]);
			if (curpos.x == endpos.x - 2 && curpos.y == endpos.y)break;
			curpos = Nextpos(curpos, 1);
			i++;
		}
		else{
			if (!StackEmpty(S))
			{
				Pop(S, foot[i]);
				i--;
				while (foot[i].dir == 4 && !StackEmpty(S))
				{
					FootPrint(foot[i].pos);
					Pop(S, foot[i]);
					i--;

				}
				if (foot[i].dir < 4)
				{
					foot[i].dir++;
					Push(S, foot[i]);
					i++;
					curpos = Nextpos(foot[i].pos, foot[i].dir);
				}
			}
		}
	} while (!StackEmpty(S));
	gotoxy(10, 0);
	printf("按回车键显示走迷宫!");
	while (getchar() != '\n');
	for (i = 1; foot[i].ord != 0; i++)
	{
		gotoxy(foot[i].pos.x, foot[i].pos.y);
		color(13);
		printf("%c%c", pel[6], pel[7]);
		Sleep(1000);
	}
	gotoxy(10, 22);
	printf("一共走了%d步!\n", i - 1);
}