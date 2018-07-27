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

	w_anime[RS_IDLE_LEFT] = resMgr.getAnimation("����.png", 1, 20, 0, 280, 90, 70);
	w_anime[RS_IDLE_LEFT]->SetSpeed(10);
	w_anime[RS_IDLE_RIGHT] = resMgr.getAnimation("����.png", 1, 20, 0, 350, 90, 70);
	w_anime[RS_IDLE_RIGHT]->SetSpeed(10);
	w_anime[RS_WALK_LEFT] = resMgr.getAnimation("����.png", 6, 20, 0, 280, 90, 70);
	w_anime[RS_WALK_LEFT]->SetSpeed(10);
	w_anime[RS_WALK_RIGHT] = resMgr.getAnimation("����.png", 6, 20, 0, 350, 90, 70);
	w_anime[RS_WALK_RIGHT]->SetSpeed(10);
	w_anime[RS_JUMP_LEFT] = resMgr.getAnimation("����.png", 4, 20, 0, 0, 90, 70);
	w_anime[RS_JUMP_LEFT]->SetSpeed(10);
	w_anime[RS_JUMP_RIGHT] = resMgr.getAnimation("����.png", 4, 20, 0, 70, 90, 70);
	w_anime[RS_JUMP_RIGHT]->SetSpeed(10);
	w_x = 250;
	w_y = 705 - 70 + 10;//705����߶� 70����ͼƬ�߶� 10 ����ͼ�հ׸߶�
	w_rc = new hgeRect(w_x+20,w_y+12,w_x-25+90,w_y-10+70);
	w_move_x = 0;
	canJumpATT = false;
	wp.w_velocityX = 50.0f;
	wp.w_velocityY = -400.0f;//��Ծ�ٶ�400
	wp.w_distanceX = .0f;
	wp.w_distanceY = .0f;
	wp.w_velocityOldY = wp.w_velocityY;
	wp.w_weight = 0.f;
	wp.w_velocityFall = .0f;
	w_state = RS_IDLE_RIGHT;
	w_anime[w_state]->Play();
	w_cur = w_anime[w_state];

}

void g_worms::setX(float x)
{
	w_x = x;
}

void g_worms::setY(float y)
{
	w_y = y;
}

void g_worms::setMoveX(float x)
{
	w_move_x = x;
}

float g_worms::getX()
{
	return w_x;
}

float g_worms::getY()
{
	return w_y;
}

int g_worms::getState(){
	return w_state;
}

hgeRect* g_worms::getRect()
{
	return w_rc;
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
	keyFrame();
	w_cur->Update(dt);
}

void g_worms::commonFrame()
{
	int impactCommon = checkMove(0, 0.1f);//��������Ƿ��ж���
	if (!wImpactDown(impactCommon)){//�������û�ж���
		//������
		if (w_state != RS_JUMP_LEFT && w_state != RS_JUMP_RIGHT){
			float t = myhge.getDelta();
			float velocityNext = .0f;
			velocityNext = getVelocity(wp.w_velocityFall, 98 * 6, t);
			wp.w_velocityFall = velocityNext;
			wp.w_distanceY = getDistanceY(velocityNext, t);
			wormmove(wp.w_distanceX, wp.w_distanceY);
		}
	}else{
		wp.w_velocityFall = .0f;
		if (w_state == RS_JUMP_RIGHT){
			w_state = RS_IDLE_RIGHT;
			w_cur->Stop();
			w_cur = w_anime[w_state];
			w_cur->Play();
		}
		if (w_state == RS_JUMP_LEFT){
			w_state = RS_IDLE_LEFT;
			w_cur->Stop();
			w_cur = w_anime[w_state];
			w_cur->Play();
		}

	}
	wp.w_distanceY = 0;
	//�����Ծ��������ײ���򶯻���ԭ

}

void g_worms::keyFrame()
{
	if (myhge.getHGE()->Input_GetKeyState(HGEK_RIGHT)){
		if (w_state != RS_WALK_RIGHT && w_state != RS_JUMP_LEFT && w_state != RS_JUMP_RIGHT){//����Ծ��������
			w_state = RS_WALK_RIGHT;
			w_cur->Stop();
			w_cur = w_anime[w_state];
			w_cur->Play();
		}
		wp.w_distanceX = myhge.getDelta()*wp.w_velocityX;
		int cmNum = checkMove(wp.w_distanceX, wp.w_distanceY);
		if (!wImpactRight(cmNum)){
			wormmove(wp.w_distanceX, wp.w_distanceY);
		}
		else{
			return;
		}
	}
	if (myhge.getHGE()->Input_GetKeyState(HGEK_LEFT)){
		if (w_state != RS_WALK_LEFT && w_state != RS_JUMP_LEFT&&w_state != RS_JUMP_RIGHT){//����Ծ��������
			w_state = RS_WALK_LEFT;
			w_cur->Stop();
			w_cur = w_anime[w_state];
			w_cur->Play();
		}
		wp.w_distanceX = myhge.getDelta()*wp.w_velocityX*(-1);
		int cmNum = checkMove(wp.w_distanceX, wp.w_distanceY);
		if (!wImpactLeft(cmNum)){
			wormmove(wp.w_distanceX, wp.w_distanceY);
		}
	}
	if (myhge.getHGE()->Input_KeyUp(HGEK_RIGHT) && w_state != RS_JUMP_LEFT&&w_state != RS_JUMP_RIGHT){//�����ɼ����ң�
		w_state = RS_IDLE_RIGHT;
		w_cur->Stop();
		w_cur = w_anime[w_state];
		w_cur->Play();
	}
	if (myhge.getHGE()->Input_KeyUp(HGEK_LEFT) && w_state != RS_JUMP_LEFT&&w_state != RS_JUMP_RIGHT){//�����ɼ�����
		w_state = RS_IDLE_LEFT;
		w_cur->Stop();
		w_cur = w_anime[w_state];
		w_cur->Play();
	}
	if (myhge.getHGE()->Input_KeyUp(HGEK_SPACE)){//�ո�̧��Ԥʾ��������
		if (!(w_state == RS_JUMP_LEFT || w_state == RS_JUMP_RIGHT) || canJumpATT){//������Ӳ�����Ծ״̬�����Ѿ�װ���������������Ծ
			wp.w_velocityOldY = wp.w_velocityY;
		}
		if (w_state == RS_IDLE_LEFT || w_state == RS_WALK_LEFT){//�泯����
			w_state = RS_JUMP_LEFT;
			w_cur->Stop();
			w_cur = w_anime[w_state];
			w_cur->Play();
		}
		else if (w_state == RS_IDLE_RIGHT || w_state == RS_WALK_RIGHT){//�泯����
			w_state = RS_JUMP_RIGHT;
			w_cur->Stop();
			w_cur = w_anime[w_state];
			w_cur->Play();
		}
		
	}
	if (w_state == RS_JUMP_LEFT || w_state == RS_JUMP_RIGHT){//��Ծ
		float t = myhge.getDelta();//��Ծ��ĳʱ���
		float velocityNext = getVelocity(wp.w_velocityOldY, 98 * 6, t);//�������ٶ�6*98
		wp.w_velocityOldY = velocityNext;
		wp.w_distanceY = getDistanceY(velocityNext, t);
		velocityNext = .0f;
		int cmNum = checkMove(wp.w_distanceX, wp.w_distanceY);
		if (!wImpactUp(cmNum)){
			wormmove(wp.w_distanceX, wp.w_distanceY);
		}
		else{
			wp.w_velocityOldY = 0;
		}

	}
	wp.w_distanceX = .0f;
	wp.w_distanceY = .0f;
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
	return mygame.obs.beImpacted(&rc);
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

bool g_worms::wImpactLeft(int checkNum)
{
	if (checkNum%10==9)//����ײ
		return true;
	return false;
}

bool g_worms::wImpactRight(int checkNum)
{
	if (checkNum / 10 % 10 == 9)//����ײ
		return true;
	return false;
}

bool g_worms::wImpactUp(int checkNum)
{
	if (checkNum / 100 % 10 == 9)//����ײ
		return true;
	return false;
}

bool g_worms::wImpactDown(int checkNum)
{
	if (checkNum / 1000 % 10 == 9)//����ײ
		return true;
	return false;
}

