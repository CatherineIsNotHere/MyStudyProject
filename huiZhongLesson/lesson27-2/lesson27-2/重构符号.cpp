#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class CMyString{

private:
	char* m_pData;
	int m_iSize;

public:
	CMyString()
		:m_iSize(32)
		, m_pData(nullptr)
	{
		m_pData = new char[m_iSize + 1];
		strcpy_s(m_pData, m_iSize + 1, "");
	}
	CMyString(const char* p){
		m_iSize = strlen(p);
		m_pData = new char[m_iSize + 1];
		strcpy_s(m_pData, m_iSize + 1, p);
	}
	CMyString(const CMyString& r){
		m_iSize = r.m_iSize;
		m_pData = new char[m_iSize + 1];
		strcpy_s(m_pData, m_iSize + 1, r.m_pData);
	}
	~CMyString(){
		delete[] m_pData;
		m_pData = nullptr;
	}
	void operator = (const char* p){//重点  修改等号作用
		setValue(p);
	}
	void operator = (const CMyString& r){
		setValue(r);
	}

	void setValue(const char* p){
		delete[] m_pData;
		m_iSize = strlen(p);
		m_pData = new char[m_iSize + 1];
		strcpy_s(m_pData, m_iSize + 1, p);
	}
	void setValue(const CMyString& r){
		delete[] m_pData;
		m_iSize =r.m_iSize;
		m_pData = new char[m_iSize + 1];
		strcpy_s(m_pData, m_iSize + 1, r.m_pData);
	}

};


void main(){
	CMyString str;
	CMyString str2("abc");
	CMyString str3="def";
	str3 = "xxx";
	str3.operator=("yyy");
	CMyString str4 = "ghi";
	str3 = str4;
	CMyString str5 = str4;
	system("pause");
}