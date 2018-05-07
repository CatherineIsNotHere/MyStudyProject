#pragma once;


extern enum workManDirection
{
	none,
	up,
	down,
	left,
	right,
};

extern enum pbstate{
	space = 0,
	destination = 1,
	wall = 2,
	box = 4,
	player = 8,

};
class workMan{
private:
	char* w_pName;
	char w_cGender;
	int w_iAge;
	int w_iLocationX;
	int w_iLocationY;
	char w_cAvatar;
public:
	workMan();
	workMan(int w_iLocationX, int w_iLocationY);
	~workMan();
	char* getPName();
	char getCGender();
	int getIAge();
	int getILocationX();
	int getILocationY();
	char getCAvatar();
	void setPname(char* pName);
	void setCGender(char cGender);
	void setIAge(int iAge);
	void setILocationY(char avatar);
	void setILocationX(int x);
	void setILocationY(int y);
	void Move(workManDirection drc, int map[][14]);
};

