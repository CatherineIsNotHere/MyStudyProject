#pragma once
#include "hge.h"
#include "config.h"
#include "Poco\SingletonHolder.h"
#define myhge dx_hge::Instance()

class dx_hge{
public:
	dx_hge();
	~dx_hge();
	static dx_hge& Instance();
	HGE* getHGE(){ return hge; };//获取hge
	void setProc(hgeCallback ff, hgeCallback rf);//设置键盘监控函数和绘制函数
	void BeginRender(DWORD col);//开始绘制
	void EndRender();//结束绘制
	void Start();//开始程序
	HTEXTURE LoadTex(const char*);//加载纹理
	void FreeTex(HTEXTURE);//释放纹理
	float getDelta();//获取时间戳
	bool getKeyState(int k);//获取键盘状态
private:
	dx_hge(const dx_hge&);// 不能类外调用拷贝构造与赋值操作符
	dx_hge& operator = (const dx_hge&);
	HGE* hge;

};