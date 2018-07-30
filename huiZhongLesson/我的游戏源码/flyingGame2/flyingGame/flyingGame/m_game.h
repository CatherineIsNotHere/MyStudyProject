#pragma once
#include "g_obstacle.h"
#include "g_maps.h"
#include "g_worms.h"
#include "g_weapon.h"
#include "g_bullet.h"

#define mygame m_game::Instance() 

enum MAP_OUT{
	MO_NONE,
	MO_LEFT,
	MO_RIGHT
};

class m_game{
public:
	m_game();
	~m_game();
	void Init();//初始化game
	void clean();//清空游戏内存
	static bool Frame();
	static bool Render();
	static m_game& Instance();
	void Run();//运行
	void mouseDragStart();//鼠标拖动
	void mouseDragclear();//鼠标结束移动，坐标移动
	void mouseDragOver();//鼠标结束拖动如果拖到了墙则还原
	void mouseDragBorderMove(float distanceX);
	void checkRect();
	g_obstacle obs;
	g_maps maps;
	g_worms worms;
	g_weapon weapon;
	g_bullet bullet;
private:
	m_game(const m_game&);//不能类外调用拷贝构造与赋值操作符
	m_game& operator = (const m_game&);
	struct gms_for_moveMap
	{
		float gms_x;
		float gms_y;
		float gms_click_x;//鼠标点击时记录x在屏幕中的坐标
		float gms_move_x;//鼠标拖动时记录x拖动距离
		float gms_overmove_x;//鼠标结束拖动时记录总共拖动的距离
		float gms_stopVelocity;//从边框往内移动的速度
		float gms_borderDistance;//出边距离
		int gms_isOutOfBorder;//是否出边
	}gms;
	
};