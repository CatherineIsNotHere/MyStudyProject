#include <graphics.h>
#include <time.h>

class Bullet;//玩家子弹类
class Tank;
class Ebullet;
class Boss;

bool dead = false;
bool wined = false;

struct pos//坐标
{
	int a;
	int b;
};

class EBullet{//敌人子弹类
public:
	clock_t d;//敌人子弹的时间
	int x;
	int y;//子弹坐标
	bool on = false;//是否放置子弹

	pos show(){
		setfillcolor(RGB(255, 180, 20));
		fillrectangle(x - 5, y - 5, x + 5, y + 5);
		return pos{ x, y };
	}

	pos del(){//删除原来的子弹
		setfillcolor(0);//跟随背景色
		setlinecolor(0);//线条也和背景色一样
		fillrectangle(x - 5, y - 5, x + 5, y + 5);
		return pos{ x, y };
	}

	pos move(){//向左移动
		x -= 3;
		return pos{ x, y };
	}
};

class Bullet{//玩家子弹类
public:
	clock_t d;//玩家子弹的时间
	int x;
	int y;//子弹坐标
	bool on = false;//是否放置子弹

	pos show(){
		setfillcolor(RGB(150, 180, 210));
		fillrectangle(x - 5, y - 5, x + 5, y + 5);
		return pos{ x, y };
	}

	pos del(){//删除原来的子弹
		setfillcolor(0);//跟随背景色
		setlinecolor(0);//线条也和背景色一样
		fillrectangle(x - 5, y - 5, x + 5, y + 5);
		return pos{ x, y };
	}

	pos move(){//向左移动
		x += 3;
		return pos{ x, y };
	}
};

class Boss{
public:
	bool hurting = false;//是否受伤
	bool angle = false; //方向 false 向下移动
	clock_t ftime;//开火时间
	clock_t mtime;//移动时间
	clock_t htime;//受伤时间

	int x;//表示敌人的坐标
	int y;
	int hp = 100;

	COLORREF c = RGB(0, 130, 125);

	Boss(int xx, int yy){//进行初始化
		x = xx;
		y = yy;
	}

	pos show(){
		setfillcolor(c);
		fillrectangle(x - 20, y - 40, x + 20, y + 40);
		return pos{ x, y };
	}

	pos del(){
		setfillcolor(0);
		setlinecolor(0);//线条也和背景色一样
		fillrectangle(x - 20, y - 40, x + 20, y + 40);
		return pos{ x, y };
	}

	void fire(EBullet &but){
		but.on = true;//可以放置子弹
		but.x = x - 20;//子弹的横纵坐标
		but.y = y;
		but.d = clock();
	}

	void move(){//上下移动
		if (angle == true){
			y -= 5;
		}
		if (angle == false){
			y += 5;
		}
		if (y >= 440){//如果运动到边界
			angle = true;
		}
		if (y <= 40){
			angle = false;
		}
	}

	void hurt(){
		hp -= 4;
		htime = clock();//记录受伤时间
		//绘制血量条
		setfillcolor(0);
		setlinecolor(WHITE);
		fillrectangle(160, 485, 560, 510);
		rectangle(160, 485, 160 + hp * 4, 510);

		setfillcolor(RGB(230, 0, 0));
		setlinecolor(WHITE);
		fillrectangle(160, 485, 160 + hp * 4, 510);
		rectangle(160, 485, 160 + hp * 4, 510);

		hurting = true;
		if (hp <= 0){
			wined = true;//玩家赢了
		}
	}
};

class Tank{
public:
	bool hurting = false;//是否受伤
	clock_t ftime;//开火时间
	clock_t mtime;//移动时间
	clock_t htime;//受伤时间

	int x;//表示敌人的坐标
	int y;
	int hp = 100;

	COLORREF c = RGB(150, 180, 210);

	Tank(int xx, int yy){//进行初始化
		x = xx;
		y = yy;
	}

	pos show(){
		setfillcolor(c);
		fillrectangle(x - 25, y - 25, x + 25, y + 25);
		setfillcolor(RGB(100, 200, 180));
		fillrectangle(x, x + 5, x + 40, y - 5);
		return pos{ x, y };
	}

	pos del(){
		setfillcolor(0);
		setlinecolor(0);//线条也和背景色一样
		fillrectangle(x - 25, y - 25, x + 25, y + 25);
		rectangle(x - 25, y - 25, x + 25, y + 25);
		fillrectangle(x, x + 5, x + 40, y - 5);
		rectangle(x, x + 5, x + 40, y - 5);
		return pos{ x, y };
	}

	void fire(Bullet &but){
		but.on = true;//可以放置子弹
		but.x = x + 45;//子弹的横纵坐标
		but.y = y;
		but.d = clock();
		but.show();
	}

	void hurt(){
		hp -= 2;
		htime = clock();//记录受伤时间
		//绘制血量条
		setfillcolor(0);
		setlinecolor(WHITE);
		fillrectangle(160, 485, 560, 510);
		rectangle(160, 485, 160 + hp * 4, 510);

		setfillcolor(RGB(230, 0, 0));
		setlinecolor(WHITE);
		fillrectangle(160, 485, 160 + hp * 4, 510);
		rectangle(160, 485,  160 + hp * 4, 510);

		hurting = true;
		if (hp <= 0){
			wined = true;//玩家赢了
		}
	}
};

int main(){
	initgraph(640, 550, 4);//初始化屏幕
	//提示
	settextcolor(RGB(0, 255, 0));
	settextstyle(35, 0, L"黑体");
	outtextxy(150, 200, L"W，S移动，K攻击");
	Sleep(3000);

	cleardevice();//刷新提示

	setlinecolor(WHITE);
	setfillcolor(WHITE);
	line(0, 481, 640, 481);//分割画面与血条

	settextstyle(20, 0, L"黑体");
	outtextxy(10, 485, L"BOSS生命值");
	setfillcolor(RGB(230, 0, 1));
	fillrectangle(160, 485, 560, 510);//敌人血条

	outtextxy(10, 520, L"玩家生命值");
	setfillcolor(RGB(0, 255, 1));
	fillrectangle(160, 515, 560, 540);//玩家血条
	return 0;
}