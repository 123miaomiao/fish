#include<graphics.h>
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#pragma comment(lib,"Winmm.lib")
using namespace std;
double length=1000.0,high=640.0;
int life=3;
int score=0;
char input;//定义变量便于使用
int  p1size;//定义一个变量来储存玩家鱼的尺寸
int start_p1size;//定义一个变量来储存玩家的初始大小
int fishhead=0; //判断鱼头朝向
int gameStatus=0; // 游戏状态，0为初始菜单界面，1为正常游戏，2为结束游戏状态
IMAGE img_p1;//玩家图片
IMAGE img_p1bei;
IMAGE img_bk;//背景图片
IMAGE img_bk0;//进入界面图
IMAGE img_f1,img_f_f1;
IMAGE img_f1bei,img_f_f1bei;//1号鱼图片
IMAGE img_f2,img_f_f2;
IMAGE img_f2bei,img_f_f2bei;//2号鱼图片
IMAGE img_f3,img_f_f3;
IMAGE img_f3bei,img_f_f3bei;//3号鱼图片
IMAGE img_f4,img_f_f4;
IMAGE img_f4bei,img_f_f4bei;//4号鱼图片
IMAGE img_f5,img_f_f5;
IMAGE img_f5bei,img_f_f5bei;//5号鱼图片
IMAGE bk[8];
IMAGE last1;
IMAGE last2;
IMAGE gui1,gui1bei;
IMAGE haiwang[28];
class fish
{
private:
	double position_x;//横坐标
	double position_y;//纵坐标
	double v_x;//水平速度
public:
	fish(double x,double y,double v);
	void rightmove();
	void leftmove();
	friend void rightrepeat(fish &a,double num);
	friend void leftrepeat(fish &a,double num);
	friend void showfood(fish &food1,fish &f_food1,fish &food2,fish &f_food2,fish &food3,fish &f_fish3,fish &foo4,fish &f_food4,fish &food5, fish &f_food5,fish &gui);
	friend class player;
};
class player
{
private:
	double position_x;
	double position_y;
	double v_x;
	double v_y;
public:
	player(double x,double y,double vx,double vy); 
	friend void showplayer(player &player);
	void eaten(fish &food1,fish &f_food1,fish &food2,fish &f_food2,fish &food3,fish &f_food3,fish &food4,fish &f_food4,fish &food5,fish &f_food5);
	friend void play(player &player);
};
void cartoon()
{
	int length=1000,high=640;
	initgraph(1000,640);
	    loadimage(&haiwang[0],L"28.bmp",length,high);
		loadimage(&haiwang[1],L"1.bmp",length,high);
		loadimage(&haiwang[2],L"2.bmp",length,high);
		loadimage(&haiwang[3],L"3.bmp",length,high);
		loadimage(&haiwang[4],L"4.bmp",length,high);
		loadimage(&haiwang[5],L"5.bmp",length,high);
		loadimage(&haiwang[6],L"6.bmp",length,high);
		loadimage(&haiwang[7],L"7.bmp",length,high);
		loadimage(&haiwang[8],L"8.bmp",length,high);
		loadimage(&haiwang[9],L"9.bmp",length,high);
		loadimage(&haiwang[10],L"10.bmp",length,high);
		loadimage(&haiwang[11],L"11.bmp",length,high);
		loadimage(&haiwang[12],L"12.bmp",length,high);
		loadimage(&haiwang[13],L"13.bmp",length,high);
		loadimage(&haiwang[14],L"14.bmp",length,high);
		loadimage(&haiwang[15],L"15.bmp",length,high);
		loadimage(&haiwang[16],L"16.bmp",length,high);
		loadimage(&haiwang[17],L"17.bmp",length,high);
		loadimage(&haiwang[18],L"18.bmp",length,high);
		loadimage(&haiwang[19],L"19.bmp",length,high);
		loadimage(&haiwang[20],L"20.bmp",length,high);
		loadimage(&haiwang[21],L"21.bmp",length,high);
	for(int j=0;j<21;j++)
	{
		putimage(0,0,&haiwang[j]);
		Sleep(300);
		cleardevice();
	}
	putimage(0,0,&haiwang[21]);
	Sleep(1000);
	cleardevice();
	//getchar();
	
}
void startMenu()
{ 
	IMAGE fishtu;
	loadimage(&fishtu,L"start.jpg",1000,640);//开始界面的设计
	initgraph(1000,640);
	putimage(0,0,&fishtu);
	settextstyle(50,0,L"字魂24号，镇魂手书");
	setbkmode(TRANSPARENT);
	setfillcolor(LIGHTBLUE);
	fillrectangle(360,100,600,180);
	fillrectangle(360,100+120,600,180+120);
	outtextxy(360+20,100+13,L"开始游戏");
	outtextxy(360+20,233,L"结束游戏");
	settextstyle(60,0,L"字魂24号，镇魂手书");
	settextcolor(RED);
	outtextxy(300,350,L"海王V2.0版本");
	settextstyle(30,0, _T("微软雅黑"));
	outtextxy(250,450, _T("游戏中ESC键返回主菜单"));
	settextcolor(RGB(64,0,128));
	settextstyle(30,0, _T("微软雅黑"));
	outtextxy(250, 490, _T("鼠标左键点击开始游戏 方向键控制移动吃掉小鱼"));
	settextcolor(0x0000AA);
	settextstyle(25,0,L"幼圆");
	settextcolor(DARKGRAY);
	outtextxy(250,530,L"小提示：海王欺负不了比自己个头大的");
	settextcolor(BLUE);
	settextstyle(25,0,L"字魂24号，镇魂手书");
	outtextxy(250,600,L"抵制盗版游戏，防止沉迷游戏");
	//鼠标操作
	MOUSEMSG m;
	while(1)
	{
		m=GetMouseMsg();
		if(m.x>=360&&m.x<=600&&m.y>=100&&m.y<=180)
		{
			setlinecolor(RED);
			rectangle(360-10,100-10,600+10,180+10);
			if(m.uMsg==WM_LBUTTONDOWN)
			{
				gameStatus=1; 
				break;
			}
		}
		else if(m.x>=360&&m.x<=600&&m.y>=220&&m.y<=300)
		{
			setlinecolor(RED);
			rectangle(360-10,220-10,600+10,300+10);
			if(m.uMsg==WM_LBUTTONDOWN)
			{
				gameStatus=2; 
				exit(0);
			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(360-10,100-10,600+10,180+10);
			rectangle(360-10,220-10,600+10,300+10);
		}
	}
	//getchar();
	//cleardevice();
}
void pauseMenu() // 游戏暂停后菜单界面，一般按ESC键后启动该界面
{   double length=1000.0,high=640.0;
	putimage(0, 0, &img_bk0);//显示背景
	settextcolor(RGB(123,90,254));
	settextstyle(70,0, _T("华文琥珀"));
	outtextxy(length*0.36, high*0.19, _T("海王"));

	setbkmode(TRANSPARENT);
	settextcolor(RGB(106,0,0));
	settextstyle(37,0, _T("幼圆"));
	outtextxy(length*0.35, high*0.36, _T("1 继续游戏"));
	outtextxy(length*0.35, high*0.44, _T("2 退出游戏"));

	settextcolor(RGB(64,0,128));
	settextstyle(30,0, _T("微软雅黑"));
	outtextxy(length*0.36, high*0.55, _T("ESC键返回主菜单"));

	settextcolor(RGB(64,0,128));
	settextstyle(25,0, _T("微软雅黑"));
	outtextxy(length*0.36, high*0.65, _T("方向键控制移动吃掉小鱼"));
	outtextxy(length*0.36, high*0.8, _T("三条生命 撞大鱼失去一条"));

	FlushBatchDraw();
	Sleep(2);

	if(kbhit())  
	{
		input = getch();  // 根据用户的不同输入来移动
		if (input == '1') 
			gameStatus = 1;
		else if (input == '2')
		{
			gameStatus = 2;
			exit(0);
		}
	}
}

fish::fish(double x,double y,double v)//fish类的构造函数
{
	position_x=x;
	position_y=y;
	v_x=v;
}
void fish::rightmove()//向右移动
{
	position_x=position_x+v_x;
}
void fish::leftmove()//向左移动
{
	position_x=position_x-v_x;
}
void rightrepeat(fish &a,double num)//右向重复出现
{
	if (a.position_x>=length)
	{
		 a.position_x= num;
		 a.position_y= rand() % 400;
	}
}
void leftrepeat(fish &a,double num)//左向重复出现
{
	if(a.position_x<=-300)
	{
		a.position_x=num;
		a.position_y=rand()%400;
	}
}
void showfood(fish &food1,fish &f_food1,fish &food2,fish &f_food2,fish &food3,fish &f_food3,fish &food4,fish &f_food4,fish &food5, fish &f_food5,fish &gui)
{
	while (gameStatus==2)
		pauseMenu(); // 游戏暂停后菜单界面，一般按ESC键后
	static int i=0,j=0;//换背景图
	if(i<500)
	i++;
	if(i==500)
	{
		i=0;
		j++;
	}
	if(j==7)
		j=0;

	putimage(0, 0, &bk[j]);//显示背景
	putimage(food1.position_x, food1.position_y, &img_f1bei,NOTSRCERASE);//显示1号鱼
	putimage(food1.position_x, food1.position_y, &img_f1,SRCINVERT);
	putimage(f_food1.position_x, f_food1.position_y, &img_f_f1bei,NOTSRCERASE);//显示反向1号鱼
	putimage(f_food1.position_x, f_food1.position_y, &img_f_f1,SRCINVERT);

	putimage(food2.position_x, food2.position_y, &img_f2bei,NOTSRCERASE);//显示2号鱼
	putimage(food2.position_x, food2.position_y, &img_f2,SRCINVERT);
	putimage(f_food2.position_x, f_food2.position_y, &img_f_f2bei,NOTSRCERASE);//显示反向2号鱼
	putimage(f_food2.position_x, f_food2.position_y, &img_f_f2,SRCINVERT);

	putimage(food3.position_x, food3.position_y, &img_f3bei,NOTSRCERASE);//显示3号鱼
	putimage(food3.position_x, food3.position_y, &img_f3,SRCINVERT);
	putimage(f_food3.position_x, f_food3.position_y, &img_f_f3bei,NOTSRCERASE);//显示反向3号鱼
	putimage(f_food3.position_x, f_food3.position_y, &img_f_f3,SRCINVERT);

	putimage(food4.position_x, food4.position_y, &img_f4bei,NOTSRCERASE);//显示4号鱼
	putimage(food4.position_x, food4.position_y, &img_f4,SRCINVERT);
	putimage(f_food4.position_x, f_food4.position_y, &img_f_f4bei,NOTSRCERASE);//显示反向4号鱼
	putimage(f_food4.position_x, f_food4.position_y, &img_f_f4,SRCINVERT);

	putimage(gui.position_x,gui.position_y,&gui1bei,NOTSRCERASE);//显示龟
	putimage(gui.position_x,gui.position_y,&gui1,SRCINVERT);

	putimage(food5.position_x, food5.position_y, &img_f5bei,NOTSRCERASE);//显示5号鱼
	putimage(food5.position_x, food5.position_y, &img_f5,SRCINVERT);
	putimage(f_food5.position_x, f_food5.position_y, &img_f_f5bei,NOTSRCERASE);//显示反向5号鱼
	putimage(f_food5.position_x, f_food5.position_y, &img_f_f5,SRCINVERT);
}
player::player(double x,double y,double vx,double vy)//player类的构造函数
{
	position_x=x;
	position_y=y;
	v_x=vx;
	v_y=vy;
}
void showplayer(player &player)
{

	if (fishhead==0)
	{
		loadimage(&img_p1,  L"player.jpg",p1size,p1size,true);
		loadimage(&img_p1bei, L"playerbei.jpg",p1size,p1size,true);//正向玩家
	}
	else
	{
		loadimage(&img_p1, L"f_player.jpg",p1size,p1size,true);
		loadimage(&img_p1bei,  L"f_playerbei.jpg",p1size,p1size,true);//反向玩家
	}//玩家类
	putimage(player.position_x, player.position_y, &img_p1bei,NOTSRCERASE);//显示玩家
	putimage(player.position_x, player.position_y, &img_p1,SRCINVERT);//将玩家放到最后显示为了使其吃小鱼时看起来更真实

	setbkmode(TRANSPARENT);
	setcolor(WHITE);
	settextstyle(20,0, _T("黑体"));

	FlushBatchDraw();
}
void player::eaten(fish &food1,fish &f_food1,fish &food2,fish &f_food2,fish &food3,fish &f_food3,fish &food4,fish &f_food4,fish &food5,fish &f_food5)
{
	int length=1000,high=640;
	//判断一号鱼是否被吃。判断条件为一号鱼的中心坐标在玩家内部即被吃
	if(food1.position_x+20>position_x&& food1.position_x+20<position_x+p1size && food1.position_y+15>position_y && food1.position_y+15<position_y+p1size)
	{
		mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
		mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
		mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
		mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次

		p1size+=2;
		score=score+1;
		food1.position_x=-400;
		food1.position_y=rand()%(high-30);//小鱼被吃，重新随机生成
	}
	//判断2号鱼是否被吃。判断条件为2号鱼的中心坐标在玩家内部即被吃
	if(p1size>45)
	{
		if(food2.position_x+32.5>position_x && food2.position_x+32.5<position_x+p1size && food2.position_y+20>position_y && food2.position_y+20<position_y+p1size)
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
			mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
			mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次

			p1size+=4;
			score=score+2;
			food2.position_x=-1000;
			food2.position_y=rand()%(high-40);
		}
	}
	//玩家与比自身大的鱼相撞，大小回到初始状态并随机在其他地方生成
	else
	{
		if(position_x+p1size/2.0>food2.position_x && position_x+p1size/2.0<food2.position_x+65 && position_y+p1size/2.0>food2.position_y && position_y+p1size/2.0<food2.position_y+40 )
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
			mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(L"open 2.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
			mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次
			life=life-1;
			p1size=start_p1size;
			
			position_x=rand()%(length-40);//出现在随机位置
			position_y=rand()%(high-40);
		}
	}
	//判断3号鱼是否被吃。判断条件为3号鱼的中心坐标在玩家内部即被吃
	if(p1size>70)
	{
		if(food3.position_x+40>position_x && food3.position_x+40<position_x+p1size && food3.position_y+40>position_y && food3.position_y+40<position_y+p1size)
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
			mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
			mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次

			p1size+=7;
			score=score+3;
			food3.position_x=-1800;
			food3.position_y=rand()%(high-80);
		}
	}
	//玩家与比自身大的鱼相撞，大小回到初始状态；并随机在其他地方生成
	else
	{
		if(position_x+p1size/2.0>food3.position_x && position_x+p1size/2.0<food3.position_x+80 && position_y+p1size/2.0>food3.position_y && position_y+p1size/2.0<food3.position_y+80 )
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
			mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(L"open 2.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
			mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次

			p1size=start_p1size;
			life=life-1;
			position_x=rand()%(length-40);//出现在随机位置
			position_y=rand()%(high-40);
		}
	}
	//判断4号鱼是否被吃。判断条件为4号鱼的中心坐标在玩家内部即被吃
	if(p1size>100)
	{
		if(food4.position_x+60>position_x && food4.position_x+60<position_x+p1size && food4.position_y+50>position_y && food4.position_y+50<position_y+p1size)
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
			mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
			mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次

			p1size+=8;
			score=score+4;
			food4.position_x=-2700;
			food4.position_y=rand()%(high-100);
		}
	}
	//玩家与比自身大的鱼相撞，大小回到初始状态；并随机在其他地方生成
	else
	{
		if(position_x+p1size/2.0>food4.position_x && position_x+p1size/2.0<food4.position_x+110 && position_y+p1size/2.0>food4.position_y && position_y+p1size/2.0<food4.position_y+100 )
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
			mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(L"open 2.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
			mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次

			p1size=start_p1size;
			life=life-1;
			position_x=rand()%(length-40);//出现在随机位置
			position_y=rand()%(high-40);
		}
	}
	//判断5号鱼是否被吃。判断条件为5号鱼的中心坐标在玩家内部即被吃
	if(p1size>185)
	{
		if(food5.position_x+125>position_x&&food5.position_x+125<position_x+p1size&&food5.position_y+62.5>position_y&&food5.position_y+62.5<position_y+p1size)
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
			mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
			mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次

			p1size+=5;
			score=score+5;
			food5.position_x =-4000;
			food5.position_y =rand()%(high-125);
		}
	}
	if(score==1)
	{
		mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
		mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
		mciSendString(L"open fist.mp3 alias getmusic", NULL, 0, NULL); // 打开跳动音乐
		mciSendString(L"play getmusic", NULL, 0, NULL); // 仅播放一次
	}
	//玩家与比自身大的鱼相撞，大小回到初始状态；并随机在其他地方生成
	else
	{
		if(position_x+p1size/2.0>food5.position_x && position_x+p1size/2.0<food5.position_x+250 && position_y+p1size/2.0>food5.position_y && position_y+p1size/2.0<food5.position_y+125 )
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
			mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(L"open 2.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
			mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次

			p1size=start_p1size;
			life=life-1;
			position_x=rand()%(length-40);//出现在随机位置
			position_y=rand()%(high-40);
		}
	}
	//判断1号鱼是否被吃。判断条件为1号鱼的中心坐标在玩家内部即被吃
	if(f_food1.position_x+20>position_x && f_food1.position_x+20<position_x+p1size && f_food1.position_y+15>position_y && f_food1.position_y+15<position_y+p1size)
	{
		mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
		mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
		mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
		mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次

		p1size+=2;
		score=score+1;
		f_food1.position_x=length+600;
		f_food1.position_y=rand()%(high-30);//小鱼被吃，重新随机生成
	}
	//判断2号鱼是否被吃。判断条件为2号鱼的中心坐标在玩家内部即被吃
	if(p1size>45)
	{
		if(f_food2.position_x+32.5>position_x && f_food2.position_x+32.5<position_x+p1size && f_food2.position_y+20>position_y && f_food2.position_y+20<position_y+p1size)
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
			mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
			mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次

			p1size+=4;
			score=score+2;
			f_food2.position_x=length+1800;
			f_food2.position_y=rand()%(high-40);
		}
	}
	//玩家与比自身大的鱼相撞，大小回到初始状态；并随机在其他地方生成
	else
	{
		if(position_x+p1size/2.0>f_food2.position_x && position_x+p1size/2.0<f_food2.position_x+65 && position_y+p1size/2.0>f_food2.position_y && position_y+p1size/2.0<f_food2.position_y+40 )
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
			mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(L"open 2.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
			mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次

			p1size=start_p1size;
			life=life-1;
			position_x=rand()%(length-40);//出现在随机位置
			position_y=rand()%(high-40);
		}
	}
	//判断3号鱼是否被吃。判断条件为3号鱼的中心坐标在玩家内部即被吃
	if(p1size>70)
	{
		if(f_food3.position_x+40>position_x && f_food3.position_x+40<position_x+p1size && f_food3.position_y+40>position_y && f_food3.position_y+40<position_y+p1size)
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
			mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
			mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次

			p1size+=7;
			score=score+3;
			f_food3.position_x=length+2800;
			f_food3.position_y=rand()%(high-80);
		}
	}
	//玩家与比自身大的鱼相撞，大小回到初始状态；并随机在其他地方生成
	else
	{
		if(position_x+p1size/2.0>f_food3.position_x && position_x+p1size/2.0<f_food3.position_x+80 && position_y+p1size/2.0>f_food3.position_y && position_y+p1size/2.0<f_food3.position_y+80 )
		{
			
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
			mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
			mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次
			p1size=start_p1size;
			life=life-1;
			position_x=rand()%(length-40);//出现在随机位置
			position_y=rand()%(high-40);
		}
	}
	//判断4号鱼是否被吃。判断条件为4号鱼的中心坐标在玩家内部即被吃
	if(p1size>100)
	{
		if(f_food4.position_x+60>position_x && f_food4.position_x+60<position_x+p1size && f_food4.position_y+50>position_y && f_food4.position_y+50<position_y+p1size)
		{
			
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
			mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
			mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次
			p1size+=8;
			score=score+4;
			f_food4.position_x=length+6000;
			f_food4.position_y=rand()%(high-100);
		}

	}
	//玩家与比自身大的鱼相撞，大小回到初始状态；并随机在其他地方生成
	else
	{
		if(position_x+p1size/2.0>f_food4.position_x && position_x+p1size/2.0<f_food4.position_x+120 && position_y+p1size/2.0>f_food4.position_y && position_y+p1size/2.0<f_food4.position_y+100 )
		{
			
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
			mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
			mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次
			p1size=start_p1size;
			life=life-1;
			position_x=rand()%(length-40);//出现在随机位置
			position_y=rand()%(high-40);
		}
	}
	//判断5号鱼是否被吃。判断条件为5号鱼的中心坐标在玩家内部即被吃
	if(p1size>185)
	{
		if(f_food5.position_x+125>position_x&&f_food5.position_x+125<position_x+p1size&&f_food5.position_y+62.5>position_y&&f_food5.position_y+62.5<position_y+p1size)
		{
			
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
			mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
			mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次
			p1size+=5;
			score=score+5;
			f_food5.position_x =length+3300;
			f_food5.position_y =rand()%(high-125);
		}
	}
	//玩家与比自身大的鱼相撞，大小回到初始状态；并随机在其他地方生成
	else
	{
		if(position_x+p1size/2.0>f_food5.position_x && position_x+p1size/2.0<f_food5.position_x+250 && position_y+p1size/2.0>f_food5.position_y && position_y+p1size/2.0<f_food5.position_y+125 )
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
			mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
			mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次
			p1size=start_p1size;
			life=life-1;
			position_x=rand()%(length-40);//出现在随机位置
			position_y=rand()%(high-40);
		}
	}
	
}
void play(player &player)
{
	if ((GetAsyncKeyState(VK_LEFT) & 0x8000)  &&  (player.position_x>0))
	{
		fishhead=1;//转头
		player.position_x=player.position_x-player.v_x;  //左移
	}
	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)  &&  (player.position_x<920))
	{
		fishhead=0;
		player.position_x=player.position_x+player.v_x;  //右移
	}
	if ((GetAsyncKeyState(VK_UP) & 0x8000)  &&  player.position_y>0)
		player.position_y=player.position_y-player.v_y;  //上移
	if ((GetAsyncKeyState(VK_DOWN) & 0x8000)  &&  player.position_y<640-80)
		player.position_y=player.position_y+player.v_y;  //下移


	if(kbhit())//判断用户是否输入暂停游戏
	{
		input = getch();
		if (input == 27) //27代表esc键
		{
			gameStatus = 2;
		}
	}
}

void prepare()
{
	 int length=1000,high=640;
	mciSendString(L"open fish.mp3 alias bkmusic", NULL, 0, NULL);//打开背景音乐
	mciSendString(L"play bkmusic repeat", NULL, 0, NULL);  // 循环播放

	initgraph(1000,640);
	// 获取窗口句柄
	HWND hwnd = GetHWnd();
	// 设置窗口标题文字
	SetWindowText(hwnd, _T("海王"));

	p1size=40;//玩家初始大小为40
	start_p1size=p1size;

	srand((unsigned) time(NULL));//随机数

	//是否调整 IMAGE 的大小以适应图片
	loadimage(&img_bk0, L"11.bmp",1000,640,true);//进入界面
	loadimage(&img_bk, L"background.jpg",1000,640,true);//背景

	loadimage(&img_f1, L"food1.jpg",40,30,true);
	loadimage(&img_f1bei, L"food1bei.jpg",40,30,true);//1号鱼
	loadimage(&img_f_f1, L"f_food1.jpg",40,30,true);
	loadimage(&img_f_f1bei, L"f_food1bei.jpg",40,30,true);//1号鱼反向

	loadimage(&img_f2, L"food2.jpg",65,40,true);
	loadimage(&img_f2bei, L"food2bei.jpg",65,40,true);//2号鱼
	loadimage(&img_f_f2, L"f_food2.jpg",65,40,true);
	loadimage(&img_f_f2bei, L"f_food2bei.jpg",65,40,true);//2号鱼反向

	loadimage(&img_f3, L"food3.jpg",80,80,true);
	loadimage(&img_f3bei, L"food3bei.jpg",80,80,true);//3号鱼
	loadimage(&img_f_f3, L"f_food3.jpg",80,80,true);
	loadimage(&img_f_f3bei, L"f_food3bei.jpg",80,80,true);//3号鱼反向

	loadimage(&img_f4, L"food4.jpg",120,110,true);
	loadimage(&img_f4bei, L"food4bei.jpg",120,110,true);//4号鱼
	loadimage(&img_f_f4, L"f_food4.jpg",120,110,true);
	loadimage(&img_f_f4bei, L"f_food4bei.jpg",120,110,true);//4号鱼反向

	loadimage(&img_f5, L"food5.jpg",250,125,true);
	loadimage(&img_f5bei, L"food5bei.jpg",250,125,true);//5号鱼
	loadimage(&img_f_f5, L"f_food5.jpg",250,125,true);
	loadimage(&img_f_f5bei, L"f_food5bei.jpg",250,125,true);//5号鱼反向
	loadimage(&bk[0],L"backpicture0.jpg",length,high);
	loadimage(&bk[1],L"backpicture1.jpg",length,high);//////////
	loadimage(&bk[2],L"backpicture2.jpg",length,high);
	loadimage(&bk[3],L"backpicture3.jpg",length,high);
	loadimage(&bk[4],L"backpicture4.jpg",length,high);
	loadimage(&bk[5],L"backpicture5.jpg",length,high);
	loadimage(&bk[6],L"backpicture6.jpg",length,high);
	loadimage(&bk[7],L"backpicture7.jpg",length,high);
	loadimage(&last1,L"over1.jpg",length,high);
	loadimage(&last2,L"over2.jpg",length,high);
	loadimage(&gui1,L"gui.jpg",65,50,true);
	loadimage(&gui1bei,L"guibei.jpg",65,50,true);

	while (gameStatus==0)
	startMenu();//初始菜单界面
	initgraph(length,high);//画面大小
	BeginBatchDraw();
}

void gameover()
{
	int length=1000,high=640;
	//游戏结束 显示最终分数
	mciSendString(L"stop gemusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
	mciSendString(L"close gemusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
	mciSendString(L"open overmusic.mp3 alias gemusic", NULL, 0, NULL); // 打开跳动音乐
	mciSendString(L"play gemusic", NULL, 0, NULL); // 仅播放一次
	setbkmode(TRANSPARENT);
	setcolor(BLACK);
	if (score>35)
	{
		putimage(0,0,&last2);
	}
	else
		putimage(0,0,&last1);
	settextcolor(RGB(123,90,254));
	settextstyle(70,0, _T("华文琥珀"));
	TCHAR b[] = _T("score");
	outtextxy(0,0,b);
	TCHAR m[20];
	_stprintf(m, _T("%d"),score);
	outtextxy(60,50,m);
	EndBatchDraw();
	Sleep(100000);
	getch();
	closegraph();

}

int main()
{
	double length=1000.0,high=640.0;
	fish food1(0,rand()%400,1.8),f_food1(length+(rand()%10)*100,rand()%400,1.8);//1号鱼
    fish food2(-200,rand()%400,1.5),f_food2(length+length+(rand()%15)*100,rand()%400,1.5);//2号鱼
    fish food3(-500,rand()%400,1.6),f_food3(length+length+(rand()%20)*100,rand()%400,1.6);//3号鱼
    fish food4(-800,rand()%400,1.5),f_food4(length+length+(rand()%20)*150,rand()%400,1.5);//4号鱼
    fish food5(-10000,rand()%400,1.5),f_food5(length+length+(rand()%10)*1000,rand()%400,1.5);//5号鱼
    fish gui(length,rand()%400,1.1);//乌龟
	player player(1000.0/2.0,640.0/2.0,2.2,2.2);//玩家
	cartoon();
	prepare();
	p1size=40;//玩家初始大小为40
	start_p1size=p1size;
	while(1)
	{
		showfood(food1,f_food1,food2,f_food2,food3,f_food3,food4,f_food4,food5,f_food5,gui);
		showplayer(player);
		if(life<=0)
		gameStatus=0;
		food1.rightmove();
		food2.rightmove();
		food3.rightmove();
		food4.rightmove();
		food5.rightmove();
		gui.rightmove();
		f_food1.leftmove();
		f_food2.leftmove();
		f_food3.leftmove();
		f_food4.leftmove();
		f_food5.leftmove();
		rightrepeat(food1,-400);
		rightrepeat(food2,-1000);
		rightrepeat(food3,-1800);
		rightrepeat(food4,-2700);
		rightrepeat(food5,-6000);
		leftrepeat(f_food1,length+1000);
		leftrepeat(f_food2,length+1200);
		leftrepeat(f_food3,length+2000);
		leftrepeat(f_food4,length+3000);
		leftrepeat(f_food5,length+5000);
		leftrepeat(gui,2000);
		player.eaten(food1,f_food1,food2,f_food2,food3,f_food3,food4,f_food4,food5,f_food5);
		play(player);
		if(!gameStatus) //判断值是否为0
			break;

	}
	cleardevice();
	gameover();
	return 0;
}