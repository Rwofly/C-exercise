#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define SNAKE_NUM 500
//ö�ٱ�ʾ����
enum DIR
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
//�ߵĽṹ
struct Snake
{
	int size;//�ߵĽ���
	int dir;//�ߵķ���
	int speed;//�ƶ��ٶ�
	//�����ʾ
	POINT coor[SNAKE_NUM];//POINT�Ƕ���õĽṹ�壬�ں���long���͵�x��y����
};
//ʳ��ṹ
struct Food
{
	int x;//x����
	int y;
	int r;//ʳ���С
	bool flag;//ʳ���Ƿ񱻳Եı��
	DWORD color;//ʳ����ɫ
};
//ȫ�ֱ�����ʾ�ߺ�ʳ��
Snake snake;
Food food;
//���ݳ�ʼ��
void GameInit();
//����
void GameDraw();
//�ƶ���
void snakemove();
//ͨ�������ı��ߵ��˶�����
void keyControl();
//��ʳ��
void EatFood();
int main()
{
	//initgraph��ʼ��һ��ͼ�δ���
	initgraph(640, 480);//�����ֱ��ʾy���x���С
	GameInit();
	while (1)//ѭ�����ϻ�ͼ
	{
		GameDraw();
		snakemove();
		Sleep(100);//�ӳ�ִ�д���
		keyControl();
		EatFood();
	}
	int n = getchar();
	return 0;
}
void GameInit()
{
	snake.size = 3;//һ��ʼ������
	snake.speed = 10;
	snake.dir=RIGHT;
	for (int i=0;i<snake.size;i++)
	{
		snake.coor[i].x = 40 - 10 * i;//ȷ��ͷ���ұ�
		snake.coor[i].y = 10;
	}
	//ʹ��rand()���������
	srand(time(0));//�������������
	food.x = rand() % 640;//%640Ϊ��ȷ�����������겻�����640
	food.y = rand() % 480;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.r = rand() % 5 + 5;
	food.flag = true;
	return;
}
void GameDraw()
{
	//˫�����ͼ
	BeginBatchDraw();
	//���ñ�����ɫ
	setbkcolor(RGB(28, 115, 119));
	//����ڿ���ʾ�����õ���ɫ
	cleardevice();
	//������
	setfillcolor(RED);//�����ߵ���ɫ
	for (int i = 0;i < snake.size;i++)
	{
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);//x,y,�뾶
	}
	//����ʳ��
	if (food.flag)//���ʳ�����
	{
		setfillcolor(food.color);//ʳ�����ɫ
		solidcircle(food.x, food.y, food.r);
	}
	//˫�������
	EndBatchDraw();
	return;
}
void snakemove()
{
	//���������ͷ�ƶ�
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
		snake.coor[0].y-=snake.speed;//�ߵ����ƶ�
		if (snake.coor[0].y+10 <=0 )//��10��ʾ��ͷ�����߽糬��������߽�
		{
			snake.coor[0].y = 480;//��480Ϊ���ڵĸߣ��Ӵ����³���
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
	//�ж���û�а���
	if (_kbhit())//���а��������棬û�з��ؼ�
	{
		switch (_getch())
		{//72 80 75 77 �������Ҽ�ֵ
		case 'w':
		case 'W':
		case 72:
			//�ı䷽��
			if (snake.dir != DOWN)//��if��� ̰���߲������¸ı䷽������Ҹı䷽��
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
		snake.coor[0].y >= food.y-food.r&& snake.coor[0].y <= food.y + food.r)//�ڷ�Χ�ڼ���ʾ�Ե�
	{
		food.flag = false;
		snake.size++;//�ߵĽ�����һ
	}
	//���ʳ����ʧ������������һ��ʳ��
	if (!food.flag)
	{
		food.x = rand() % 640;//%640Ϊ��ȷ�����������겻�����640
		food.y = rand() % 480;
		food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
		food.r = rand() % 10 + 5;
		food.flag = true;
	}
}