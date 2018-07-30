#pragma once
#include "g_bullet.h"
#include "g_resourceManager.h"
#include "dx_hge.h"
#include "g_weapon.h"
#include "m_game.h"

g_bullet::g_bullet()
{

}

g_bullet::~g_bullet()
{

}

void g_bullet::Init()
{
	bl_animation = resMgr.getAnimation("×Óµ¯.png",4,20,0,0,50,20);
	bl_x = .0f;
	bl_y = .0f;
	bl_rot = .0f;
	bl_move_x = .0f;
	bp.bl_distanceX = .0f;
	bp.bl_distanceY = .0f;
	bp.bl_distanceOldY=.0f;
	bp.bl_velocity = .0f;
	bp.bl_velocityX = .0f;
	bp.bl_velocityY = .0f;
	bl_state = BS_NONE;
}

void g_bullet::Render()
{
	if (bl_state!=BS_NONE){
		bl_animation->RenderEx(bl_x + bl_move_x, bl_y, 0, 1.0f, 1.0f);
	}
}

void g_bullet::Frame()
{
	float dt = myhge.getDelta();
	if (myhge.getHGE()->Input_KeyUp(HGEK_F)){
		bl_animation->Stop();
		bl_state = BS_FLY;
		bl_animation->Play();

	}
	bl_animation->Update(dt);
}

float g_bullet::getX()
{
	return bl_x;
}

float g_bullet::getY()
{
	return bl_y;
}

float g_bullet::getMoveX()
{
	return bl_move_x;
}

void g_bullet::setX(float)
{

}

void g_bullet::setMoveX(float)
{

}
