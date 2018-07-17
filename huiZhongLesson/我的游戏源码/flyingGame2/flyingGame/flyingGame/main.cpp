#include <windows.h>
#include "m_game.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	mygame.Run();//游戏运行
	mygame.clean();//运行后清理内存
	return 0;
}