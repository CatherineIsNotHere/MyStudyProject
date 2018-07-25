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
	void setX(float x);
	void setMoveX(float x);
	float getX();
	void keyFrame();//键盘控制
	void impactFrame();//碰撞控制
	void updateWormDragRect();//鼠标拖动后更新虫子碰撞框
private:
	hgeAnimation* w_anime[RS_COUNT];
	hgeAnimation* w_cur;
	hgeRect* w_rc;
	int w_state;
	float w_x;
	float w_y;
	float w_move_x;
	float w_jump_time;
	struct wormPys
	{
		float w_weight;//虫子质量
		float w_velocityX;//虫子移动速度
		float w_velocityY;//虫子跳跃速度
		float w_distanceOldY = .0f;//虫子y移动距离
		float w_distanceOldX = .0f;//虫子x移动距离
		float w_velocityOldY = .0f;//虫子在某时间间隔内的初始速度
	}wp;
};

