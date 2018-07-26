#pragma once
#define myobject g_object::Instance()
class g_object{
public:
	g_object();
	virtual ~g_object();
	virtual void Init();//初始化
	virtual void Clean();//清理
	virtual void Frame();//操作更新
	virtual void Render();//绘制
	virtual void setPaintLine(bool);
	virtual bool getPaintLine();
	virtual void paintRect();
	virtual void updateDragMove();
private:
	g_object(const g_object&);//不能类外调用拷贝构造与赋值操作符
	g_object& operator =(const g_object&);
	bool o_paintLine;
};