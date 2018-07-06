#pragma once
#include "Game.hpp"
#include "HGEsingleton.hpp"
#include "hgeSprite.h"
#include "hgeanim.h" 


enum PLAYER_STATE
{
	PS_IDLE,
	PS_WALK,
	PS_FALL,
	// PS_RUN,
	PS_JUMP,
//	PS_DEAD,
	PS_COUNT,
};
enum PLAYER_FACE
{
	PF_LEFT,
	PF_RIGHT,
};

class CPlayer
{
public:
	CPlayer()
	{

	}
	~CPlayer()
	{

	}

	void Init(CMap* m)
	{
		_map = m;
		tex[PS_IDLE] = HGEsgt::Instance().GetHGE()->Texture_Load(".\\snowbro\\idle.png");
  		tex[PS_WALK] = HGEsgt::Instance().GetHGE()->Texture_Load(".\\snowbro\\walk.png");
// 		tex[PS_RUN]  = HGEsgt::Instance().GetHGE()->Texture_Load(".\\snowbro\\run.png");
 		tex[PS_JUMP] = HGEsgt::Instance().GetHGE()->Texture_Load(".\\snowbro\\jump.png");
// 		tex[PS_DEAD] = HGEsgt::Instance().GetHGE()->Texture_Load(".\\snowbro\\dead.png");
	 
		/*
		图中存放了包含20帧动画的图片。
		nframes：指定tex中包含的动画帧数
		FPS：动画播放速度，以帧\秒计数；
		x：第一帧动画的x坐标，一般为0；
		y：第一帧动画的y坐标，一般为0,；
		w：每一帧动画的宽度；
		h：每一帧动画的高度；
		*/
		_ani[PS_IDLE] = new hgeAnimation(tex[PS_IDLE], 1, 20, 0, 0, 71, 71);
		// _ani[PS_IDLE]->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
		_ani[PS_IDLE]->SetSpeed(10);
		
  		_ani[PS_WALK] = new hgeAnimation(tex[PS_WALK], 4, 20, 0, 0, 71, 71);
  		// _ani[PS_WALK]->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
  		_ani[PS_WALK]->SetSpeed(10);

		_ani[PS_JUMP] = new hgeAnimation(tex[PS_JUMP], 8, 20, 0, 0, 71, 71);
		// _ani[PS_JUMP]->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
		_ani[PS_WALK]->SetSpeed(10);

		_ani[PS_FALL] = new hgeAnimation(tex[PS_JUMP], 1, 20, 0, 0, 71, 71);
		// _ani[PS_IDLE]->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
		_ani[PS_FALL]->SetSpeed(10);

		_cur = _ani[PS_IDLE];
		_x = 500;
		_y = 121;
		_velocity = 200.0f;
		_face = PF_RIGHT;
		_state = PS_IDLE;
		_jumping = false;

		_cur->Play();
	}

	void Render(){
		_cur->Render(_x, _y);
		 
		
		const float dis = 0.0f;
		hgeRect r(_rc);
		r.x1 -= dis;
		r.x2 += dis;
		r.y1 -= dis;
		r.y2 += dis;
		HGEsgt::Instance().GetHGE()->Gfx_RenderLine(r.x1, r.y1, r.x2, r.y1, 0xffFF00ff);
		HGEsgt::Instance().GetHGE()->Gfx_RenderLine(r.x2, r.y1, r.x2, r.y2, 0xffFF00ff);
		HGEsgt::Instance().GetHGE()->Gfx_RenderLine(r.x2, r.y2, r.x1, r.y2, 0xffFF00ff);
		HGEsgt::Instance().GetHGE()->Gfx_RenderLine(r.x1, r.y2, r.x1, r.y1, 0xffFF00ff);
	}

	void Frame(){

		

		float dt = HGEsgt::Instance().GetHGE()->Timer_GetDelta();
		GravityHandle(dt);
		KeyHandle(dt);
		UpdateRC();
		_cur->Update(dt); // 更新
	}

	void GravityHandle(float dt)
	{
		float offset = dt * _velocity;
		hgeRect rc(_rc);
		rc.y1 += offset;
		rc.y2 += offset;
		hgeRect colrc;
		bool r = _map->CheckCollision(&rc, &colrc);
		if (r)
		{
			_y = colrc.y1 - 71;
			_jumping = false;
		}
		else{
			_y += offset;
			AniHandle(PS_FALL);
		}
	}

	bool CheckMove(float offsetx, float offsety)
	{
		hgeRect rc(_rc);
		rc.x1 += offsetx;
		rc.x2 += offsetx;
		rc.y1 += offsety;
		rc.y2 += offsety; 
		return !_map->CheckCollision(&rc);
	}

	bool IsFalling(){
		return _state == PS_FALL;
	}

	void KeyHandle(float dt)
	{
		bool bchange = false;
		float offsetx = 0;
		float offsety = 0;
		if (HGEsgt::Instance().GetHGE()->Input_GetKeyState(HGEK_A))
		{
			offsetx = -dt * _velocity;
		}
		if (HGEsgt::Instance().GetHGE()->Input_GetKeyState(HGEK_D))
		{
			offsetx = dt * _velocity;
		}
		if (HGEsgt::Instance().GetHGE()->Input_GetKeyState(HGEK_W))
		{
			offsety = -dt * _velocity;
		}
		if (HGEsgt::Instance().GetHGE()->Input_GetKeyState(HGEK_S))
		{
			offsety = dt * _velocity;
		}

		if (HGEsgt::Instance().GetHGE()->Input_GetKeyState(HGEK_SPACE))
		{
			offsety = -dt * _velocity;
			_jumping = true;
		}


		if (CheckMove(offsetx, offsety))
		{
			if (offsetx > 0)
			{
				_x += offsetx;
				FaceHandle(PF_RIGHT);
				AniHandle(PS_WALK);
				bchange = true;
			}
			else if (offsetx < 0)
			{
				_x += offsetx;
				FaceHandle(PF_LEFT);
				AniHandle(PS_WALK);
				bchange = true;
			}
			if (offsety > 0)
			{
				_y += dt * _velocity;
				AniHandle(PS_WALK);
				bchange = true;
			}
			else if (offsety < 0)
			{
				_y -= (dt * _velocity * 3.5f);
				AniHandle(PS_JUMP);
				bchange = true;
			}
			
		}
		if (!bchange && _state != PS_FALL)
		{
			AniHandle(PS_IDLE);
		}
	}

	void UpdateRC()
	{
		_rc.Set(_x, _y, _x + 71, _y + 71);
	}

	void AniHandle(PLAYER_STATE s)
	{
		if (_state != s)
		{
			_state = s;
			_cur->Stop();
			switch (_state)
			{
			case PS_IDLE:
				_cur = _ani[PS_IDLE];
				break;
			case PS_WALK:
				_cur = _ani[PS_WALK];
				break;
			case PS_FALL:
				_cur = _ani[PS_FALL];
				break;
			case PS_JUMP:
				_cur = _ani[PS_JUMP];
				break;
			default:
				break;
			}
			_cur->Play();
		}
	}
	void FaceHandle(PLAYER_FACE f)
	{
		if (_face != f)
		{
			if (PF_LEFT == f && PF_RIGHT == _face)
			{
				_face = PF_LEFT;
				for (auto a : _ani)
				{
					a->SetFlip(true, false);
				}
				
			}
			else if (PF_RIGHT == f && PF_LEFT == _face)
			{
				_face = PF_RIGHT;
				for (auto a : _ani)
				{
					a->SetFlip(false, false);
				}
			}
		}
	}
protected:
	 
	HTEXTURE tex[PS_COUNT];
	hgeAnimation* _ani[PS_COUNT];
	hgeAnimation* _cur;
	float _x, _y;
	float _velocity; // 移动速度
	float _mass; // 质量
	float _jumpvelocity; // 弹跳力
	PLAYER_FACE _face;
	PLAYER_STATE _state;
	hgeRect _rc;
	CMap* _map;
	bool _jumping;
};
