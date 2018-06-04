#pragma once
#include "allSysInclude.h"
#include "sysTools.h"
#include "typeGameEnum.h"
/*
	����һ��������
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

	void wordDown();//����
	void wordDisappear();//��ʧ
	void wordUp(const int locationX);

private:
	string tw_sNum;//���ʱ��
	int tw_iWordLevel;//���ʼ���
	string tw_sEnglishW;//����Ӣ��
	string tw_sChineseW;//��������
	int tw_iLocationX;//��������X����
	int tw_iLocationY;//��������Y����
	int tw_iEWordSize;//Ӣ�ĵ��ʳ���
	int tw_iCWordSize;//���ĵ��ʳ���
	int tw_iExist;//����
};