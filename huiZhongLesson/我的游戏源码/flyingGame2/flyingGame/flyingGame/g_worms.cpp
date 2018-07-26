#pragma once
#include "g_worms.h"
#include "dx_hge.h"
#include "g_resourceManager.h"
#include "pys_asvt.h"
#include "m_game.h"


g_worms::g_worms()
{

}

g_worms::~g_worms()
{

}

void g_worms::Init()
{

	w_anime[RS_IDLE_LEFT] = resMgr.getAnimation("虫子.png", 1, 20, 0, 280, 90, 70);
	w_anime[RS_IDLE_LEFT]->SetSpeed(10);
	w_anime[RS_IDLE_RIGHT] = resMgr.getAnimation("虫子.png", 1, 20, 0, 350, 90, 70);
	w_anime[RS_IDLE_RIGHT]->SetSpeed(10);
	w_anime[RS_WALK_LEFT] = resMgr.getAnimation("虫子.png", 6, 20, 0, 280, 90, 70);
	w_anime[RS_WALK_LEFT]->SetSpeed(10);
	w_anime[RS_WALK_RIGHT] = resMgr.getAnimation("虫子.png", 6, 20, 0, 350, 90, 70);
	w_anime[RS_WALK_RIGHT]->SetSpeed(10);
	w_anime[RS_JUMP_LEFT] = resMgr.getAnimation("虫子.png", 4, 20, 0, 0, 90, 70);
	w_anime[RS_JUMP_LEFT]->SetSpeed(10);
	w_anime[RS_JUMP_RIGHT] = resMgr.getAnimation("虫子.png", 4, 20, 0, 70, 90, 70);
	w_anime[RS_JUMP_RIGHT]->SetSpeed(10);
	w_x = 250;
	w_y = 705 - 70 + 10;//705地面高度 70像素图片高度 10 像素图空白高度
	w_rc = new hgeRect(w_x+20,w_y+12,w_x-25+90,w_y-10+70);
	w_move_x = 0;
	wp.w_velocityX = 50.0f;
	wp.w_velocityY = -400.0f;//跳跃速度400
	wp.w_distanceX = .0f;
	wp.w_distanceY = .0f;
	wp.w_velocityOldY = wp.w_velocityY;
	wp.w_weight = 0.f;
	w_state = RS_IDLE_RIGHT;
	w_anime[w_state]->Play();
	w_cur = w_anime[w_state];

}

void g_worms::setX(float x)
{
	w_x = x;
}

void g_worms::setMoveX(float x)
{
	w_move_x = x;
}

float g_worms::getX()
{
	return w_x;
}
void g_worms::Render()
{
	w_cur->Render(w_x + w_move_x, w_y);
	PaintRect();
}

void g_worms::Frame()
{
	float dt = myhge.getHGE()->Timer_GetDelta();
	commonFrame();
	//keyFrame();
	w_cur->Update(dt);
}

void g_worms::commonFrame()
{
	//受重力
	float t = myhge.getDelta();
	float velocityNext = getVelocity(0, 98 * 6, t);//重力加速度6*98
	wp.w_distanceY = getDistanceY(velocityNext, t);
	if (checkMove(wp.w_distanceX, wp.w_distanceY)){
		wormmove(wp.w_distanceX, wp.w_distanceY);
	}
	//如果跳跃中遇到碰撞物则动画还原

}

void g_worms::keyFrame()
{
	if (myhge.getHGE()->Input_GetKeyState(HGEK_RIGHT)){
		if (w_state != RS_WALK_RIGHT && w_state != RS_JUMP_LEFT && w_state != RS_JUMP_RIGHT){//非跳跃正常右走
			w_state = RS_WALK_RIGHT;
			w_cur->Stop();
			w_cur = w_anime[w_state];
			w_cur->Play();
		}
		wp.w_distanceX = myhge.getDelta()*wp.w_velocityX;
		if (checkMove(wp.w_distanceX, wp.w_distanceY)){
			wormmove(wp.w_distanceX, wp.w_distanceY);
		}
	}
	if (myhge.getHGE()->Input_GetKeyState(HGEK_LEFT)){
		if (w_state != RS_WALK_LEFT && w_state != RS_JUMP_LEFT&&w_state != RS_JUMP_RIGHT){//非跳跃正常左走
			w_state = RS_WALK_LEFT;
			w_cur->Stop();
			w_cur = w_anime[w_state];
			w_cur->Play();
		}
		wp.w_distanceX = myhge.getDelta()*wp.w_velocityX*(-1);
		if (checkMove(wp.w_distanceX, wp.w_distanceY)){
			wormmove(wp.w_distanceX, wp.w_distanceY);
		}
	}
	if (myhge.getHGE()->Input_KeyUp(HGEK_RIGHT) && w_state != RS_JUMP_LEFT&&w_state != RS_JUMP_RIGHT){//正常松键（右）
		w_state = RS_IDLE_RIGHT;
		w_cur->Stop();
		w_cur = w_anime[w_state];
		w_cur->Play();
	}
	if (myhge.getHGE()->Input_KeyUp(HGEK_LEFT) && w_state != RS_JUMP_LEFT&&w_state != RS_JUMP_RIGHT){//正常松键（左）
		w_state = RS_IDLE_LEFT;
		w_cur->Stop();
		w_cur = w_anime[w_state];
		w_cur->Play();
	}
	if (myhge.getHGE()->Input_KeyUp(HGEK_SPACE)){//空格抬起预示着跳动作
		if (w_state == RS_IDLE_LEFT || w_state == RS_WALK_LEFT){//面朝左跳
			w_state = RS_JUMP_LEFT;
			w_cur->Stop();
			w_cur = w_anime[w_state];
			w_cur->Play();
		}
		else if (w_state == RS_IDLE_RIGHT || w_state == RS_WALK_RIGHT){//面朝右跳
			w_state = RS_JUMP_RIGHT;
			w_cur->Stop();
			w_cur = w_anime[w_state];
			w_cur->Play();
		}
	}
	if (w_state == RS_JUMP_LEFT || w_state == RS_JUMP_RIGHT){//跳跃
		float t = myhge.getDelta();//飞跃的某时间段
		float velocityNext = getVelocity(wp.w_velocityOldY, 98 * 6, t);//重力加速度6*98
		wp.w_velocityOldY = velocityNext;
		wp.w_distanceY = getDistanceY(velocityNext, t);
		if (checkMove(wp.w_distanceX, wp.w_distanceY)){
			wormmove(wp.w_distanceX, wp.w_distanceY);
		}
	}
	wp.w_distanceX = .0f;
	wp.w_distanceY = .0f;
}

void g_worms::impactFrame()
{
	
}

void g_worms::updateDragMove()
{
	w_rc->x1 += w_move_x;
	w_rc->x2 += w_move_x;
}

int g_worms::checkMove(float distanceX,float distanceY)
{
	hgeRect rc(*w_rc);
	rc.x1 += distanceX;
	rc.x2 += distanceX;
	rc.y1 += distanceY;
	rc.y2 += distanceY;
	mygame.obs.beImpacted(&rc);
	return ;
}

void g_worms::PaintRect()
{
	if (!getPaintLine())
		return;
	else{
		myhge.getHGE()->Gfx_RenderLine(w_rc->x1 + w_move_x, w_rc->y1, w_rc->x2 + w_move_x, w_rc->y1, 0xffff00ff);
		myhge.getHGE()->Gfx_RenderLine(w_rc->x2 + w_move_x, w_rc->y1, w_rc->x2 + w_move_x, w_rc->y2, 0xffff00ff);
		myhge.getHGE()->Gfx_RenderLine(w_rc->x2 + w_move_x, w_rc->y2, w_rc->x1 + w_move_x, w_rc->y2, 0xffff00ff);
		myhge.getHGE()->Gfx_RenderLine(w_rc->x1 + w_move_x, w_rc->y2, w_rc->x1 + w_move_x, w_rc->y1, 0xffff00ff);
	}
}

void g_worms::wormmove(float distanceX, float distanceY)
{
	w_x += distanceX;
	w_y += distanceY;
	w_rc->y1 += distanceY;
	w_rc->y2 += distanceY;
	w_rc->x1 += distanceX;
	w_rc->x2 += distanceX;
}
