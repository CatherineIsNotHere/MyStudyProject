#include "allSysInclude.h"
#include "sysTools.h"
#include "typeGameEnum.h"
#include "typeWord.h"

static char map[23][36] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
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
static void beforeGame();				//��ӡ��Ϸ����
static void printMap();					//��ӡ��ͼ
static int fileToWords();				//��ʼ������
static void printKey();					//������
static void wordMove();					//�����ƶ�
static void checkWord(string str);		//��鵥���Ƿ���ȷ
static int randBar();					//���������
static bool checkOver();				//����Ƿ����
static void overGame();					//��Ϸ������ӡ�ɼ�
static string intToString(const int);	
static int typeLetterNum = 0;//�������ĸ����
static int letterNum = 1;//���䵥������
static int wordNum = -1;//������������֪��Ϊʲô�������������ܱ�ʵ��������1
static int sleepedTime = 1000;
static int barNum = 0;//�ж��������䵥��
static int maxStrSize = 0;//��󵥴���ռ����
static int isOver = 0;//��Ϸ�����ı�־ 1��ʾ����
static int correct = 0;//��ȷ����
static int incorrect = 0;//�������
static string allWordUrl = "./word/word2.popw";
static typedWord* tws;//���е���ʵ��
CRITICAL_SECTION cs;//�����߳���

void main() {
	HideCursor();
	beforeGame();
	printMap();
	if (fileToWords() < 0) {
		system("cls");
		cout << "��ȡ�ļ������޷���������" << endl;
		system("pause");
	}
	InitializeCriticalSection(&cs);//��ʼ���߳���
	thread t_wd(wordMove);
	t_wd.detach();
	printKey();
	t_wd.~thread();
	overGame();
	DeleteCriticalSection(&cs);//�����߳���
	delete[] tws;
	tws = nullptr;
}


static void printMap() {
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
	gotoxy(2 * XSize, 6, "0", -1);
	gotoxy(2 * XSize, 7, "miss��", -1);
	gotoxy(2 * XSize, 8, "0", -1);
}


static int fileToWords() {
	string wordUrl = allWordUrl;
	ifstream ifsNum(wordUrl);
	if (ifsNum.is_open()) {//�ɹ���
		string cup;
		while (ifsNum) {
			ifsNum >> cup;
			wordNum++;
		}
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
			while (wordIndex < wordNum)
			{
				ifs >> cup;
				int fstposi = cup.find("---");
				int endposi = cup.rfind("---");
				tw = new typedWord(cup.substr(0, fstposi), cup.substr(fstposi + 3, endposi - fstposi - 3), cup.substr(endposi + 3), 0);
				size = (tw->getIEWordSize() > tw->getICWordSize() ? tw->getIEWordSize() : tw->getICWordSize());
				if (maxStrSize < size)
					maxStrSize = size;
				tws[wordIndex] = *tw;
				delete tw;
				tw = nullptr;
				wordIndex++;
			}
			barNum = (XSize - 2) * 2 / maxStrSize;//ȥ��������������󵥴ʳ���Ϊ�������ֵ��ʵ����
		}
	}
	gotoxy(2 * XSize, 4, intToString(wordNum), -1);
	return wordNum;
}

/*
	�ƶ��������̣߳�
*/
static void wordMove() {
	int i = 0;
	DWORD start, stop;
	start = GetTickCount();//windowsһ����ʱ�����ʽ��ȷ������
	while (true)
	{
		Sleep(sleepedTime);
		stop = GetTickCount();
		for (int i = 0; i < letterNum; i++)//�������е���ʵ��
		{
			if (tws[i].getILocationX() == 0)//���û������λ������������x����
				tws[i].setILocationX(1 + randBar()*maxStrSize);
			EnterCriticalSection(&cs);//���keyprint��������ִ����ȴ�
			if (tws[i].getIExist() == engExist) {
				if (tws[i].getILocationY() >= YSize - 2) {//������Χ
					incorrect++;//���󵥴�����һ
					gotoxy(2 * XSize, 8, intToString(incorrect), -1);
					tws[i].wordDisappear();
					tws[i].setIExist(overExist);
				}
				else {
					tws[i].wordDown();
				}
			}
			else if (tws[i].getIExist() == cnExist) {//����ֱ������
				if (tws[i].getILocationY() >= YSize - 2) {//������Χ
					tws[i].wordDisappear();
					tws[i].setIExist(overExist);
				}
				else {
					tws[i].wordDown();
				}
			}
			LeaveCriticalSection(&cs);
		}
		if (stop - start > sleepedTime * 3) {//һ����һ�����ʵĳ���ʱ���������ٶȵ�3��
			if (letterNum < wordNum)//���ʶ�������
				letterNum++;
			else if (checkOver())
				break;
			start = stop;
		}
	}
	isOver = 1;
}

/*
	���������
*/
static int randBar() {
	srand((int)time(NULL));
	int rx = rand() % barNum;
	return rx;
}

/*
	������
*/
static void printKey() {
	string str = "";
	while (true) {
		if (!isOver) {
			int key = 0;
			stringstream stream;
			string c = "";
			if (_kbhit()) {
				key = _getch();
				if (typeLetterNum > 20 && key != 13 && key != 8)//������볬��20����ĸ�Ҳ��ǻس������˸��
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
			}
		}
		else
			break;
	}
}

/*
	�鿴���뵥���Ƿ�����Ŀ��
*/
static void checkWord(string str) {
	int i = 0;
	while (i < wordNum) {
		if (tws[i].getIExist() == 1)
			if (str.compare(tws[i].getSEnglishW()) == 0) {
				tws[i].setIExist(2);
				correct++;
				gotoxy(2 * XSize, 6, intToString(correct), -1);
				return;
			}
		i++;
	}
}
/*
	�����Ϸ�Ƿ����
*/
static bool checkOver() {
	bool over = true;
	for (int i = 0; i < letterNum; i++)//�������е���ʵ��
	{
		if (tws[i].getIExist() == 1 || tws[i].getIExist() == 2) {
			over = false;
		}
	}
	return over;
}

/*
	intתstring
*/
static string intToString(const int num) {
	stringstream ss;
	string strss = "";
	ss << num;
	ss >> strss;
	ss.clear();
	return strss;
}

/*
	��Ϸ��ʼǰ��ӡ����
*/
static void beforeGame() {
	gotoxy(6, 6);
	cout << "������Ϸ����" << endl;
	gotoxy(6, 8);
	cout << "�û�������ĸ���������ʣ��������������ʾ�������塣" << endl;
	gotoxy(6, 10);
	cout << "���س���ִ���������ʣ�backspace������������ĸ��" << endl;
	gotoxy(6, 12);
	cout << "�����죡" << endl;
	getchar();
	system("cls");
}

/*
	��Ϸ�������ӡ������
*/
static void overGame() {
	system("cls");
	gotoxy(6, 6);
	cout << "�����" << correct << "������" << endl;
	gotoxy(6, 8);
	cout << "�����" << incorrect << "������" << endl;
	gotoxy(6, 10);
	cout << "�ٽ�����"<< endl;
	getchar();
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