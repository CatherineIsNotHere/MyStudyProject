//#pragma once
//#include "hge.h"
//#include "hgeanim.h"
//#include "hgeSprite.h" 
//#include "G_ResourceManager.cpp"
//#include <list>
//using namespace std;
//
//class G_Bullet{
//public:
//	int b_x;
//	int b_y;
//	hgeSprite * b_spr;
//	G_Bullet(){
//	}
//	G_Bullet(int x,int y)
//		:b_x(x),
//		b_y(y)
//	{
//		b_spr = resMgr.GetSpr("·É»ú1ºÅÈ«.png", 0, 0, 100, 90);
//	}
//	~G_Bullet(){
//	}
//
//};
//
//class G_BulletManager{
//
//public:
//	list<G_Bullet*> p_bullets;
//
//	void add(int x,int y){
//		G_Bullet* bullet = new G_Bullet(x,y);
//		p_bullets.push_back(bullet);
//	}
//};