#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#pragma warning(disable:4996)

class CMyString{

private:
	char* m_pData;
	int m_iSize;

public:

	char* getPData(){
		return m_pData;
	}
	int getISize(){
		return m_iSize;
	}
	void setPData(char* st){
		this->m_pData = st;
	}
	void setISize(int s){
		this->m_iSize = s;
	}

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
	CMyString(const char* p, int len)
		:m_iSize(len)
		, m_pData((char*)p)
	{
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

	void operator +=(const char* r){//实现+=
		int size = strlen(r);
		int len = size + m_iSize+1;
		char* p = new char[len];
		strcpy_s(p, m_iSize+1, m_pData);
		strcpy_s(p + m_iSize, size+1, r);
		delete[] m_pData;
		m_pData = p;
		m_iSize += size;
		p = nullptr;
	}

	void operator +=(const CMyString& r){
		int len = r.m_iSize + m_iSize + 1;
		char* p = new char[len];
		strcpy_s(p,m_iSize+1, m_pData);
		strcpy_s(p + m_iSize,r.m_iSize+1, r.m_pData);
		delete[] m_pData;
		m_pData = p;
		m_iSize += r.m_iSize;
		p = nullptr;
	}

	CMyString operator +(const CMyString& r){
		int len = r.m_iSize + m_iSize + 1;
		char* p = new char[len];
		strcpy_s(p, len, m_pData);
		strcpy_s(p + m_iSize, len, r.m_pData);
		return CMyString(p, len);
	}

	char& operator [](int index){
		if (index>m_iSize){
			printf("下标不正确");
			char c = 0;
			return c;
		}
		else{
			return m_pData[index];
		}
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

/*
	符号重载放到外面
*/
//CMyString operator +=(CMyString& left,const CMyString& right){
//	int len = left.getISize + right.getISize + 1;
//	char* p = new char[len];
//	strcpy_s(p, len, left.getPData);
//	strcpy_s(p + left.getISize, len, right.getPData);
//	delete[] left.getPData;
//	left.getPData = p;
//	left.getISize += right.getISize;
//	p = nullptr;
//
//}



void main(){
	//CMyString str;
	//CMyString str2("abc");
	CMyString str3="def";
	//str3 = "xxx";
	//str3.operator=("yyy");
	CMyString str4 = "ghi";
	//str3 = str4;
	CMyString str5 = str4;
	str5 += "aaaa";
	str5 += str3;
	//CMyString str6 = str5 + str4;
	//char c = str6[0];

	//str6[1] = 'z';

	system("pause");
}