#pragma once
#include "g_weapon.h"
#include "g_resourceManager.h"
#include "m_game.h"

g_weapon::g_weapon()
{

}

g_weapon::~g_weapon()
{

}

void g_weapon::Init()
{
	wp_state = WPS_NONE;
	wp_x = .0f;
	wp_y = .0f;
	wp_moveX = .0f;
	wp_rot = 0.0f;
	wp_hotpotX = 47.0f;
	wp_hotpotY = 53.0f;
	wp_radReversal = false;//弧度翻转
	wp_anime[WPS_IDLE_LEFT] = resMgr.getAnimation("虫子.png", 1, 20, 0, 140, 90, 70);
	wp_anime[WPS_IDLE_LEFT]->SetSpeed(10);
	wp_anime[WPS_IDLE_LEFT]->SetHotSpot(wp_hotpotX,wp_hotpotY);
	wp_anime[WPS_IDLE_RIGHT] = resMgr.getAnimation("虫子.png", 1, 20, 0, 210, 90, 70);
	wp_anime[WPS_IDLE_RIGHT]->SetSpeed(10);
	wp_anime[WPS_IDLE_RIGHT]->SetHotSpot(wp_hotpotX, wp_hotpotY);
	wp_anime[WPS_WALK_LEFT] = resMgr.getAnimation("虫子.png", 6, 20, 0, 140, 90, 70);
	wp_anime[WPS_WALK_LEFT]->SetSpeed(10);
	wp_anime[WPS_WALK_LEFT]->SetHotSpot(wp_hotpotX, wp_hotpotY);
	wp_anime[WPS_WALK_RIGHT] = resMgr.getAnimation("虫子.png", 6, 20, 0, 210, 90, 70);
	wp_anime[WPS_WALK_RIGHT]->SetSpeed(10);
	wp_anime[WPS_WALK_RIGHT]->SetHotSpot(wp_hotpotX, wp_hotpotY);
	wp_cur = wp_anime[WPS_IDLE_LEFT];
}

void g_weapon::Render()
{
	if (wp_state!=WPS_NONE){
		wp_cur->RenderEx(wp_x + wp_moveX, wp_y, wp_rot, 1.0f, 1.0f);
	}
}

void g_weapon::Frame()
{
	float dt = myhge.getHGE()->Timer_GetDelta();
	wp_x = mygame.worms.getX()+wp_hotpotX;
	wp_y = mygame.worms.getY()+wp_hotpotY;
	int wormstate = mygame.worms.getState();
	if (myhge.getHGE()->Input_KeyDown(HGEK_E)){//按E显示炮筒
		if (wp_state == WPS_IDLE_RIGHT || wp_state == WPS_IDLE_LEFT || wp_state == WPS_WALK_LEFT || wp_state == WPS_WALK_RIGHT){
			wp_state = WPS_NONE;
		}
		else if (wormstate == RS_IDLE_LEFT || wormstate==RS_JUMP_LEFT){
			wp_state = WPS_IDLE_LEFT;
			wp_cur = wp_anime[wp_state];
		}
		else if (wormstate == RS_WALK_LEFT){
			wp_state = WPS_WALK_LEFT;
			wp_cur = wp_anime[wp_state];
		}
		else if (wormstate == RS_IDLE_RIGHT|| wormstate==RS_JUMP_RIGHT){
			wp_state = WPS_IDLE_RIGHT;
			wp_cur = wp_anime[wp_state];
		}
		else if (wormstate == RS_WALK_RIGHT){
			wp_state = WPS_WALK_RIGHT;
			wp_cur = wp_anime[wp_state];
		}
		wp_cur->Stop();
		wp_cur->Play();
	}
	else if (myhge.getHGE()->Input_GetKeyState(HGEK_W) && !myhge.getHGE()->Input_GetKeyState(HGEK_A) && !myhge.getHGE()->Input_GetKeyState(HGEK_D)){
		if (wp_state == WPS_IDLE_LEFT){
			if (wp_rot >= PI / 2){//如果角度超过90度则扭身
				mygame.worms.setState(RS_IDLE_RIGHT);
				mygame.worms.compelFlush();
				wp_rot=wp_rot*(-1);
				wp_state =WPS_IDLE_RIGHT;
				mygame.weapon.compelFlush();
			}
			else{
				wp_rot += 0.001f;
			}
		}
		else if (wp_state == WPS_IDLE_RIGHT){
			
			if (wp_rot<=PI/2*(-1)){
				mygame.worms.setState(RS_IDLE_LEFT);
				mygame.worms.compelFlush();
				wp_rot = wp_rot*(-1);
				wp_state = WPS_IDLE_LEFT;
				mygame.weapon.compelFlush();
			}
			else{
				wp_rot -= 0.001f;
			}
		}
	}
	else if (myhge.getHGE()->Input_GetKeyState(HGEK_S) && !myhge.getHGE()->Input_GetKeyState(HGEK_A) && !myhge.getHGE()->Input_GetKeyState(HGEK_D)){
		if (wp_state == WPS_IDLE_LEFT){
			if (wp_rot <= PI / 2 * (-1)){
				mygame.worms.setState(RS_IDLE_RIGHT);
				mygame.worms.compelFlush();
				wp_rot = wp_rot*(-1);
				wp_state = WPS_IDLE_RIGHT;
				mygame.weapon.compelFlush();
			}
			else{
				wp_rot -= 0.001f;
			}
		}
		else if (wp_state == WPS_IDLE_RIGHT){
			if (wp_rot >= PI / 2){//如果角度超过90度则扭身
				mygame.worms.setState(RS_IDLE_LEFT);
				mygame.worms.compelFlush();
				wp_rot = wp_rot*(-1);
				wp_state = WPS_IDLE_LEFT;
				mygame.weapon.compelFlush();
			}
			else{
				wp_rot += 0.001f;
			}
		}
	}
	else if (wormstate == RS_IDLE_LEFT && (wp_state != WPS_IDLE_LEFT&&wp_state != WPS_NONE)){//人和武器不是一个方向时调整方向
		if (wp_state != WPS_WALK_LEFT){//如果不是从相同方向停下的话
			wp_radReversal = true;
		}
		wp_state = WPS_IDLE_LEFT;
		wp_cur = wp_anime[wp_state];
		wp_cur->Stop();
		wp_cur->Play();
	}
	else if (wormstate == RS_WALK_LEFT && (wp_state != WPS_WALK_LEFT&&wp_state != WPS_NONE)){
		if (wp_state != WPS_IDLE_LEFT){//如果不是从相同方向停下的话
			wp_radReversal = true;
		}
		wp_state = WPS_WALK_LEFT;
		wp_cur = wp_anime[wp_state];
		wp_cur->Stop();
		wp_cur->Play();
	}
	else if (wormstate == RS_IDLE_RIGHT && (wp_state != WPS_IDLE_RIGHT&&wp_state != WPS_NONE)){
		if (wp_state != WPS_WALK_RIGHT){//如果不是从相同方向停下的话
			wp_radReversal = true;
		}
		wp_state = WPS_IDLE_RIGHT;
		wp_cur = wp_anime[wp_state];
		wp_cur->Stop();
		wp_cur->Play();
	}
	else if (wormstate == RS_WALK_RIGHT && (wp_state != WPS_WALK_RIGHT&&wp_state != WPS_NONE)){
		if (wp_state != WPS_IDLE_RIGHT){//如果不是从相同方向停下的话
			wp_radReversal = true;
		}
		wp_state = WPS_WALK_RIGHT;
		wp_cur = wp_anime[wp_state];
		wp_cur->Stop();
		wp_cur->Play();
	}
	if (wp_radReversal)
	{
		wp_rot = wp_rot*(-1);
		wp_radReversal = false;
	}
	wp_cur->Update(dt);
}

void g_weapon::setX(float x)
{
	wp_x = x;
}

float g_weapon::getX()
{
	return wp_x;
}

float g_weapon::getY()
{
	return wp_y;
}

int g_weapon::getWPState()
{
	return wp_state;
}

float g_weapon::getWPRot()
{
	return wp_rot;
}

void g_weapon::setMoveX(float moveX)
{
	wp_moveX = moveX;
}

void g_weapon::compelFlush()
{
	wp_cur->Stop();
	wp_cur = wp_anime[wp_state];
	wp_cur->Play();
}
