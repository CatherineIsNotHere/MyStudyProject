#include "hge.h"
#include "config.h"
#include "poco_foundation_include\Poco\SingletonHolder.h"

class dx_hge{
public:
	dx_hge();
	~dx_hge();
	static dx_hge& Instance();
	HGE* getHGE(){ return hge; };//��ȡhge
	void setProc(hgeCallback ff, hgeCallback rf);//���ü��̼�غ����ͻ��ƺ���
	void BeginRender(DWORD col);//��ʼ����
	void EndRender();//��������
	void Start();//��ʼ����
	HTEXTURE LoadTex(const char*);//��������
	void FreeTex(HTEXTURE);//�ͷ�����
	float getDelta();//��ȡʱ���
	bool getKeyState(int k);//��ȡ����״̬
private:
	dx_hge(const dx_hge&);// ����������ÿ��������븳ֵ������
	dx_hge& operator = (const dx_hge&);
	HGE* hge;

};