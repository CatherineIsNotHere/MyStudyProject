#pragma once
#include "g_obstacle.h"
#include "g_maps.h"
#include "g_mouse.h"
#include "g_worms.h"
#include "g_weapon.h"

#define mygame m_game::Instance() 

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
	void mouseDrag();//����϶�
	void checkRect();
	g_obstacle obs;
	g_maps maps;
	g_mouse mouse;
	g_worms worms;
	g_weapon weapon;
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
	}gms;
	
};