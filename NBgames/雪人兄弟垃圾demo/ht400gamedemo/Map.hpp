#pragma once
#include "HGEsingleton.hpp"
#include "hgeSprite.h"
#include <list>
using namespace std;


#define gravity -9.8f

class CMap
{
public:
	CMap()
	{
			 
	}
	~CMap()
	{

	}
	
	void Init()
	{
		tex = HGEsgt::Instance().GetHGE()->Texture_Load(".\\snowbro\\map.png");
		spr = new hgeSprite(tex, 0, 0, BASESCREENW, BASESCREENH);


  		_lst.push_back(hgeRect(0, 0, 1024, 20));
  		_lst.push_back(hgeRect(0, 0, 18, 896));
  		_lst.push_back(hgeRect(1008, 0, 1024, 896));
  		_lst.push_back(hgeRect(0, 800, 1024, 896));

  		_lst.push_back(hgeRect(220, 390,353,584));
  		_lst.push_back(hgeRect(354,532,746,585));
	}

	bool CheckCollision(const hgeRect* other, hgeRect* colrc = nullptr)
	{

 		for (auto rc : _lst)
 		{
 			if (rc.Intersect(other))
 			{
				if (colrc)
				{
					*colrc = rc;
				}
 				return true;
 			}
 		}
		return false;
	}

	void Render(){
		spr->Render(0, 0);

		 

 		for (auto r : _lst)
 		{
 			HGEsgt::Instance().GetHGE()->Gfx_RenderLine(r.x1, r.y1, r.x2, r.y1, 0xffFF00ff);
 			HGEsgt::Instance().GetHGE()->Gfx_RenderLine(r.x2, r.y1, r.x2, r.y2, 0xffFF00ff);
 			HGEsgt::Instance().GetHGE()->Gfx_RenderLine(r.x2, r.y2, r.x1, r.y2, 0xffFF00ff);
 			HGEsgt::Instance().GetHGE()->Gfx_RenderLine(r.x1, r.y2, r.x1, r.y1, 0xffFF00ff);
 		}
	 
		
	}
protected:
	hgeSprite* spr;
	HTEXTURE tex;
	list<hgeRect> _lst;
	 
};
