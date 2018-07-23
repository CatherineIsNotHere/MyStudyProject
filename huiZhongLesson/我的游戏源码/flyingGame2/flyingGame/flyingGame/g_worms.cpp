#include "g_worms.h"
#include "dx_hge.h"
#include "g_resourceManager.h"

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
	w_y = 705 - 70+10;//705地面高度 70像素图片高度 10 像素图空白高度
	w_move_x = 0;
	w_state = RS_IDLE_RIGHT;
	w_anime[w_state]->Play();
	w_cur = w_anime[w_state];
	
}

void g_worms::Render()
{
	w_cur->Render(w_x+w_move_x, w_y);
}

void g_worms::Frame()
{
	float dt = myhge.getHGE()->Timer_GetDelta();
	if (myhge.getHGE()->Input_GetKeyState(HGEK_RIGHT)){
		if (w_state != RS_WALK_RIGHT){
			w_state = RS_WALK_RIGHT;
			w_cur->Stop();
			w_cur = w_anime[w_state];
			w_cur->Play();
		}
		w_x+=0.2f;
	}
	if (myhge.getHGE()->Input_GetKeyState(HGEK_LEFT)){
		if (w_state != RS_WALK_LEFT){
			w_state = RS_WALK_LEFT;
			w_cur->Stop();
			w_cur = w_anime[w_state];
			w_cur->Play();
		}
		w_x-=0.2f;
	}
	if (myhge.getHGE()->Input_KeyUp(HGEK_RIGHT)){
		w_state = RS_IDLE_RIGHT;
		w_cur->Stop();
		w_cur = w_anime[w_state];
		w_cur->Play();
	}
	if (myhge.getHGE()->Input_KeyUp(HGEK_LEFT)){
		w_state = RS_IDLE_LEFT;
		w_cur->Stop();
		w_cur = w_anime[w_state];
		w_cur->Play();
	}
	if (myhge.getHGE()->Input_KeyUp(HGEK_SPACE)){//空格抬起预示着跳动作
		if (w_state == RS_IDLE_LEFT||w_state==RS_WALK_LEFT){
			w_state = RS_JUMP_LEFT;
			w_cur->Stop();
			w_cur = w_anime[w_state];
			w_cur->Play();
		}
		else if (w_state == RS_IDLE_RIGHT || w_state == RS_WALK_RIGHT){
			w_state = RS_JUMP_RIGHT;
			w_cur->Stop();
			w_cur = w_anime[w_state];
			w_cur->Play();
		}
	}
	if (w_state == RS_JUMP_LEFT || w_state == RS_JUMP_RIGHT){
		w_y -= 0.98*0.5;
	}
	w_cur->Update(dt);
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
