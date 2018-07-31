#pragma once
#include <math.h>
#include "g_bullet.h"
#include "g_resourceManager.h"
#include "dx_hge.h"
#include "g_weapon.h"
#include "m_game.h"
#include "pys_asvt.h"

g_bullet::g_bullet()
{

}

g_bullet::~g_bullet()
{

}

void g_bullet::Init()
{
	bl_x = 200.0f;
	bl_y = 200.0f;
	bl_rot = .0f;
	bl_face = BTF_LEFT;
	bl_hotpotX = 25.0f;
	bl_hotpotY = 10.0f;
	bl_move_x = .0f;
	bp.bl_distanceX = .0f;
	bp.bl_distanceY = .0f;
	bp.bl_velocityOldY = .0f;
	bp.bl_velocity = 50.0f;
	bp.bl_velocityX = .0f;
	bp.bl_velocityY = .0f;
	bl_force = 1.0f;
	bl_bowl = false;
	bl_bowlTime = .5f;
	bo_state = BOS_NONE;
	bl_rc = new hgeRect(bl_x-13.0f,bl_y-15.0f,bl_x+17.0f,bl_y+15.0f);
	bl_state = BS_NONE;
	bl_animation = resMgr.getAnimation("子弹.png",4,20,0,0,50,20);
	bl_animation->SetSpeed(10);
	bl_animation->SetHotSpot(bl_hotpotX, bl_hotpotY);
	bl_bowlAni = resMgr.getAnimation("爆炸.png", 4, 20, 0, 50, 50, 50);
	bl_bowlAni->SetSpeed(10);
	bl_bowlAni->SetHotSpot(25.0f, 25.0f);
	bl_bowlAni->Play();
}

void g_bullet::Render()
{
	if (bl_state == BS_FLY){
		bl_animation->RenderEx(bl_x + bl_move_x, bl_y, bl_rot, 1.0f, 1.0f);
		PaintRect();
	}
	if (bo_state == BOS_BOWL){
		bl_bowlAni->RenderEx(bl_x + bl_move_x, bl_y,bl_rot,2.0f,2.0f);
	}
}

void g_bullet::Frame()
{
	bulletFrame();
	bowlFrame();
}

void g_bullet::bulletFrame()
{
	float dt = myhge.getDelta();
	if (myhge.getHGE()->Input_KeyUp(HGEK_F) && bl_state != BS_FLY&& bo_state != BOS_BOWL&&mygame.weapon.getWPState() != WPS_NONE){//按f开火
		bl_animation->Stop();
		bl_state = BS_FLY;
		bl_animation->Play();
		if (mygame.weapon.getWPState() == WPS_IDLE_RIGHT || mygame.weapon.getWPState() == WPS_WALK_RIGHT){
			bl_rot = mygame.weapon.getWPRot();//获取武器弧度
			bl_face = BTF_RIGHT;
		}
		else if (mygame.weapon.getWPState() == WPS_IDLE_LEFT || mygame.weapon.getWPState() == WPS_WALK_LEFT){
			bl_rot = mygame.weapon.getWPRot() + PI;
			bl_face = BTF_LEFT;
		}
		bl_x = mygame.weapon.getX() + cos(bl_rot)*27.0f;
		bl_y = mygame.weapon.getY() - 12.0f + sin(bl_rot)*27.0f;
		bl_rc->x1 = bl_x - 13.0f;
		bl_rc->x2 = bl_x + 17.0f;
		bl_rc->y1 = bl_y - 15.0f;
		bl_rc->y2 = bl_y + 15.0f;
		bp.bl_velocityX = bp.bl_velocity*cos(bl_rot);
		bp.bl_velocityY = bp.bl_velocity*sin(bl_rot);
		bp.bl_velocityOldY = bp.bl_velocityY;
	}
	else if (myhge.getHGE()->Input_GetKeyState(HGEK_F) && bl_state != BS_FLY && bo_state != BOS_BOWL&& mygame.weapon.getWPState() != WPS_NONE){//按f蓄力
		if (bp.bl_velocity <= 1000.0f){
			bp.bl_velocity += bl_force;
		}
	}
	else if (bl_state == BS_FLY){
		float t = myhge.getDelta();//飞跃的某时间段
		float velocityNext = getVelocity(bp.bl_velocityOldY, 98 * 6, t);//重力加速度6*98
		bp.bl_velocityOldY = velocityNext;
		bp.bl_distanceY = getDistanceY(velocityNext, t);
		bp.bl_distanceX = getDistanceX(bp.bl_velocityX, t);
		velocityNext = .0f;
		int shouldMove = checkMove(bp.bl_distanceX, bp.bl_distanceY);
		if (shouldMove == IM_NONE&&bl_y<=M_SCREEN_H){//如果无碰撞且没有出地图边界
			if (bl_face == BTF_RIGHT){
				bl_rot = atan(bp.bl_distanceY / bp.bl_distanceX);
			}
			else{
				bl_rot = atan(bp.bl_distanceY / bp.bl_distanceX) + PI;
			}
			bulletMove(bp.bl_distanceX, bp.bl_distanceY);
		}
		else{
			bl_animation->Stop();
			bl_state = BS_NONE;
			bp.bl_velocityX = .0f;
			bp.bl_velocityY = .0f;
			bp.bl_velocityOldY = .0f;
			bp.bl_velocity = 50.0f;
			bl_bowl = true;
		}
	}
	bl_animation->Update(dt);
}

void g_bullet::bowlFrame()
{
	
	if (bl_bowl){//如果可以爆炸则爆炸然后将状态变为爆炸完
		bl_bowl = false;
		bo_state = BOS_BOWL;
		bl_bowlAni->Play();
	}
	if (bo_state==BOS_BOWL){//如果开始爆炸则计时 到时则爆炸贴图结束
		float dt = myhge.getDelta();
		bl_bowlTime -= dt;
		if (bl_bowlTime <= 0){
			bl_bowlAni->Stop();
			bo_state = BOS_NONE;
			bl_bowlTime = .5f;
		}
		bl_bowlAni->Update(dt);
	}
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

void g_bullet::setX(float x)
{
	bl_x = x;
}

void g_bullet::setMoveX(float movex)
{
	bl_move_x = movex;
}

void g_bullet::PaintRect()
{
	if (!getPaintLine())
		return;
	else{
		myhge.getHGE()->Gfx_RenderLine(bl_rc->x1 + bl_move_x, bl_rc->y1, bl_rc->x2 + bl_move_x, bl_rc->y1, 0xffff00ff);
		myhge.getHGE()->Gfx_RenderLine(bl_rc->x2 + bl_move_x, bl_rc->y1, bl_rc->x2 + bl_move_x, bl_rc->y2, 0xffff00ff);
		myhge.getHGE()->Gfx_RenderLine(bl_rc->x2 + bl_move_x, bl_rc->y2, bl_rc->x1 + bl_move_x, bl_rc->y2, 0xffff00ff);
		myhge.getHGE()->Gfx_RenderLine(bl_rc->x1 + bl_move_x, bl_rc->y2, bl_rc->x1 + bl_move_x, bl_rc->y1, 0xffff00ff);
	}
}

void g_bullet::updateDragMove()
{
	bl_rc->x1 += bl_move_x;
	bl_rc->x2 += bl_move_x;
}

void g_bullet::bulletMove(float distanceX, float distanceY)
{

	bl_x += distanceX;
	bl_y += distanceY;
	bl_rc->y1 += distanceY;
	bl_rc->y2 += distanceY;
	bl_rc->x1 += distanceX;
	bl_rc->x2 += distanceX;
}

int g_bullet::checkMove(float distanceX, float distanceY)
{
	hgeRect rc(*bl_rc);
	rc.x1 += distanceX;
	rc.x2 += distanceX;
	rc.y1 += distanceY;
	rc.y2 += distanceY;
	return mygame.obs.beImpacted(&rc);
}

void g_bullet::setBLBowl(bool b)
{
	bl_bowl = b;
}

bool g_bullet::getBLBowl()
{
	return bl_bowl;
}
