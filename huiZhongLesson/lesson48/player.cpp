#pragma once
#include "player.h"

MyPlayer::MyPlayer()
{
	_ani[PS_IDLE] = resMgr.GetAni(".\\snowbro\\idle.png", 1,20,0, 0, 36, 36);
	_ani[PS_IDLE]->SetSpeed(10);
	_ani[PS_WALK] = resMgr.GetAni(".\\snowbro\\walk.png", 4,20,0, 0, 36, 36);
	_ani[PS_WALK]->SetSpeed(10);
	_ani[PS_JUMP] = resMgr.GetAni(".\\snowbro\\jump.png", 4,20,0, 0, 36, 36);
	_ani[PS_JUMP]->SetSpeed(10);
	_cur = _ani[PS_IDLE];
	_x = 0;
	_y = 0;
	_velocity = 200.0f;
	_face = PF_LEFT;
	_state = PS_IDLE;
}

MyPlayer::~MyPlayer()
{

}

void MyPlayer::Init()
{

}

void MyPlayer::Render()
{
	_cur->Render(_x,_y);
}

void MyPlayer::Frame()
{
	float td = myhge.GetDelta();
	keyHandle();
	_cur->Update(td);
}

void MyPlayer::SetState(PLAYER_STATE ps)
{
	if (ps!=_state){
		switch (ps)
		{
		case PS_IDLE:
			AniHandle(PS_IDLE);
			break;
		case PS_COUNT:
			AniHandle(PS_COUNT);
			break;
		case PS_WALK:
			AniHandle(PS_WALK);
			break;
		case PS_JUMP:
			AniHandle(PS_JUMP);
			break;
		case PS_FALL:
			AniHandle(PS_FALL);
			break;
		default:
			break;
		}
	}
}

void MyPlayer::AniHandle(PLAYER_STATE ps)
{
	if (ps != _state){
		_state = ps;
		_cur->Stop();
		switch (ps)
		{
		case PS_IDLE:
			_cur = _ani[PS_IDLE];
			break;
		case PS_COUNT:
			_cur = _ani[PS_COUNT];
			break;
		case PS_WALK:
			_cur = _ani[PS_WALK];
			break;
		case PS_JUMP:
			_cur = _ani[PS_JUMP];
			break;
		case PS_FALL:
			_cur = _ani[PS_FALL];
			break;
		default:
			break;
		}
	}
}

void MyPlayer::keyHandle()
{
	if (myhge.GetKeyState(HGEK_LEFT)){
		SetState(PS_WALK);
		FaceHandle(PF_LEFT);
	}
	else if (myhge.GetKeyState(HGEK_RIGHT)){
		SetState(PS_WALK);
		FaceHandle(PF_RIGHT);
	}
	else{
		SetState(PS_IDLE);
	}
}

void MyPlayer::FaceHandle(PLAYER_FACE f)
{
	if (_face!=f){
		if (PF_LEFT==f&&PF_RIGHT==_face){
			_face=PF_LEFT;
			for (auto a:_ani)
			{
				a->SetFlip(true, false);
			}
		}
		else if (PF_RIGHT == f&&PF_LEFT== _face){
			_face = PF_RIGHT;
			for (auto a : _ani)
			{
				a->SetFlip(true, true);
			}
		}
	}
}
