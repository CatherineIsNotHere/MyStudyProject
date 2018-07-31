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
	void Init();//��ʼ��game
	void clean();//�����Ϸ�ڴ�
	static bool Frame();
	static bool Render();
	static m_game& Instance();
	void Run();//����
	void mouseDragStart();//����϶�
	void mouseDragclear();//�������ƶ��������ƶ�
	void mouseDragOver();//�������϶�����ϵ���ǽ��ԭ
	void mouseDragBorderMove(float distanceX);
	void checkRect();
	g_obstacle obs;
	g_maps maps;
	g_worms worms;
	g_weapon weapon;
	g_bullet bullet;
private:
	m_game(const m_game&);//����������ÿ��������븳ֵ������
	m_game& operator = (const m_game&);
	struct gms_for_moveMap
	{
		float gms_x;
		float gms_y;
		float gms_click_x;//�����ʱ��¼x����Ļ�е�����
		float gms_move_x;//����϶�ʱ��¼x�϶�����
		float gms_overmove_x;//�������϶�ʱ��¼�ܹ��϶��ľ���
		float gms_stopVelocity;//�ӱ߿������ƶ����ٶ�
		float gms_borderDistance;//���߾���
		int gms_isOutOfBorder;//�Ƿ����
	}gms;
	
};