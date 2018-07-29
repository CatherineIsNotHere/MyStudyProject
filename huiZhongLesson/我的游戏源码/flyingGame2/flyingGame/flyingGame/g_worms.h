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
	void PaintRect();//画线
	void setX(float x);
	void setY(float y);
	void setMoveX(float x);
	float getX();
	float getY();
	int getState();
	void setState(int);
	void compelFlush();//强制刷新
	hgeRect* getRect();
	void commonFrame();//非人为控制
	void keyFrame();//键盘控制
	void updateDragMove();//鼠标拖动后更新虫子碰撞框
	int checkMove(float,float);//检测碰撞
	void wormmove(float,float);//虫子移动
	//调用完checkMove方法后需要解析在何方向碰撞
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
		float w_weight;//虫子质量
		float w_velocityX;//虫子移动速度
		float w_velocityY;//虫子跳跃速度
		float w_distanceY;//虫子y移动距离
		float w_distanceX;//虫子x移动距离
		float w_velocityOldY;//虫子在某时间间隔内的初始速度
		float w_velocityFall;
	}wp;
};

