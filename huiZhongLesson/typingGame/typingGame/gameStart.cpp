#include "allSysInclude.h"
#include "sysTools.h"
#include "typeGameEnum.h"
#include "typeWord.h"

string word[2] = { "hello", "world" };


char map[23][36] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

void printMap();//打印地图
int fileToWords();//文件初始化单词
void printKey();//输入栏
void wordMove();//所有单词移动
void checkWord(string str);//检查单词是否正确
int randBar();//随机栏掉落
int typeLetterNum = 0;//输入的字母数量
int letterNum = 1;//下落单词数量
int wordNum = -1;//单词总数，不知道为什么读出来的行数总比实际行数大1
int sleepedTime = 500;
int barNum = 0;//有多少栏掉落单词
int maxStrSize = 0;//最大单词所占长度
int isOver = 0;//游戏结束的标志 1表示结束
string allWordUrl = "./word/word1.popw";
typedWord* tws;//所有单词实体
CRITICAL_SECTION cs;//声明线程锁




void main() {
	HideCursor();
	printMap();
	fileToWords();
	InitializeCriticalSection(&cs);//初始化线程锁
	thread t_wd(wordMove);
	t_wd.detach();
	printKey();
	DeleteCriticalSection(&cs);//销毁线程锁

}


void printMap(){
	for (int i = 0; i < YSize; i++)
	{
		for (int j = 0; j < XSize; j++)
		{
			switch (map[i][j])
			{
			case 1:
				cout << "□";
				break;
			case 0:
				cout << "  ";
				break;
			default:
				cout << map[i][j];
				break;
			}
		}
		cout << endl;
	}
}


int fileToWords() {
	string wordUrl = allWordUrl;
	ifstream ifsNum(wordUrl);
	if (ifsNum.is_open()) {//成功打开
		string cup;
		while (ifsNum) {
			ifsNum >> cup;
			wordNum++;
		}
	}
	else {
		system("cls");
		cout << "单词消失了！" << endl;
	}
	ifsNum.close();
	if (wordNum > 0) {
		ifstream  ifs(wordUrl);
		if (ifs.is_open()) {//成功打开
			int  wordIndex = 0;
			string cup;
			tws = new typedWord[wordNum];//初始化单词实体
			typedWord* tw;
			int size = 0;
			while (wordIndex<wordNum)
			{
				ifs >> cup;
				int fstposi = cup.find("---");
				int endposi = cup.rfind("---");
				tw = new typedWord(cup.substr(0, fstposi), cup.substr(fstposi + 3, endposi - fstposi - 3), cup.substr(endposi + 3), 0);
				size = (tw->getIEWordSize()>tw->getICWordSize() ? tw->getIEWordSize() : tw->getICWordSize());
				if (maxStrSize < size)
					maxStrSize = size;
				tws[wordIndex] = *tw;
				delete tw;
				tw = nullptr;
				wordIndex++;
			}
			barNum = (XSize - 2) * 2 / maxStrSize;//去掉左右两边以最大单词长度为倍数划分单词掉落格
		}
		else {
			system("cls");
			cout << "单词消失了！" << endl;
		}
	}
	else {
		system("cls");
		cout << "单词消失了！" << endl;
	}
	return 0;
}

void wordMove() {
	int i = 0;
	DWORD start, stop;
	start = GetTickCount();//windows一种求时间戳方式精确到毫秒
	int over = 0;
	while (true)
	{
		over = 1;
		Sleep(sleepedTime);
		for (int i = 0; i < letterNum; i++)//遍历所有单词实体
		{
			if (tws[i].getILocationX() == 0)
				tws[i].setILocationX(2 + (randBar()*maxStrSize));
			if (tws[i].getIExist() == 1) {
				over = 0;
				EnterCriticalSection(&cs);//如果keyprint方法正在执行则等待
				if (tws[i].getILocationY() >= YSize - 2){
					tws[i].setIExist(3);
					tws[i].wordDisappear();
				}
				else{
					tws[i].wordDown();
				}
				LeaveCriticalSection(&cs);
			}
			else {
				tws[i].wordDisappear();
			}
		}
		stop = GetTickCount();
		if (stop - start > sleepedTime * 3) {//一般下一个单词的出现时间是下落速度的3倍
			if (letterNum < wordNum)
				letterNum++;
			start = stop;
		}
		if (over)
			break;
	}
	isOver = 1;
}

int randBar(){
	srand((int)time(NULL));
	return rand() % barNum;
}

/*
	打字栏
	*/
void printKey() {
	string str = "";
	while (true) {
		if (!isOver){
			int key = 0;
			stringstream stream;
			string c = "";
			if (_kbhit()) {
				key = _getch();
				if (typeLetterNum > 20 && key != 13 && key != 8)
					continue;
				EnterCriticalSection(&cs);//如果move方法正在执行则等待
				switch (key)
				{
				case 'A':case 'a':case 'B':case 'b':case 'C':case 'c':case 'D':case 'd':case 'E':case 'e':case 'F':case 'f':case 'G'://52个字母
				case 'g':case 'H':case 'h':case 'I':case 'i':case 'J':case 'j':case 'K':case 'k':case 'L':case 'l':case 'M':case 'm':
				case 'N':case 'n':case 'O':case 'o':case 'P':case 'p':case 'Q':case 'q':case 'R':case 'r':case 'S':case 's':case 'T':
				case 't':case 'U':case 'u':case 'V':case 'v':case 'W':case 'w':case 'X':case 'x':case 'Y':case 'y':case 'Z':case 'z':
					stream << (char)key;
					stream >> c;
					str.append(c);
					typeLetterNum++;
					break;
				case 13://回车提交字符
					gotoxy(0, YSize, " ", typeLetterNum);
					checkWord(str);//查看是否有相同单词
					typeLetterNum = 0;
					str.erase();
					break;
				case 8:
					if (typeLetterNum <= 0)
						break;
					gotoxy(0, YSize, " ", typeLetterNum);
					str.erase(typeLetterNum - 1, 1);
					typeLetterNum--;
				default:
					break;
				}
				gotoxy(0, YSize, str, -1);
				LeaveCriticalSection(&cs);
				//gotoxyAndPrint(0, YSize,str);
			}
		}
		else
			break;
	}
}

/*
	查看输入单词是否命中目标
	*/
void checkWord(string str) {
	for (int i = 0; i < wordNum; i++)
	{
		if (str.compare(tws[i].getSEnglishW()) == 0) {
			tws[i].setIExist(0);
			return;
		}
	}
	//system("cls");
	//printMap();

}


/*
	线程锁说明
	*/
//CRITICAL_SECTION cs;//这个CRITICAL_SECTION数据型态是一个结构，但是其中的字段只能由Windows内部使用。这个临界区域对象必须先被程序中的某个线程初始化，
//这样就建立了一个名为cs的临界区域对象。该函数的在线辅助说明包含下面的警告：「临界区域对象不能被移动或者复制，程序也不能修改该对象，但必须在逻辑上把它视为不透明的。」这句话，可以被解释为：「不要干扰它，甚至不要看它。」
//InitializeCriticalSection(&cs);
//当临界区域对象被初始化之后，线程可以通过下面的呼叫进入临界区域：
//EnterCriticalSection(&cs); 
//在这时，线程被认为「拥有」临界区域对象。两个线程不可以同时拥有同一个临界区域对象，因此，如果一个线程进入了临界区域，那么下一个使用同一临界区域对象呼叫EnterCriticalSection的线程将在函数呼叫中被暂停。只有当第一个线程通过下面的呼叫离开临界区域时，函数才会传回控制权：
//LeaveCriticalSection(&cs);
//DeleteCriticalSection(&cs);