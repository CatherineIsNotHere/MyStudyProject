#include <windows.h>
#include "m_game.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	mygame.Run();//��Ϸ����
	mygame.clean();//���к������ڴ�
	return 0;
}