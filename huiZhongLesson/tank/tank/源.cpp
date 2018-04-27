#include <graphics.h>
#include <time.h>

class Bullet;//����ӵ���
class Tank;
class Ebullet;
class Boss;

bool dead = false;
bool wined = false;

struct pos//����
{
	int a;
	int b;
};

class EBullet{//�����ӵ���
public:
	clock_t d;//�����ӵ���ʱ��
	int x;
	int y;//�ӵ�����
	bool on = false;//�Ƿ�����ӵ�

	pos show(){
		setfillcolor(RGB(255, 180, 20));
		fillrectangle(x - 5, y - 5, x + 5, y + 5);
		return pos{ x, y };
	}

	pos del(){//ɾ��ԭ�����ӵ�
		setfillcolor(0);//���汳��ɫ
		setlinecolor(0);//����Ҳ�ͱ���ɫһ��
		fillrectangle(x - 5, y - 5, x + 5, y + 5);
		return pos{ x, y };
	}

	pos move(){//�����ƶ�
		x -= 3;
		return pos{ x, y };
	}
};

class Bullet{//����ӵ���
public:
	clock_t d;//����ӵ���ʱ��
	int x;
	int y;//�ӵ�����
	bool on = false;//�Ƿ�����ӵ�

	pos show(){
		setfillcolor(RGB(150, 180, 210));
		fillrectangle(x - 5, y - 5, x + 5, y + 5);
		return pos{ x, y };
	}

	pos del(){//ɾ��ԭ�����ӵ�
		setfillcolor(0);//���汳��ɫ
		setlinecolor(0);//����Ҳ�ͱ���ɫһ��
		fillrectangle(x - 5, y - 5, x + 5, y + 5);
		return pos{ x, y };
	}

	pos move(){//�����ƶ�
		x += 3;
		return pos{ x, y };
	}
};

class Boss{
public:
	bool hurting = false;//�Ƿ�����
	bool angle = false; //���� false �����ƶ�
	clock_t ftime;//����ʱ��
	clock_t mtime;//�ƶ�ʱ��
	clock_t htime;//����ʱ��

	int x;//��ʾ���˵�����
	int y;
	int hp = 100;

	COLORREF c = RGB(0, 130, 125);

	Boss(int xx, int yy){//���г�ʼ��
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
		setlinecolor(0);//����Ҳ�ͱ���ɫһ��
		fillrectangle(x - 20, y - 40, x + 20, y + 40);
		return pos{ x, y };
	}

	void fire(EBullet &but){
		but.on = true;//���Է����ӵ�
		but.x = x - 20;//�ӵ��ĺ�������
		but.y = y;
		but.d = clock();
	}

	void move(){//�����ƶ�
		if (angle == true){
			y -= 5;
		}
		if (angle == false){
			y += 5;
		}
		if (y >= 440){//����˶����߽�
			angle = true;
		}
		if (y <= 40){
			angle = false;
		}
	}

	void hurt(){
		hp -= 4;
		htime = clock();//��¼����ʱ��
		//����Ѫ����
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
			wined = true;//���Ӯ��
		}
	}
};

class Tank{
public:
	bool hurting = false;//�Ƿ�����
	clock_t ftime;//����ʱ��
	clock_t mtime;//�ƶ�ʱ��
	clock_t htime;//����ʱ��

	int x;//��ʾ���˵�����
	int y;
	int hp = 100;

	COLORREF c = RGB(150, 180, 210);

	Tank(int xx, int yy){//���г�ʼ��
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
		setlinecolor(0);//����Ҳ�ͱ���ɫһ��
		fillrectangle(x - 25, y - 25, x + 25, y + 25);
		rectangle(x - 25, y - 25, x + 25, y + 25);
		fillrectangle(x, x + 5, x + 40, y - 5);
		rectangle(x, x + 5, x + 40, y - 5);
		return pos{ x, y };
	}

	void fire(Bullet &but){
		but.on = true;//���Է����ӵ�
		but.x = x + 45;//�ӵ��ĺ�������
		but.y = y;
		but.d = clock();
		but.show();
	}

	void hurt(){
		hp -= 2;
		htime = clock();//��¼����ʱ��
		//����Ѫ����
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
			wined = true;//���Ӯ��
		}
	}
};

int main(){
	initgraph(640, 550, 4);//��ʼ����Ļ
	//��ʾ
	settextcolor(RGB(0, 255, 0));
	settextstyle(35, 0, L"����");
	outtextxy(150, 200, L"W��S�ƶ���K����");
	Sleep(3000);

	cleardevice();//ˢ����ʾ

	setlinecolor(WHITE);
	setfillcolor(WHITE);
	line(0, 481, 640, 481);//�ָ����Ѫ��

	settextstyle(20, 0, L"����");
	outtextxy(10, 485, L"BOSS����ֵ");
	setfillcolor(RGB(230, 0, 1));
	fillrectangle(160, 485, 560, 510);//����Ѫ��

	outtextxy(10, 520, L"�������ֵ");
	setfillcolor(RGB(0, 255, 1));
	fillrectangle(160, 515, 560, 540);//���Ѫ��
	return 0;
}