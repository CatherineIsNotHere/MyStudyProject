#pragma once

class g_object{
public:
	g_object();
	virtual ~g_object();
	void Init();//��ʼ��
	virtual void Clean();//����
	virtual void Frame();//��������
	virtual void Render();//����
private:
	g_object(const g_object&);//����������ÿ��������븳ֵ������
	g_object& operator =(const g_object&);
};