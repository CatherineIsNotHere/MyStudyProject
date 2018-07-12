#include "include/hgeSprite.h"

class CMap
{
public:
	CMap();
	~CMap();

	void Init();
	void Render();
protected:
	HTEXTURE tex;
	hgeSprite* spr;
};
