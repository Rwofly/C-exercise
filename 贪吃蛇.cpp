#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define SNAKE_NUM 500
//枚举表示方向
enum DIR
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
//蛇的结构
struct Snake
{
	int size;//蛇的节数
	int dir;//蛇的方向
	int speed;//移动速度
	//坐标表示
	POINT coor[SNAKE_NUM];//POINT是定义好的结构体，内含有long类型的x和y变量
};
//食物结构
struct Food
{
	int x;//x坐标
	int y;
	int r;//食物大小
	bool flag;//食物是否被吃的标记
	DWORD color;//食物颜色
};
//全局变量表示蛇和食物
Snake snake;
Food food;
//数据初始化
void GameInit();
//绘制
void GameDraw();
//移动蛇
void snakemove();
//通过按键改变蛇的运动方向
void keyControl();
//吃食物
void EatFood();
int main()
{
	//initgraph初始化一个图形窗口
	initgraph(640, 480);//参数分别表示y轴和x轴大小
	GameInit();
	while (1)//循环不断绘图
	{
		GameDraw();
		snakemove();
		Sleep(100);//延迟执行代码
		keyControl();
		EatFood();
	}
	int n = getchar();
	return 0;
}
void GameInit()
{
	snake.size = 3;//一开始有三节
	snake.speed = 10;
	snake.dir=RIGHT;
	for (int i=0;i<snake.size;i++)
	{
		snake.coor[i].x = 40 - 10 * i;//确保头在右边
		snake.coor[i].y = 10;
	}
	//使用rand()产生随机数
	srand(time(0));//设置随机数种子
	food.x = rand() % 640;//%640为了确保产生的坐标不会大于640
	food.y = rand() % 480;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.r = rand() % 5 + 5;
	food.flag = true;
	return;
}
void GameDraw()
{
	//双缓冲绘图
	BeginBatchDraw();
	//设置背景颜色
	setbkcolor(RGB(28, 115, 119));
	//清除黑框，显示出设置的颜色
	cleardevice();
	//绘制蛇
	setfillcolor(RED);//设置蛇的颜色
	for (int i = 0;i < snake.size;i++)
	{
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);//x,y,半径
	}
	//绘制食物
	if (food.flag)//如果食物存在
	{
		setfillcolor(food.color);//食物的颜色
		solidcircle(food.x, food.y, food.r);
	}
	//双缓冲结束
	EndBatchDraw();
	return;
}
void snakemove()
{
	//让身体跟着头移动
	for (int i = snake.size-1;i>0;i--)
	{
		snake.coor[i] = snake.coor[i-1];
	}
	switch (snake.dir)
	{
	case RIGHT:
		snake.coor[0].x+=snake.speed;
		if (snake.coor[0].x - 10 >= 640)
		{
			snake.coor[0].x = 0;
		}
		break;
	case UP:
		snake.coor[0].y-=snake.speed;//蛇的上移动
		if (snake.coor[0].y+10 <=0 )//加10表示蛇头触碰边界超出了上面边界
		{
			snake.coor[0].y = 480;//（480为窗口的高）从窗口下出来
		}
		break;
	case LEFT:
		snake.coor[0].x-=snake.speed;
		if (snake.coor[0].x + 10 <= 0)
		{
			snake.coor[0].x = 640;
		}
		break;
		break;
	case DOWN:
		snake.coor[0].y+=snake.speed;
		if (snake.coor[0].y - 10 >= 480)
		{
			snake.coor[0].y = 0;
		}
		break;
	}
	
	return;
}
void keyControl()
{
	//判断有没有按键
	if (_kbhit())//若有按键返回真，没有返回假
	{
		switch (_getch())
		{//72 80 75 77 上下左右键值
		case 'w':
		case 'W':
		case 72:
			//改变方向
			if (snake.dir != DOWN)//用if语句 贪吃蛇不能上下改变方向和左右改变方向
			{
				snake.dir = UP;
			}
			break;
		case 's':
		case 'S':
		case 80:
			if (snake.dir != UP)
			{
				snake.dir = DOWN;
			}
			break;
		case 'a':
		case 'A':
		case 75:
			if (snake.dir != RIGHT)
			{
				snake.dir = LEFT;
			}
			break;
		case 'd':
		case 'D':
		case 77:
			if (snake.dir != LEFT)
			{
				snake.dir = RIGHT;
			}
			break;
		case ' ':
			while (1)
			{
				if (_getch() !=' ')
				{
					return;
				}
			}
			break;
		}
	}
	return;
}
void EatFood()
{
	if (food.flag==true&&snake.coor[0].x >= food.x-food.r && snake.coor[0].x <= food.x + food.r&&
		snake.coor[0].y >= food.y-food.r&& snake.coor[0].y <= food.y + food.r)//在范围内即表示吃到
	{
		food.flag = false;
		snake.size++;//蛇的节数加一
	}
	//如果食物消失，则重新生成一个食物
	if (!food.flag)
	{
		food.x = rand() % 640;//%640为了确保产生的坐标不会大于640
		food.y = rand() % 480;
		food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
		food.r = rand() % 10 + 5;
		food.flag = true;
	}
}