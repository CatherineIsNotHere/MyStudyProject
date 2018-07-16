

class g_object{
public:
	g_object();
	~g_object();
	void Init();
	virtual void Clean();
	virtual void Frame();
	virtual void Render();
private:
	g_object(const g_object&);//不能类外调用拷贝构造与赋值操作符
	g_object& operator =(const g_object&);
};