

class g_object{
public:
	g_object();
	~g_object();
	void Init();
	virtual void Clean();
	virtual void Frame();
	virtual void Render();
private:
	g_object(const g_object&);//����������ÿ��������븳ֵ������
	g_object& operator =(const g_object&);
};