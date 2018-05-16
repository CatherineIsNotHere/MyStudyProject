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
	dirNone,
	dirUp,
	dirDown,
	dirLeft,
	dirRight,
};