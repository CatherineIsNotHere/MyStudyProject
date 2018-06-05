#include "allSysInclude.h"
#include "sysTools.h"
#include "typeGameEnum.h"
#include "typeWord.h"

string word[2] = { "hello", "world" };


char map[23][36] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

void printMap();//��ӡ��ͼ
int fileToWords();//�ļ���ʼ������
void printKey();//������
void wordMove();//���е����ƶ�
void checkWord(string str);//��鵥���Ƿ���ȷ
int randBar();//���������
int typeLetterNum = 0;//�������ĸ����
int letterNum = 1;//���䵥������
int wordNum = -1;//������������֪��Ϊʲô�������������ܱ�ʵ��������1
int sleepedTime = 1000;
int bar10Num = 0;//�ж��������䵥��
int maxStrSize = 0;//��󵥴���ռ����
int isOver = 0;//��Ϸ�����ı�־ 1��ʾ����
int correct = 0;//��ȷ����
int incorrect = 0;//�������
string allWordUrl = "./word/word1.popw";
typedWord* tws;//���е���ʵ��
CRITICAL_SECTION cs;//�����߳���




void main() {
	HideCursor();
	printMap();
	fileToWords();
	InitializeCriticalSection(&cs);//��ʼ���߳���
	thread t_wd(wordMove);
	t_wd.detach();
	printKey();
	DeleteCriticalSection(&cs);//�����߳���
	delete[] tws;
	tws = nullptr;
}


void printMap(){
	for (int i = 0; i < YSize; i++)
	{
		for (int j = 0; j < XSize; j++)
		{
			switch (map[i][j])
			{
			case 1:
				cout << "��";
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
	gotoxy(2 * XSize, 3, "������", -1);
	gotoxy(2 * XSize, 5, "��ȷ��", -1);
	gotoxy(2 * XSize, 7, "miss��", -1);
}


int fileToWords() {
	string wordUrl = allWordUrl;
	ifstream ifsNum(wordUrl);
	if (ifsNum.is_open()) {//�ɹ���
		string cup;
		while (ifsNum) {
			ifsNum >> cup;
			wordNum++;
		}
	}
	else {
		system("cls");
		cout << "������ʧ�ˣ�" << endl;
	}
	ifsNum.close();
	if (wordNum > 0) {
		ifstream  ifs(wordUrl);
		if (ifs.is_open()) {//�ɹ���
			int  wordIndex = 0;
			string cup;
			tws = new typedWord[wordNum];//��ʼ������ʵ��
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
			bar10Num = (XSize - 2) * 20 / maxStrSize;//ȥ��������������󵥴ʳ���Ϊ�������ֵ��ʵ����
		}
		else {
			system("cls");
			cout << "������ʧ�ˣ�" << endl;
		}
	}
	else {
		system("cls");
		cout << "������ʧ�ˣ�" << endl;
	}
	stringstream ss;
	string strAllNum = "";
	ss << wordNum;
	ss >> strAllNum;
	gotoxy(2 * XSize, 4, strAllNum, -1);
	return 0;
}

void wordMove() {
	int i = 0;
	DWORD start, stop;
	start = GetTickCount();//windowsһ����ʱ�����ʽ��ȷ������
	while (true)
	{
		Sleep(sleepedTime);
		for (int i = 0; i < letterNum; i++)//�������е���ʵ��
		{
			EnterCriticalSection(&cs);//���keyprint��������ִ����ȴ�
			if (tws[i].getILocationX() == 0)
				tws[i].setILocationX((randBar()*maxStrSize));
			if (tws[i].getIExist() == 1 || tws[i].getIExist() == 2) {
				if (tws[i].getILocationY() >= YSize - 2){
					/*if (tws[i].getIExist() == 1)
					{
						incorrect++;
						stringstream strMiss;
						string strAllMiss;
						strMiss << incorrect;
						strMiss >> strAllMiss;
						gotoxy(2 * XSize, 7, strAllMiss, -1);
					}*/
					tws[i].wordDisappear();
					tws[i].setIExist(3);
				}
				else{
					tws[i].wordDown();
				}
			}
			else {
				tws[i].wordDisappear();
			}
			LeaveCriticalSection(&cs);
		}
		stop = GetTickCount();
		if (stop - start > sleepedTime * 3) {//һ����һ�����ʵĳ���ʱ���������ٶȵ�3��
			if (letterNum < wordNum)
				letterNum++;
			else
				break;
			start = stop;
		}

	}
	isOver = 1;
}

int randBar(){
	srand((int)time(NULL));
	return rand() % bar10Num / 10;
}

/*
	������
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
				EnterCriticalSection(&cs);//���move��������ִ����ȴ�
				switch (key)
				{
				case 'A':case 'a':case 'B':case 'b':case 'C':case 'c':case 'D':case 'd':case 'E':case 'e':case 'F':case 'f':case 'G'://52����ĸ
				case 'g':case 'H':case 'h':case 'I':case 'i':case 'J':case 'j':case 'K':case 'k':case 'L':case 'l':case 'M':case 'm':
				case 'N':case 'n':case 'O':case 'o':case 'P':case 'p':case 'Q':case 'q':case 'R':case 'r':case 'S':case 's':case 'T':
				case 't':case 'U':case 'u':case 'V':case 'v':case 'W':case 'w':case 'X':case 'x':case 'Y':case 'y':case 'Z':case 'z':
					stream << (char)key;
					stream >> c;
					str.append(c);
					typeLetterNum++;
					break;
				case 13://�س��ύ�ַ�
					gotoxy(0, YSize, " ", typeLetterNum);
					checkWord(str);//�鿴�Ƿ�����ͬ����
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
	�鿴���뵥���Ƿ�����Ŀ��
	*/
void checkWord(string str) {
	stringstream ss;
	string strss = "";
	for (int i = 0; i < wordNum; i++)
	{
		if (str.compare(tws[i].getSEnglishW()) == 0) {
			tws[i].setIExist(2);
			correct++;
			ss << correct;
			ss >> strss;
			gotoxy(2 * XSize, 6, strss, -1);
			ss.clear();
			return;
		}
	}
	//system("cls");
	//printMap();

}


/*
	�߳���˵��
	*/
//CRITICAL_SECTION cs;//���CRITICAL_SECTION������̬��һ���ṹ���������е��ֶ�ֻ����Windows�ڲ�ʹ�á�����ٽ������������ȱ������е�ĳ���̳߳�ʼ����
//�����ͽ�����һ����Ϊcs���ٽ�������󡣸ú��������߸���˵����������ľ��棺���ٽ���������ܱ��ƶ����߸��ƣ�����Ҳ�����޸ĸö��󣬵��������߼��ϰ�����Ϊ��͸���ġ�����仰�����Ա�����Ϊ������Ҫ��������������Ҫ��������
//InitializeCriticalSection(&cs);
//���ٽ�������󱻳�ʼ��֮���߳̿���ͨ������ĺ��н����ٽ�����
//EnterCriticalSection(&cs); 
//����ʱ���̱߳���Ϊ��ӵ�С��ٽ�������������̲߳�����ͬʱӵ��ͬһ���ٽ����������ˣ����һ���߳̽������ٽ�������ô��һ��ʹ��ͬһ�ٽ�����������EnterCriticalSection���߳̽��ں��������б���ͣ��ֻ�е���һ���߳�ͨ������ĺ����뿪�ٽ�����ʱ�������Żᴫ�ؿ���Ȩ��
//LeaveCriticalSection(&cs);
//DeleteCriticalSection(&cs);