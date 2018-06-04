#include "allSysInclude.h"
#include "sysTools.h"
#include "typeGameEnum.h"
#include "typeWord.h"

string word[2] = { "hello", "world" };


char map[23][36] = { { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
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
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 }
};

void printMap();//��ӡ��ͼ
void printKey();
void checkWord(string str);
int fileToWords();
int typeLetterNum = 0;
int letterNum = 1;
string allWordUrl = "./word/word1.popw";
typedWord* tws;

typedWord* tw1 = new typedWord("001", "hello", "���");
typedWord* tw2 = new typedWord("002", "world", "����");


void wordMove() {
	tws = new typedWord[2];
	int i = 0;
	time_t t1;
	time_t t2;
	tws[0] = *tw1;//todo �ǵö�ȡ�ĵ������е���
	tws[0].setILocationX(10);
	tws[0].setILocationY(0);
	tws[0].setIExist(1);
	tws[1] = *tw2;
	tws[1].setILocationX(20);
	tws[1].setILocationY(0);
	tws[1].setIExist(1);
	time(&t1);
	while (true)
	{
		Sleep(1000);
		for (int i = 0; i < letterNum; i++)
		{
			if (tws[i].getIExist()==1) {
			tws[i].wordDown();
			}
			else {
				tws[i].wordDisappear();
			}
		}
		time(&t2);
		if (t2-t1>=5) {
			if (letterNum<2){//todo �ж��Ƿ�ﵽ������������
				letterNum++;
			}
			t1 = t2;
		}
	}

}

void main() {
	//HideCursor();
	//printMap();
	//thread t_wd(wordMove);
	//t_wd.detach();
	//printKey();

	fileToWords();

	/*thread t_pk(printKey);
	t_pk.join();*///�˴�ʹ���̻߳�ʹ�ô�ӡ�п��ܻ�����ڷ�����
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
}

/*
	������
*/
void printKey() {
	string str = "";
	while (true) {
		int key = 0;
		stringstream stream;
		string c = "";
		if (_kbhit()) {
			key = _getch();
			//gotoxy(typeLetterNum, YSize);
			if (typeLetterNum > 20&&key!=13&&key!=8)
				continue;
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
				for (int i = 0; i < typeLetterNum; i++)
				{
					gotoxy(i, YSize);
					cout << " ";
				}
				//�鿴�Ƿ�����ͬ����
				checkWord(str);
				typeLetterNum = 0;
				str.erase();
				break;
			case 8:
				if (typeLetterNum<=0)
					break;
				for (int i = 0; i < typeLetterNum; i++)
				{
					gotoxy(i, YSize);
					cout << " ";
				}
				str.erase(typeLetterNum-1,1);
				typeLetterNum--;
			default:
				break;
			}
			gotoxy(0, YSize);
			cout << str;
		}
	}
	
}

/*
	�鿴�Ƿ�����ͬ����
*/
void checkWord(string str) {
	for (int i = 0; i < 2; i++)
	{
		if (str.compare(tws[i].getSEnglishW())==0) {
			tws[i].setIExist(0);
			return;
		}
	}
}

int fileToWords() {
	string wordUrl = allWordUrl;
	ifstream ifsNum(wordUrl);
	int wordNum = -1;//��֪��Ϊʲô�������������ܱ�ʵ��������1
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
	if (wordNum>0) {
		ifstream  ifs(wordUrl);
		if (ifs.is_open()) {//�ɹ���
			string cup;
			tws = new typedWord[wordNum];
			
			
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
	return 0;
}