#pragma once
#include "g_obstacle.h"
#include "g_maps.h"
#include "g_mouse.h"
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
	g_obstacle obs;
	g_maps maps;
	g_mouse mouse;
	
private:
	m_game(const m_game&);//����������ÿ��������븳ֵ������
	m_game& operator = (const m_game&);
	float ms_click_x;//�����ʱ��¼x����Ļ�е�����
	float ms_move_x;//����϶�ʱ��¼x�϶�����
	float ms_overmove_x;//�������϶�ʱ��¼�ܹ��϶��ľ���
};