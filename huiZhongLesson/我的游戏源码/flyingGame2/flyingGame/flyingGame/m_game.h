#pragma once
#include "dx_hge.h"
#include "g_obstacle.h"
#define mygame m_game::Instance() 

class m_game{
public:
	m_game();
	~m_game();
	void Init();
	void clean();
	static bool Frame();
	static bool Render();
	static m_game& Instance();
	void Run();

	g_obstacle obs;

private:
	m_game(const m_game&);//不能类外调用拷贝构造与赋值操作符
	m_game& operator = (const m_game&);
};