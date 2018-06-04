#include "typeWord.h"

typedWord::typedWord() {

}
typedWord::typedWord(const string wNum, const string EWord, const string CWord, const int loationX)
:tw_sNum(wNum),
tw_sEnglishW(EWord),
tw_sChineseW(CWord),
tw_iLocationX(loationX)
{
	this->tw_iEWordSize = EWord.length();
	this->tw_iCWordSize = CWord.length();
	this->tw_iExist = 1;
	this->tw_iLocationY = 0;
	this->tw_iWordLevel = 1;
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
int typedWord::getIExist() {
	return this->tw_iExist;
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
void typedWord::setIExist(const int exist) {
	this->tw_iExist = exist;
}

void typedWord::wordDown() {
	int ptx = this->getILocationX();
	int pty = this->getILocationY();
	string word = this->getSEnglishW();
	pty++;
	this->setILocationY(pty);
	gotoxy(ptx, pty, word, -1);//打印单词
	if (pty>1)
		gotoxy(ptx, pty - 1, " ", this->getIEWordSize());//清空原位置单词
	
}

void typedWord::wordDisappear() {
	int ptx = this->getILocationX();
	int pty = this->getILocationY();
	gotoxy(ptx, pty, " ", this->getIEWordSize());//清空单词
}


void typedWord::wordUp(const int locationX) {

}