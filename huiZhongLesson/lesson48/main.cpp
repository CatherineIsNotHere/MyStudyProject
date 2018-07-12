#pragma once
#include "windows.h"
#include "myhge.h"
#include "game.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	mygame.Run();
	mygame.Clean();
	return 0;
}



