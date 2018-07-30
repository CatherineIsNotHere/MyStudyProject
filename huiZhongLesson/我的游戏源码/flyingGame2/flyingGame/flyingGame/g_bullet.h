#pragma once
#include "g_object.h"
#include "hgeanim.h"

enum BULLET_STATE{
	BS_NONE,
	BS_FLY
};

class g_bullet:public g_object{
public:
	g_bullet();
	~g_bullet();
	void Init();
	void Render();
	void Frame();
	float getX();
	float getY();
	float getMoveX();
	void setX(float);
	void setMoveX(float);
private:
	hgeAnimation* bl_animation;
	float bl_x;
	float bl_y;
	float bl_move_x;
	float bl_rot;
	int bl_state;
	struct bulletPys{
		float bl_velocity;
		float bl_velocityY;
		float bl_velocityX;
		float bl_distanceX;
		float bl_distanceY;
		float bl_distanceOldY;
	}bp;
};