#pragma once
#include "m_game.h"
#include "dx_hge.h"
#include "g_object.h"
#include "m_gmouse.h"
#include "pys_asvt.h"

m_game::m_game()
{

}

m_game::~m_game()
{

}

void m_game::Init()
{
	gms.gms_click_x = .0f;
	gms.gms_move_x = .0f;
	gms.gms_overmove_x = .0f;
	gms.gms_x = .0f;
	gms.gms_y = .0f;
	gms.gms_stopVelocity = 600.0f;
	gms.gms_borderDistance = .0f;
	gms.gms_isOutOfBorder = MO_NONE;
	maps.Init();
	worms.Init();
	weapon.Init();
	bullet.Init();
	mymouse.Init();
}

void m_game::clean()
{

}

bool m_game::Frame()
{
	mymouse.Frame();
	mygame.worms.Frame();
	mygame.mouseDragStart();
	mygame.mouseDragOver();
	mygame.weapon.Frame();
	mygame.bullet.Frame();
	if (myhge.getKeyState(HGEK_ESCAPE)){
		return true;
	}
	if (myhge.getHGE()->Input_KeyUp(HGEK_P)){
		if (mygame.obs.getPaintLine())
			mygame.obs.setPaintLine(false);
		else
			mygame.obs.setPaintLine(true);
		if (mygame.worms.getPaintLine())
			mygame.worms.setPaintLine(false);
		else
			mygame.worms.setPaintLine(true);
		if (mygame.bullet.getPaintLine())
			mygame.bullet.setPaintLine(false);
		else
			mygame.bullet.setPaintLine(true);
	}
	//mygame.checkRect();
	return false;
}

bool m_game::Render()
{
	myhge.BeginRender(0xffffff);
	mygame.maps.Render();
	mygame.worms.Render();
	mygame.weapon.Render();
	mygame.bullet.Render();
	mygame.obs.Render();
	mymouse.Render();
	myhge.EndRender();
	return false;
}

m_game& m_game::Instance()
{
	static Poco::SingletonHolder<m_game> mgame;
	return *mgame.get();
}

void m_game::Run()
{
	myhge.setProc(Frame,Render);
	mygame.Init();
	myhge.Start();
}

void m_game::mouseDragStart()
{
	if (myhge.getHGE()->Input_KeyDown(HGEK_LBUTTON)){//鼠标按下记录按下坐标
		gms.gms_overmove_x = .0f;
		gms.gms_move_x = .0f;
		myhge.getHGE()->Input_GetMousePos(&gms.gms_x, &gms.gms_y);
		gms.gms_click_x = gms.gms_x;
	}
	if (myhge.getHGE()->Input_GetKeyState(HGEK_LBUTTON)){//鼠标拖动记录位移距离
		myhge.getHGE()->Input_GetMousePos(&gms.gms_x, &gms.gms_y);
		if (((mygame.maps.getX() + gms.gms_x - gms.gms_click_x) <= 0) && (mygame.maps.getX() + gms.gms_x - gms.gms_click_x)>=-2760+B_SCREEN_W){
			gms.gms_move_x = gms.gms_x - gms.gms_click_x;
			mygame.maps.setMoveX(gms.gms_move_x);
			mygame.worms.setMoveX(gms.gms_move_x);
			mygame.obs.setMoveX(gms.gms_move_x);
			mygame.weapon.setMoveX(gms.gms_move_x);
			mygame.bullet.setMoveX(gms.gms_move_x);
		}
	}
	if (myhge.getHGE()->Input_KeyUp(HGEK_LBUTTON)){//鼠标拖动结束将真实坐标传入对象
		mygame.mouseDragclear();
		gms.gms_borderDistance = mygame.maps.getX();
		if (gms.gms_borderDistance > -100){//左出界
			gms.gms_isOutOfBorder = MO_LEFT;
		}
		else if (gms.gms_borderDistance>-2760 + B_SCREEN_W && gms.gms_borderDistance<-2660 + B_SCREEN_W){
			gms.gms_isOutOfBorder = MO_RIGHT;
		}
	}
}

void m_game::mouseDragclear()
{
	gms.gms_overmove_x = gms.gms_move_x;
	mygame.maps.setX(mygame.maps.getX() + gms.gms_overmove_x);
	mygame.maps.setMoveX(0);
	mygame.worms.setX(mygame.worms.getX() + gms.gms_overmove_x);
	mygame.worms.updateDragMove();
	mygame.worms.setMoveX(0);
	mygame.weapon.setX(mygame.weapon.getX() + gms.gms_overmove_x);
	mygame.weapon.setMoveX(0);
	mygame.bullet.setX(mygame.bullet.getX() + gms.gms_overmove_x);
	mygame.bullet.updateDragMove();
	mygame.bullet.setMoveX(0);
	mygame.obs.updateDragMove();
	mygame.obs.setMoveX(0);
}

void m_game::mouseDragOver()
{
	if (gms.gms_isOutOfBorder == MO_LEFT&&!myhge.getHGE()->Input_KeyDown(HGEK_LBUTTON) && !myhge.getHGE()->Input_GetKeyState(HGEK_LBUTTON) && !myhge.getHGE()->Input_KeyUp(HGEK_LBUTTON)){
		float dt = myhge.getDelta();
		float moveDistance = getDistanceX(gms.gms_stopVelocity*(-1),dt);
		mygame.mouseDragBorderMove(moveDistance);
		if (mygame.maps.getX()<=-100){
			gms.gms_isOutOfBorder = MO_NONE;
		}
	}
	else if (gms.gms_isOutOfBorder == MO_RIGHT&&!myhge.getHGE()->Input_KeyDown(HGEK_LBUTTON) && !myhge.getHGE()->Input_GetKeyState(HGEK_LBUTTON) && !myhge.getHGE()->Input_KeyUp(HGEK_LBUTTON)){
		float dt = myhge.getDelta();
		float moveDistance = getDistanceX(gms.gms_stopVelocity, dt);
		mygame.mouseDragBorderMove(moveDistance);
		if (mygame.maps.getX() >= -2660 + B_SCREEN_W){
			gms.gms_isOutOfBorder = MO_NONE;
		}
	}
}

void m_game::mouseDragBorderMove(float distanceX)
{
	mygame.maps.setX(mygame.maps.getX() + distanceX);
	mygame.worms.setMoveX(distanceX);
	mygame.worms.setX(mygame.worms.getX() + distanceX);
	mygame.worms.updateDragMove();
	mygame.weapon.setX(mygame.weapon.getX() + distanceX);
	mygame.bullet.setX(mygame.bullet.getX()+distanceX);
	mygame.bullet.setMoveX(distanceX);
	mygame.bullet.updateDragMove();
	mygame.obs.setMoveX(distanceX);
	mygame.obs.updateDragMove();
	mygame.obs.setMoveX(0);
	mygame.worms.setMoveX(0);
	mygame.bullet.setMoveX(0);
}

void m_game::checkRect()
{
	int checkResult = mygame.obs.checkRect(mygame.worms.getRect());
	//int resultLR = checkResult % 1000;
	int resultUD = checkResult / 1000;
	//int moveLR = 0;
	int moveUD = 0;
	//if (resultLR >= 100 && resultLR < 200){//左嵌入
	//	moveLR = resultLR % 100;
	//}
	//else if (resultLR >= 200 && resultLR < 300)//右嵌入
	//{
	//	moveLR = resultLR % 100 * (-1);
	//}
	if (resultUD>=100&&resultUD<200){//上嵌入
		moveUD = resultUD % 100;
	}
	else if (resultUD>=200&&resultUD<300){//下嵌入
		moveUD = resultUD % 100 * (-1);
	}
	hgeRect* rc = mygame.worms.getRect();
	/*rc->x1 += (float)moveLR;
	rc->x2 += (float)moveLR;*/
	rc->y1 += (float)moveUD;
	rc->y2 += (float)moveUD;
	//mygame.worms.setX(mygame.worms.getX()+moveLR);
	mygame.worms.setY(mygame.worms.getY() + moveUD);
}
