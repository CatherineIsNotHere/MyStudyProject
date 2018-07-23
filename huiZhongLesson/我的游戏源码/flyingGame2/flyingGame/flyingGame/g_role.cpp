#include "g_role.h"
#include "dx_hge.h"
#include "g_resourceManager.h"

g_role::g_role()
{

}

g_role::~g_role()
{

}

void g_role::Init()
{
	
	r_anime[RS_IDLE_LEFT] = resMgr.getAnimation("虫子.png", 6, 20, 0, 280, 90, 70);
	r_anime[RS_IDLE_LEFT]->SetSpeed(10);
	//r_anime[RS_IDLE_RIGHT] = resMgr.getAnimation("虫子.png", 1, 20, 0, 350, 90, 70);
	//r_anime[RS_IDLE_RIGHT]->SetSpeed(10);
	//r_anime[RS_IDLE_RIGHT]->Play();
	//r_anime[RS_WALK_LEFT] = resMgr.getAnimation("虫子.png", 6, 20, 0, 280, 90, 70);
	//r_anime[RS_WALK_LEFT]->SetSpeed(10);
	//r_anime[RS_WALK_LEFT]->Play();
	//r_anime[RS_WALK_RIGHT] = resMgr.getAnimation("虫子.png", 6, 20, 0, 350, 90, 70);
	//r_anime[RS_WALK_RIGHT]->SetSpeed(10);
	//r_anime[RS_WALK_RIGHT]->Play();
	r_x = 0;
	r_y = 0;
	r_state = RS_IDLE_LEFT;
	r_cur = r_anime[r_state];
	r_cur->Play();
}

void g_role::Render()
{
	r_cur->Render(r_x, r_y);
}

void g_role::Frame()
{
	float dt = myhge.getHGE()->Timer_GetDelta();
	/*if (myhge.getHGE()->Input_GetKeyState(HGEK_LEFT)){
		r_state = RS_WALK_LEFT;
	}
	if (myhge.getHGE()->Input_GetKeyState(HGEK_RIGHT)){
		r_state = RS_WALK_RIGHT;
	}
	if (myhge.getHGE()->Input_KeyUp(HGEK_LEFT)){
		r_state = RS_IDLE_LEFT;
	}
	if (myhge.getHGE()->Input_KeyUp(HGEK_RIGHT)){
		r_state = RS_IDLE_RIGHT;
	}*/
	r_cur->Update(dt);
}
