#include "typeWord.h"

typedWord::typedWord() {

}
typedWord::typedWord(const string wNum, const string EWord, const string CWord)
	:tw_sNum(wNum),
	tw_sEnglishW(EWord),
	tw_sChineseW(CWord)
{
	this->tw_iEWordSize = EWord.length();
	this->tw_iCWordSize = CWord.length() * 2;
}
typedWord::~typedWord() {

}

string typedWord::getSNum() {
	return this->tw_sNum;
}
int typedWord::getIWordLevel() {
	return this->tw_iWordLevel;
}
string typedWord::getSEnglishW() {
	return this->tw_sEnglishW;
}
string typedWord::getSChineseW() {
	return this->tw_sChineseW;
}
int typedWord::getILocationX() {
	return this->tw_iLocationX;
}
int typedWord::getILocationY() {
	return this->tw_iLocationY;
}
int typedWord::getIEWordSize() {
	return this->tw_iEWordSize;
}
int typedWord::getICWordSize() {
	return this->tw_iCWordSize;
}

void typedWord::setSNum(const string wNum) {
	this->tw_sNum = wNum;
}
void typedWord::setIWordLevel(const int level) {
	this->tw_iWordLevel = level;
}
void typedWord::setSEnglishW(const string EWord) {
	this->tw_sEnglishW = EWord;
}
void typedWord::setSChineseW(const string CWord) {
	this->tw_sChineseW = CWord;
}
void typedWord::setILocationX(const int locationX) {
	this->tw_iLocationX = locationX;
}
void typedWord::setILocationY(const int locationY) {
	this->tw_iLocationY = locationY;
}
void typedWord::setIEWordSize(const int size) {
	this->tw_iEWordSize = size;
}
void typedWord::setICWordSize(const int size) {
	this->tw_iCWordSize = size;
}
void typedWord::wordDown() {
	int ptx = this->getILocationX();
	int pty = this->getILocationY();
	int sptx = ptx;
	string word = this->getSEnglishW();
	for (int i = 0; i < this->getIEWordSize(); i++)//清空原单词位置
	{
		gotoxy(sptx + i, pty);
		cout << "  ";
	}
	this->setILocationY(pty + 1);
	pty = this->getILocationY();
	for (string::iterator wdit = word.begin(); wdit != word.end(); wdit++)//打印下落后的单词
	{
		gotoxy(ptx, pty);
		cout << *wdit;
		ptx++;
	}
	ptx = this->getILocationX();
}
void typedWord::wordUp(const int locationX) {

}