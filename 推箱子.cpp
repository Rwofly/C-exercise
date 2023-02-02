#include<iostream>
#include<stdlib.h>
#include<conio.h>//第三方文件
using namespace std;
//推箱子的元素：空地0、墙1、目的地2、箱子3、玩家4、箱子在目的地5、玩家在目的地6
enum Mine
{
	SPACE,//空地
	WALL,//墙
	DEST,//目的地
	BOX,//箱子
	PLAYER,//玩家
};
//当前关卡,从第一关开始
int level = 0;
//定义一个三维数组，用来表示不同关卡的推箱子的地图
int map[3][10][10] =
{
	{
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,0},
	{0,0,0,1,2,1,1,1,1,0},
	{0,1,1,1,3,3,0,2,1,0},
	{0,1,2,3,4,0,1,1,1,0},
	{0,1,1,1,1,3,1,0,0,0},
	{0,0,0,0,1,2,1,0,0,0},
	{0,0,0,0,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	},
	{
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,0,0,1,1,0,0},
	{0,1,0,2,1,1,2,0,1,0},
	{1,0,0,0,3,0,0,0,0,1},
	{1,0,0,0,4,3,0,0,0,1},
	{0,1,0,0,3,3,0,0,1,0},
	{0,0,1,0,0,0,0,1,0,0},
	{0,0,0,1,2,2,1,0,0,0},
	{0,0,0,0,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
    },
	{
	{0,0,0,1,1,1,1,0,0,0},
	{0,0,1,0,0,0,2,1,0,0},
	{0,1,0,0,3,0,0,1,1,0},
	{1,2,0,0,0,1,3,0,0,1},
	{1,0,0,3,1,1,0,0,2,1},
	{0,1,0,0,0,0,4,0,1,0},
	{0,0,1,0,3,0,0,0,1,0},
	{0,0,0,1,2,0,0,1,0,0},
	{0,0,0,1,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
    },
};
void gamedraw()//绘制地图
{
	cout << "        推箱子" << endl;
	for (int i = 0;i < 10;i++)
	{
		for (int k = 0;k < 10;k++)
		{
			switch (map[level][i][k])
			{
			case SPACE:
				cout << "  ";
				break;
			case WALL:
				cout << "※";
				break;
			case DEST:
				cout << "☆";
				break;
			case BOX:
				cout << "□";
				break;
			case PLAYER:
				cout << "♀";
				break;
			case PLAYER+DEST://玩家在目的地6
				cout << "♂";
				break;
			case BOX+DEST://箱子在目的地5
				cout << "■";
				break;
			}
		}
		cout << endl;
	}
}
//按键消息处理
void keyEvent()
{
	//获取玩家的位置
	int i, k;
	for (i = 0;i < 10;i++)
	{
		for (k = 0;k < 10;k++)
		{
			//玩家在目的地时，没有PLAYER的位置，只有PLAYER+DEST，因此要加上map[level][i][k]==PLAYER+DEST
			if (map[level][i][k] == PLAYER||map[level][i][k]==PLAYER+DEST)
			{

				goto end;//goto语句跳出双重循环
			}
		}
	}
end:;
	//怎么获取按键消息 getchar()有弊端，输入完数据和，需按回车确定
	//使用第三方库，VS给我们集成，可直接使用，_getch conio.h _kbhit()检测是否有按键按下
	//方向键上下左右 72 80 75 77
	char ch = _getch();
	switch (ch)
	{
	case 72://上移
		//玩家前面是空地，直接移动。玩家前面是箱子，判断箱子前面是什么
			if (map[level][i - 1][k] == SPACE||map[level][i-1][k]==DEST)//玩家前面为目的地或者空地
			{
				map[level][i - 1][k] += PLAYER;//上面变成玩家在目的地
				map[level][i][k] -= PLAYER;//原始的变为空地SPACE
			}
			else if(map[level][i-1][k]==BOX||map[level][i-1][k]==BOX+DEST)//玩家前面为箱子或者箱子在目的地
			{
				if (map[level][i - 1 - 1][k] == SPACE || map[level][i - 1 - 1][k] == DEST)//判断箱子前面
				{
					map[level][i - 1 - 1][k] += BOX;//把箱子一到前面一个位置
					map[level][i - 1][k] = map[level][i - 1][k] - BOX + PLAYER;//让原来箱子的位置，减去箱子，然后加上玩家
					map[level][i][k] -= PLAYER;//让玩家在原来的位置消失
				}
			}
		break;
	case 80://下移
		//玩家下面是空地，直接移动。玩家下面是箱子，判断箱子下面是什么
			if (map[level][i+1][k] == SPACE || map[level][i+1][k] == DEST)//玩家下面为目的地或者空地
			{
				map[level][i+1][k] += PLAYER;//下面变成玩家在目的地
				map[level][i][k] -= PLAYER;//原始的变为空地SPACE
			}
			else if (map[level][i+1][k] == BOX || map[level][i+1][k] == BOX + DEST)//玩家下面为箱子或者箱子在目的地
			{
				if (map[level][i+1+1][k] == SPACE || map[level][i+1+1][k] == DEST)//判断箱子前面
				{
					map[level][i + 1+1][k] += BOX;//把箱子一到下面一个位置
					map[level][i+1][k] = map[level][i+1][k] - BOX + PLAYER;//让原来箱子的位置，减去箱子，然后加上玩家
					map[level][i][k] -= PLAYER;//让玩家在原来的位置消失
				}
			}
		break;
	case 75://左移
		//玩家左面是空地，直接移动。玩家左面是箱子，判断箱子左面是什么
			if (map[level][i][k-1] == SPACE || map[level][i][k-1] == DEST)//玩家左面为目的地或者空地
			{
				map[level][i][k-1] += PLAYER;//左面变成玩家在目的地
				map[level][i][k] -= PLAYER;//原始的变为空地SPACE
			}
			else if (map[level][i][k-1] == BOX || map[level][i][k-1] == BOX + DEST)//玩家左面为箱子或者箱子在目的地
			{
				if (map[level][i][k-2] == SPACE || map[level][i][k-2] == DEST)//判断箱子前面
				{
					map[level][i][k-2] += BOX;//把箱子一到左面一个位置
					map[level][i][k-1] = map[level][i][k-1] - BOX + PLAYER;//让原来箱子的位置，减去箱子，然后加上玩家
					map[level][i][k] -= PLAYER;//让玩家在原来的位置消失
				}
			}
		break;
	case 77://右移
		//玩家右面是空地，直接移动。玩家右面是箱子，判断箱子右面是什么
			if (map[level][i][k+1] == SPACE || map[level][i][k+1] == DEST)//玩家右面为目的地或者空地
			{
				map[level][i][k+1] += PLAYER;//右面变成玩家在目的地
				map[level][i][k] -= PLAYER;//原始的变为空地SPACE
			}
			else if (map[level][i][k+1] == BOX || map[level][i][k+1] == BOX + DEST)//玩家右面为箱子或者箱子在目的地
			{
				if (map[level][i][k+2] == SPACE || map[level][i][k+2] == DEST)//判断箱子前面
				{
					map[level][i][k+2] += BOX;//把箱子一到右面一个位置
					map[level][i][k+1] = map[level][i][k+1] - BOX + PLAYER;//让原来箱子的位置，减去箱子，然后加上玩家
					map[level][i][k] -= PLAYER;//让玩家在原来的位置消失
				}
			}
		break;
	}
}
//判断是否过关
bool jude()//如果没有单独的箱子存在就是通关
{
	for (int i = 0;i < 10;i++)
	{
		for (int k = 0;k < 10;k++)
		{
			if (map[level][i][k] == BOX)
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	//调整窗口大小
	system("mode con lines=15 cols=25");
	while (1)//循环
	{
		system("cls");//清屏后再输出
		gamedraw();//打印地图
		if (jude())
		{
			cout << "   恭喜你第" << level+1 << "关通关！"<<endl;
			if (level < 2)
			{
				cout << "  按任意键进入下一关" << endl;
			}
			level++;//关卡最大数量为三
			if (level > 2)
			{
				cout << "   恭喜你已全部通关！";
				int n = getchar();//防止闪退
				break;
			}
		}
		keyEvent();
	}
	
	int n=getchar();//防止闪退，不让程序退出
	return 0;
}