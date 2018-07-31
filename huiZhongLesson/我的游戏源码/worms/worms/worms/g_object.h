#pragma once
#define myobject g_object::Instance()
class g_object{
public:
	g_object();
	virtual ~g_object();
	virtual void Init();//��ʼ��
	virtual void Clean();//����
	virtual void Frame();//��������
	virtual void Render();//����
	virtual void setPaintLine(bool);
	virtual bool getPaintLine();
	virtual void paintRect();
	virtual void updateDragMove();
private:
	g_object(const g_object&);//����������ÿ��������븳ֵ������
	g_object& operator =(const g_object&);
	bool o_paintLine;
};