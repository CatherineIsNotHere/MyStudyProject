#pragma once
#include "g_object.h"
#include "Poco\SingletonHolder.h"
#include "config.h"

g_object::g_object()
:o_paintLine(O_LINE)
{

}

g_object::~g_object()
{

}

void g_object::Init()
{

}

void g_object::Clean()
{

}

void g_object::Frame()
{

}

void g_object::Render()
{

}

void g_object::setPaintLine(bool b)
{
	o_paintLine = b;
}

bool g_object::getPaintLine()
{
	return o_paintLine;
}

void g_object::paintRect()
{
	return;
}

void g_object::updateDragMove()
{
	return;
}

