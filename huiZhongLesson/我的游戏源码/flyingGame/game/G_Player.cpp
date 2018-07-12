#pragma once
#include "hge.h"
#include "hgeanim.h"
#include "hgeSprite.h" 
enum actionState
{
	P_COMMON = 0,
	P_LEFT_0 = 1,
	P_LEFT_1 = 2,
	P_RIGHT_0 = 3,
	P_RIGHT_1 = 4
};
class G_Player{
public:
	hgeAnimation* p_animat[5];
	HTEXTURE p_tex;
	int p_state = P_COMMON;
	HGE *p_hge;
	int p_x;
	int p_y;
	G_Player(HGE *hge)
		:p_hge(hge)
	{
		p_x = 640 / 2 - 50;
		p_y = 960 / 2 + 180;
		p_tex = p_hge->Texture_Load("飞机1号全.png");
		p_animat[P_COMMON] = new hgeAnimation(p_tex, 5, 60, 0, 0, 100, 90);
		p_animat[P_LEFT_0] = new hgeAnimation(p_tex, 5, 60, 0, 90, 100, 90);
		p_animat[P_LEFT_1] = new hgeAnimation(p_tex, 5, 60, 0, 180, 100, 90);
		p_animat[P_RIGHT_0] = new hgeAnimation(p_tex, 5, 60, 0, 270, 100, 90);
		p_animat[P_RIGHT_1] = new hgeAnimation(p_tex, 5, 60, 0, 360, 100, 90);
		p_animat[P_COMMON]->SetSpeed(10);
		p_animat[P_LEFT_0]->SetSpeed(10);
		p_animat[P_LEFT_1]->SetSpeed(10);
		p_animat[P_RIGHT_0]->SetSpeed(10);
		p_animat[P_RIGHT_1]->SetSpeed(10);
	};

	void PlayerFrame(){
		float dt = p_hge->Timer_GetDelta();
		if (p_hge->Input_GetKeyState(HGEK_LEFT) && !p_hge->Input_GetKeyState(HGEK_RIGHT)){
			if (p_x >= 0 - 20){
				p_x--;
				if (p_state != P_LEFT_0){
					p_state = P_LEFT_0;
				}
			}
			else{
				p_state = P_LEFT_1;
			}
		}
		else if (p_hge->Input_GetKeyState(HGEK_RIGHT) && !p_hge->Input_GetKeyState(HGEK_LEFT)){
			if (p_x <= 640 - 100 + 20){
				p_x++;
				if (p_state != P_RIGHT_0){
					p_state = P_RIGHT_0;
				}
			}
			else{
				p_state = P_RIGHT_1;
			}
		}
		else{
			p_state = P_COMMON;
		}
		if (p_hge->Input_GetKeyState(HGEK_UP)){
			if (p_y >= 0){
				p_y--;
			}
		}
		else if (p_hge->Input_GetKeyState(HGEK_DOWN)){
			if (p_y <= 960 - 90){
				p_y++;
			}
		}
		if (p_hge->Input_GetKeyState(HGEK_NUMPAD0)){
			
		}
		p_animat[p_state]->Update(dt); // 更新
	}
};