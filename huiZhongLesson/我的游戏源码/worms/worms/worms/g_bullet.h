#pragma once
#include "g_object.h"
#include "hgeanim.h"

enum BULLET_FACE{
	BTF_LEFT,
	BTF_RIGHT
};

enum BULLET_STATE{
	BS_NONE,
	BS_FLY
};
enum BOWL_STATE{
	BOS_NONE,
	BOS_BOWL
};


class g_bullet:public g_object{
public:
	g_bullet();
	~g_bullet();
	void Init();
	void Render();
	void Frame();
	void bulletFrame();
	void bowlFrame();
	float getX();
	float getY();
	float getMoveX();
	void setX(float);
	void setMoveX(float);
	void PaintRect();
	void updateDragMove();
	void bulletMove(float, float);
	int checkMove(float,float);
	void setBLBowl(bool);
	bool getBLBowl();
private:
	hgeAnimation* bl_animation;
	hgeAnimation* bl_bowlAni;
	hgeRect* bl_rc;
	float bl_x;
	float bl_y;
	float bl_move_x;
	float bl_rot;
	float bl_hotpotX;
	float bl_hotpotY;
	int bl_state;
	int bl_face;
	float bl_force;
	bool bl_bowl;//ÊÇ·ñ±¬Õ¨Íê
	int bo_state;
	float bl_bowlTime;
	struct bulletPys{
		float bl_velocity;
		float bl_velocityY;
		float bl_velocityX;
		float bl_velocityOldY;
		float bl_distanceX;
		float bl_distanceY;
	}bp;
};