#pragma once
#include "include/hge.h"

#define BASESCREENW 256 * 2
#define BASESCREENH 224 * 2
#define myhge MyHGE::Instance()
#define phge MyHGE::Instance().GetHGE()
class MyHGE
{
public:
	MyHGE();
	~MyHGE();
	void SetProc(hgeCallback ff, hgeCallback rf);
	void BeginRender(DWORD col);
	void EndRender();
	void Start();
	static MyHGE& Instance();
	HTEXTURE LoadTex(const char*);
	void FreeTex(HTEXTURE);
	HGE* GetHGE() { return hge; };
	float GetDelta();
	bool GetKeyState(int k);
private:
	MyHGE(const MyHGE&);// ����������ÿ��������븳ֵ������
	MyHGE& operator = (const MyHGE&);
	HGE* hge;
};
