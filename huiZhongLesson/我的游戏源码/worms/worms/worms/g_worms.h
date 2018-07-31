#pragma once
#include "g_object.h"
#include "hgeanim.h"

enum ROLE_STATE
{
	RS_IDLE_LEFT,
	RS_IDLE_RIGHT,
	RS_WALK_LEFT,
	RS_WALK_RIGHT,
	RS_JUMP_LEFT,
	RS_JUMP_RIGHT,
	RS_FALL,
	RS_COUNT,
};

class g_worms :public g_object{
public:
	g_worms();
	~g_worms();
	void Init();
	void Render();
	void Frame();
	void PaintRect();//����
	void setX(float x);
	void setY(float y);
	void setMoveX(float x);
	float getX();
	float getY();
	int getState();
	void setState(int);
	void compelFlush();//ǿ��ˢ��
	hgeRect* getRect();
	void commonFrame();//����Ϊ����
	void keyFrame();//���̿���
	void updateDragMove();//����϶�����³�����ײ��
	int checkMove(float,float);//�����ײ
	void wormmove(float,float);//�����ƶ�
	//������checkMove��������Ҫ�����ںη�����ײ
	bool wImpactLeft(int);
	bool wImpactRight(int);
	bool wImpactUp(int);
	bool wImpactDown(int);

private:
	hgeAnimation* w_anime[RS_COUNT];
	hgeAnimation* w_cur;
	hgeRect* w_rc;
	int w_state;
	float w_x;
	float w_y;
	float w_move_x;
	bool canJumpATT;//can jump all the time
	struct wormPys
	{
		float w_weight;//��������
		float w_velocityX;//�����ƶ��ٶ�
		float w_velocityY;//������Ծ�ٶ�
		float w_distanceY;//����y�ƶ�����
		float w_distanceX;//����x�ƶ�����
		float w_velocityOldY;//������ĳʱ�����ڵĳ�ʼ�ٶ�
		float w_velocityFall;
	}wp;
};

