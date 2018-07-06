#include "Game.hpp"
 
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	CGame::Instance().Run();
	return 0;
}