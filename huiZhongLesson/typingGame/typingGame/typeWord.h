#pragma once
#include "allSysInclude.h"
#include "sysTools.h"
#include "typeGameEnum.h"
/*
	这是一个单词类
*/
class typedWord {
public:
	typedWord();
	typedWord(const string wNum, const string EWord, const string CWord);
	~typedWord();

	string getSNum();
	int getIWordLevel();
	string getSEnglishW();
	string getSChineseW();
	int getILocationX();
	int getILocationY();
	int getIEWordSize();
	int getICWordSize();
	int getIExist();

	void setSNum(const string wNum);
	void setIWordLevel(const int level);
	void setSEnglishW(const string EWord);
	void setSChineseW(const string CWord);
	void setILocationX(const int locationX);
	void setILocationY(const int locationY);
	void setIEWordSize(const int size);
	void setICWordSize(const int size);
	void setIExist(const int exist);

	void wordDown();//向下
	void wordDisappear();//消失
	void wordUp(const int locationX);

private:
	string tw_sNum;//单词编号
	int tw_iWordLevel;//单词级别
	string tw_sEnglishW;//单词英文
	string tw_sChineseW;//单词中文
	int tw_iLocationX;//单词所在X坐标
	int tw_iLocationY;//单词所在Y坐标
	int tw_iEWordSize;//英文单词长度
	int tw_iCWordSize;//中文单词长度
	int tw_iExist;//出现
};