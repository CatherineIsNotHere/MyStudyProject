#pragma once

extern enum pbstate {//推箱子状态 0空格 1目的地 2墙 4箱子 8工人
	space = 0,
	destination = 1,
	wall = 2,
	box = 4,
	player = 8,

};

extern enum Direction//往哪走
{
	dirNone=0,
	dirUp=-1,
	dirDown=1,
	dirLeft=-2,
	dirRight=2,
};

