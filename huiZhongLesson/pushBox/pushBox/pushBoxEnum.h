#pragma once

extern enum pbstate {//������״̬ 0�ո� 1Ŀ�ĵ� 2ǽ 4���� 8����
	space = 0,
	destination = 1,
	wall = 2,
	box = 4,
	player = 8,

};

extern enum Direction//������
{
	dirNone,
	dirUp,
	dirDown,
	dirLeft,
	dirRight,
};