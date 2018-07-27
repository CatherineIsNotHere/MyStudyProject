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
	wp_anime[WPS_IDLE_LEFT] = resMgr.getAnimation("³æ×Ó.png", 4, 20, 0, 140, 90, 70);
	wp_anime[WPS_IDLE_LEFT]->SetSpeed(5);
	wp_anime[WPS_IDLE_RIGHT] = resMgr.getAnimation("³æ×Ó.png", 4, 20, 0, 210, 90, 70);
	wp_anime[WPS_IDLE_RIGHT]->SetSpeed(5);
	wp_state = WPS_NONE;
	wp_x = .0f;
	wp_y = .0f;
	wp_cur = wp_anime[WPS_IDLE_LEFT];
}

void g_weapon::Render()
{
	if (wp_state!=WPS_NONE){
		wp_cur->Render(mygame.worms.getX(),mygame.worms.getY());
	}
}

void g_weapon::Frame()
{
	float dt = myhge.getHGE()->Timer_GetDelta();
	
	if (myhge.getHGE()->Input_KeyUp(HGEK_E)){
		if (mygame.worms.getState() == RS_IDLE_LEFT){
			wp_state = WPS_IDLE_LEFT;
			wp_cur->Stop();
			wp_cur = wp_anime[wp_state];
			wp_cur->Play();
		}
		else if (mygame.worms.getState() == RS_IDLE_RIGHT){
			wp_state = WPS_IDLE_RIGHT;
			wp_cur->Stop();
			wp_cur = wp_anime[wp_state];
			wp_cur->Play();
		}
	}
	wp_cur->Update(dt);
}
