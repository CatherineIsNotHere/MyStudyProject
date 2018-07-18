#pragma once

class g_object{
public:
	g_object();
	virtual ~g_object();
	void Init();//初始化
	virtual void Clean();//清理
	virtual void Frame();//操作更新
	virtual void Render();//绘制
private:
	g_object(const g_object&);//不能类外调用拷贝构造与赋值操作符
	g_object& operator =(const g_object&);
};