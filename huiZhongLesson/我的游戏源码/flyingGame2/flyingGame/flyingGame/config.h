//window
#define B_SCREEN_W 1920//宽
#define B_SCREEN_H 960//高

//map
#define M_SCREEN_W 2760
#define M_SCREEN_H 960
#define M_WALL_W 100//墙厚

//worms
#define WORMS_W 90
#define WORMS_H 70
#define W_LEFT_WALKY 280//虫子在图片中的起始纵坐标
#define W_RIGHT_WALKY 350
#define W_LEFT_JUMPY 0
#define W_RIGHT_JUMPY 70
#define W_LEFT_WALKX 0//虫子在图片中的起始纵坐标
#define W_RIGHT_WALKX 0
#define W_LEFT_JUMPX 0
#define W_RIGHT_JUMPX 0
#define W_IDLE_FRAMES 1//虫子共有几帧
#define W_WALK_FRAMES 6
#define W_JUMP_FRAMES 4
#define W_FPS 20
#define W_INITIALX 250
#define W_INITIALY 705 - 70 + 10 //705地面高度 70像素图片高度 10 像素图空白高度
#define W_JUMP_VELOCITY -400.0F
#define W_WALK_VELOCITY 50.0f


//obstacle
#define O_LINE false//是否划线
#define O_NUM 10//障碍物数量

//impact
#define IM_NONE 0
#define IM_LEFT 9
#define IM_RIGHT 90
#define IM_UP 900
#define IM_DOWN 9000

#define IN_NONE 0
#define IN_LEFT 100
#define IN_RIGHT 200
#define IN_UP 100000
#define IN_DOWN 200000

//physics
#define PI 3.14