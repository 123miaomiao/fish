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
char input;//�����������ʹ��
int  p1size;//����һ�����������������ĳߴ�
int start_p1size;//����һ��������������ҵĳ�ʼ��С
int fishhead=0; //�ж���ͷ����
int gameStatus=0; // ��Ϸ״̬��0Ϊ��ʼ�˵����棬1Ϊ������Ϸ��2Ϊ������Ϸ״̬
IMAGE img_p1;//���ͼƬ
IMAGE img_p1bei;
IMAGE img_bk;//����ͼƬ
IMAGE img_bk0;//�������ͼ
IMAGE img_f1,img_f_f1;
IMAGE img_f1bei,img_f_f1bei;//1����ͼƬ
IMAGE img_f2,img_f_f2;
IMAGE img_f2bei,img_f_f2bei;//2����ͼƬ
IMAGE img_f3,img_f_f3;
IMAGE img_f3bei,img_f_f3bei;//3����ͼƬ
IMAGE img_f4,img_f_f4;
IMAGE img_f4bei,img_f_f4bei;//4����ͼƬ
IMAGE img_f5,img_f_f5;
IMAGE img_f5bei,img_f_f5bei;//5����ͼƬ
IMAGE bk[8];
IMAGE last1;
IMAGE last2;
IMAGE gui1,gui1bei;
IMAGE haiwang[28];
class fish
{
private:
	double position_x;//������
	double position_y;//������
	double v_x;//ˮƽ�ٶ�
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
	loadimage(&fishtu,L"start.jpg",1000,640);//��ʼ��������
	initgraph(1000,640);
	putimage(0,0,&fishtu);
	settextstyle(50,0,L"�ֻ�24�ţ��������");
	setbkmode(TRANSPARENT);
	setfillcolor(LIGHTBLUE);
	fillrectangle(360,100,600,180);
	fillrectangle(360,100+120,600,180+120);
	outtextxy(360+20,100+13,L"��ʼ��Ϸ");
	outtextxy(360+20,233,L"������Ϸ");
	settextstyle(60,0,L"�ֻ�24�ţ��������");
	settextcolor(RED);
	outtextxy(300,350,L"����V2.0�汾");
	settextstyle(30,0, _T("΢���ź�"));
	outtextxy(250,450, _T("��Ϸ��ESC���������˵�"));
	settextcolor(RGB(64,0,128));
	settextstyle(30,0, _T("΢���ź�"));
	outtextxy(250, 490, _T("�����������ʼ��Ϸ ����������ƶ��Ե�С��"));
	settextcolor(0x0000AA);
	settextstyle(25,0,L"��Բ");
	settextcolor(DARKGRAY);
	outtextxy(250,530,L"С��ʾ�������۸����˱��Լ���ͷ���");
	settextcolor(BLUE);
	settextstyle(25,0,L"�ֻ�24�ţ��������");
	outtextxy(250,600,L"���Ƶ�����Ϸ����ֹ������Ϸ");
	//������
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
void pauseMenu() // ��Ϸ��ͣ��˵����棬һ�㰴ESC���������ý���
{   double length=1000.0,high=640.0;
	putimage(0, 0, &img_bk0);//��ʾ����
	settextcolor(RGB(123,90,254));
	settextstyle(70,0, _T("��������"));
	outtextxy(length*0.36, high*0.19, _T("����"));

	setbkmode(TRANSPARENT);
	settextcolor(RGB(106,0,0));
	settextstyle(37,0, _T("��Բ"));
	outtextxy(length*0.35, high*0.36, _T("1 ������Ϸ"));
	outtextxy(length*0.35, high*0.44, _T("2 �˳���Ϸ"));

	settextcolor(RGB(64,0,128));
	settextstyle(30,0, _T("΢���ź�"));
	outtextxy(length*0.36, high*0.55, _T("ESC���������˵�"));

	settextcolor(RGB(64,0,128));
	settextstyle(25,0, _T("΢���ź�"));
	outtextxy(length*0.36, high*0.65, _T("����������ƶ��Ե�С��"));
	outtextxy(length*0.36, high*0.8, _T("�������� ײ����ʧȥһ��"));

	FlushBatchDraw();
	Sleep(2);

	if(kbhit())  
	{
		input = getch();  // �����û��Ĳ�ͬ�������ƶ�
		if (input == '1') 
			gameStatus = 1;
		else if (input == '2')
		{
			gameStatus = 2;
			exit(0);
		}
	}
}

fish::fish(double x,double y,double v)//fish��Ĺ��캯��
{
	position_x=x;
	position_y=y;
	v_x=v;
}
void fish::rightmove()//�����ƶ�
{
	position_x=position_x+v_x;
}
void fish::leftmove()//�����ƶ�
{
	position_x=position_x-v_x;
}
void rightrepeat(fish &a,double num)//�����ظ�����
{
	if (a.position_x>=length)
	{
		 a.position_x= num;
		 a.position_y= rand() % 400;
	}
}
void leftrepeat(fish &a,double num)//�����ظ�����
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
		pauseMenu(); // ��Ϸ��ͣ��˵����棬һ�㰴ESC����
	static int i=0,j=0;//������ͼ
	if(i<500)
	i++;
	if(i==500)
	{
		i=0;
		j++;
	}
	if(j==7)
		j=0;

	putimage(0, 0, &bk[j]);//��ʾ����
	putimage(food1.position_x, food1.position_y, &img_f1bei,NOTSRCERASE);//��ʾ1����
	putimage(food1.position_x, food1.position_y, &img_f1,SRCINVERT);
	putimage(f_food1.position_x, f_food1.position_y, &img_f_f1bei,NOTSRCERASE);//��ʾ����1����
	putimage(f_food1.position_x, f_food1.position_y, &img_f_f1,SRCINVERT);

	putimage(food2.position_x, food2.position_y, &img_f2bei,NOTSRCERASE);//��ʾ2����
	putimage(food2.position_x, food2.position_y, &img_f2,SRCINVERT);
	putimage(f_food2.position_x, f_food2.position_y, &img_f_f2bei,NOTSRCERASE);//��ʾ����2����
	putimage(f_food2.position_x, f_food2.position_y, &img_f_f2,SRCINVERT);

	putimage(food3.position_x, food3.position_y, &img_f3bei,NOTSRCERASE);//��ʾ3����
	putimage(food3.position_x, food3.position_y, &img_f3,SRCINVERT);
	putimage(f_food3.position_x, f_food3.position_y, &img_f_f3bei,NOTSRCERASE);//��ʾ����3����
	putimage(f_food3.position_x, f_food3.position_y, &img_f_f3,SRCINVERT);

	putimage(food4.position_x, food4.position_y, &img_f4bei,NOTSRCERASE);//��ʾ4����
	putimage(food4.position_x, food4.position_y, &img_f4,SRCINVERT);
	putimage(f_food4.position_x, f_food4.position_y, &img_f_f4bei,NOTSRCERASE);//��ʾ����4����
	putimage(f_food4.position_x, f_food4.position_y, &img_f_f4,SRCINVERT);

	putimage(gui.position_x,gui.position_y,&gui1bei,NOTSRCERASE);//��ʾ��
	putimage(gui.position_x,gui.position_y,&gui1,SRCINVERT);

	putimage(food5.position_x, food5.position_y, &img_f5bei,NOTSRCERASE);//��ʾ5����
	putimage(food5.position_x, food5.position_y, &img_f5,SRCINVERT);
	putimage(f_food5.position_x, f_food5.position_y, &img_f_f5bei,NOTSRCERASE);//��ʾ����5����
	putimage(f_food5.position_x, f_food5.position_y, &img_f_f5,SRCINVERT);
}
player::player(double x,double y,double vx,double vy)//player��Ĺ��캯��
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
		loadimage(&img_p1bei, L"playerbei.jpg",p1size,p1size,true);//�������
	}
	else
	{
		loadimage(&img_p1, L"f_player.jpg",p1size,p1size,true);
		loadimage(&img_p1bei,  L"f_playerbei.jpg",p1size,p1size,true);//�������
	}//�����
	putimage(player.position_x, player.position_y, &img_p1bei,NOTSRCERASE);//��ʾ���
	putimage(player.position_x, player.position_y, &img_p1,SRCINVERT);//����ҷŵ������ʾΪ��ʹ���С��ʱ����������ʵ

	setbkmode(TRANSPARENT);
	setcolor(WHITE);
	settextstyle(20,0, _T("����"));

	FlushBatchDraw();
}
void player::eaten(fish &food1,fish &f_food1,fish &food2,fish &f_food2,fish &food3,fish &f_food3,fish &food4,fish &f_food4,fish &food5,fish &f_food5)
{
	int length=1000,high=640;
	//�ж�һ�����Ƿ񱻳ԡ��ж�����Ϊһ�������������������ڲ�������
	if(food1.position_x+20>position_x&& food1.position_x+20<position_x+p1size && food1.position_y+15>position_y && food1.position_y+15<position_y+p1size)
	{
		mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
		mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
		mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // ����������
		mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��

		p1size+=2;
		score=score+1;
		food1.position_x=-400;
		food1.position_y=rand()%(high-30);//С�㱻�ԣ������������
	}
	//�ж�2�����Ƿ񱻳ԡ��ж�����Ϊ2�������������������ڲ�������
	if(p1size>45)
	{
		if(food2.position_x+32.5>position_x && food2.position_x+32.5<position_x+p1size && food2.position_y+20>position_y && food2.position_y+20<position_y+p1size)
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
			mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // ����������
			mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��

			p1size+=4;
			score=score+2;
			food2.position_x=-1000;
			food2.position_y=rand()%(high-40);
		}
	}
	//����������������ײ����С�ص���ʼ״̬������������ط�����
	else
	{
		if(position_x+p1size/2.0>food2.position_x && position_x+p1size/2.0<food2.position_x+65 && position_y+p1size/2.0>food2.position_y && position_y+p1size/2.0<food2.position_y+40 )
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
			mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString(L"open 2.mp3 alias gemusic", NULL, 0, NULL); // ����������
			mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��
			life=life-1;
			p1size=start_p1size;
			
			position_x=rand()%(length-40);//���������λ��
			position_y=rand()%(high-40);
		}
	}
	//�ж�3�����Ƿ񱻳ԡ��ж�����Ϊ3�������������������ڲ�������
	if(p1size>70)
	{
		if(food3.position_x+40>position_x && food3.position_x+40<position_x+p1size && food3.position_y+40>position_y && food3.position_y+40<position_y+p1size)
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
			mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // ����������
			mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��

			p1size+=7;
			score=score+3;
			food3.position_x=-1800;
			food3.position_y=rand()%(high-80);
		}
	}
	//����������������ײ����С�ص���ʼ״̬��������������ط�����
	else
	{
		if(position_x+p1size/2.0>food3.position_x && position_x+p1size/2.0<food3.position_x+80 && position_y+p1size/2.0>food3.position_y && position_y+p1size/2.0<food3.position_y+80 )
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
			mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString(L"open 2.mp3 alias gemusic", NULL, 0, NULL); // ����������
			mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��

			p1size=start_p1size;
			life=life-1;
			position_x=rand()%(length-40);//���������λ��
			position_y=rand()%(high-40);
		}
	}
	//�ж�4�����Ƿ񱻳ԡ��ж�����Ϊ4�������������������ڲ�������
	if(p1size>100)
	{
		if(food4.position_x+60>position_x && food4.position_x+60<position_x+p1size && food4.position_y+50>position_y && food4.position_y+50<position_y+p1size)
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
			mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // ����������
			mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��

			p1size+=8;
			score=score+4;
			food4.position_x=-2700;
			food4.position_y=rand()%(high-100);
		}
	}
	//����������������ײ����С�ص���ʼ״̬��������������ط�����
	else
	{
		if(position_x+p1size/2.0>food4.position_x && position_x+p1size/2.0<food4.position_x+110 && position_y+p1size/2.0>food4.position_y && position_y+p1size/2.0<food4.position_y+100 )
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
			mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString(L"open 2.mp3 alias gemusic", NULL, 0, NULL); // ����������
			mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��

			p1size=start_p1size;
			life=life-1;
			position_x=rand()%(length-40);//���������λ��
			position_y=rand()%(high-40);
		}
	}
	//�ж�5�����Ƿ񱻳ԡ��ж�����Ϊ5�������������������ڲ�������
	if(p1size>185)
	{
		if(food5.position_x+125>position_x&&food5.position_x+125<position_x+p1size&&food5.position_y+62.5>position_y&&food5.position_y+62.5<position_y+p1size)
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
			mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // ����������
			mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��

			p1size+=5;
			score=score+5;
			food5.position_x =-4000;
			food5.position_y =rand()%(high-125);
		}
	}
	if(score==1)
	{
		mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
		mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
		mciSendString(L"open fist.mp3 alias getmusic", NULL, 0, NULL); // ����������
		mciSendString(L"play getmusic", NULL, 0, NULL); // ������һ��
	}
	//����������������ײ����С�ص���ʼ״̬��������������ط�����
	else
	{
		if(position_x+p1size/2.0>food5.position_x && position_x+p1size/2.0<food5.position_x+250 && position_y+p1size/2.0>food5.position_y && position_y+p1size/2.0<food5.position_y+125 )
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
			mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString(L"open 2.mp3 alias gemusic", NULL, 0, NULL); // ����������
			mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��

			p1size=start_p1size;
			life=life-1;
			position_x=rand()%(length-40);//���������λ��
			position_y=rand()%(high-40);
		}
	}
	//�ж�1�����Ƿ񱻳ԡ��ж�����Ϊ1�������������������ڲ�������
	if(f_food1.position_x+20>position_x && f_food1.position_x+20<position_x+p1size && f_food1.position_y+15>position_y && f_food1.position_y+15<position_y+p1size)
	{
		mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
		mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
		mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // ����������
		mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��

		p1size+=2;
		score=score+1;
		f_food1.position_x=length+600;
		f_food1.position_y=rand()%(high-30);//С�㱻�ԣ������������
	}
	//�ж�2�����Ƿ񱻳ԡ��ж�����Ϊ2�������������������ڲ�������
	if(p1size>45)
	{
		if(f_food2.position_x+32.5>position_x && f_food2.position_x+32.5<position_x+p1size && f_food2.position_y+20>position_y && f_food2.position_y+20<position_y+p1size)
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
			mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // ����������
			mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��

			p1size+=4;
			score=score+2;
			f_food2.position_x=length+1800;
			f_food2.position_y=rand()%(high-40);
		}
	}
	//����������������ײ����С�ص���ʼ״̬��������������ط�����
	else
	{
		if(position_x+p1size/2.0>f_food2.position_x && position_x+p1size/2.0<f_food2.position_x+65 && position_y+p1size/2.0>f_food2.position_y && position_y+p1size/2.0<f_food2.position_y+40 )
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
			mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString(L"open 2.mp3 alias gemusic", NULL, 0, NULL); // ����������
			mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��

			p1size=start_p1size;
			life=life-1;
			position_x=rand()%(length-40);//���������λ��
			position_y=rand()%(high-40);
		}
	}
	//�ж�3�����Ƿ񱻳ԡ��ж�����Ϊ3�������������������ڲ�������
	if(p1size>70)
	{
		if(f_food3.position_x+40>position_x && f_food3.position_x+40<position_x+p1size && f_food3.position_y+40>position_y && f_food3.position_y+40<position_y+p1size)
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
			mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // ����������
			mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��

			p1size+=7;
			score=score+3;
			f_food3.position_x=length+2800;
			f_food3.position_y=rand()%(high-80);
		}
	}
	//����������������ײ����С�ص���ʼ״̬��������������ط�����
	else
	{
		if(position_x+p1size/2.0>f_food3.position_x && position_x+p1size/2.0<f_food3.position_x+80 && position_y+p1size/2.0>f_food3.position_y && position_y+p1size/2.0<f_food3.position_y+80 )
		{
			
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
			mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // ����������
			mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��
			p1size=start_p1size;
			life=life-1;
			position_x=rand()%(length-40);//���������λ��
			position_y=rand()%(high-40);
		}
	}
	//�ж�4�����Ƿ񱻳ԡ��ж�����Ϊ4�������������������ڲ�������
	if(p1size>100)
	{
		if(f_food4.position_x+60>position_x && f_food4.position_x+60<position_x+p1size && f_food4.position_y+50>position_y && f_food4.position_y+50<position_y+p1size)
		{
			
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
			mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // ����������
			mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��
			p1size+=8;
			score=score+4;
			f_food4.position_x=length+6000;
			f_food4.position_y=rand()%(high-100);
		}

	}
	//����������������ײ����С�ص���ʼ״̬��������������ط�����
	else
	{
		if(position_x+p1size/2.0>f_food4.position_x && position_x+p1size/2.0<f_food4.position_x+120 && position_y+p1size/2.0>f_food4.position_y && position_y+p1size/2.0<f_food4.position_y+100 )
		{
			
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
			mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // ����������
			mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��
			p1size=start_p1size;
			life=life-1;
			position_x=rand()%(length-40);//���������λ��
			position_y=rand()%(high-40);
		}
	}
	//�ж�5�����Ƿ񱻳ԡ��ж�����Ϊ5�������������������ڲ�������
	if(p1size>185)
	{
		if(f_food5.position_x+125>position_x&&f_food5.position_x+125<position_x+p1size&&f_food5.position_y+62.5>position_y&&f_food5.position_y+62.5<position_y+p1size)
		{
			
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
			mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // ����������
			mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��
			p1size+=5;
			score=score+5;
			f_food5.position_x =length+3300;
			f_food5.position_y =rand()%(high-125);
		}
	}
	//����������������ײ����С�ص���ʼ״̬��������������ط�����
	else
	{
		if(position_x+p1size/2.0>f_food5.position_x && position_x+p1size/2.0<f_food5.position_x+250 && position_y+p1size/2.0>f_food5.position_y && position_y+p1size/2.0<f_food5.position_y+125 )
		{
			mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
			mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString(L"open 1.mp3 alias gemusic", NULL, 0, NULL); // ����������
			mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��
			p1size=start_p1size;
			life=life-1;
			position_x=rand()%(length-40);//���������λ��
			position_y=rand()%(high-40);
		}
	}
	
}
void play(player &player)
{
	if ((GetAsyncKeyState(VK_LEFT) & 0x8000)  &&  (player.position_x>0))
	{
		fishhead=1;//תͷ
		player.position_x=player.position_x-player.v_x;  //����
	}
	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)  &&  (player.position_x<920))
	{
		fishhead=0;
		player.position_x=player.position_x+player.v_x;  //����
	}
	if ((GetAsyncKeyState(VK_UP) & 0x8000)  &&  player.position_y>0)
		player.position_y=player.position_y-player.v_y;  //����
	if ((GetAsyncKeyState(VK_DOWN) & 0x8000)  &&  player.position_y<640-80)
		player.position_y=player.position_y+player.v_y;  //����


	if(kbhit())//�ж��û��Ƿ�������ͣ��Ϸ
	{
		input = getch();
		if (input == 27) //27����esc��
		{
			gameStatus = 2;
		}
	}
}

void prepare()
{
	 int length=1000,high=640;
	mciSendString(L"open fish.mp3 alias bkmusic", NULL, 0, NULL);//�򿪱�������
	mciSendString(L"play bkmusic repeat", NULL, 0, NULL);  // ѭ������

	initgraph(1000,640);
	// ��ȡ���ھ��
	HWND hwnd = GetHWnd();
	// ���ô��ڱ�������
	SetWindowText(hwnd, _T("����"));

	p1size=40;//��ҳ�ʼ��СΪ40
	start_p1size=p1size;

	srand((unsigned) time(NULL));//�����

	//�Ƿ���� IMAGE �Ĵ�С����ӦͼƬ
	loadimage(&img_bk0, L"11.bmp",1000,640,true);//�������
	loadimage(&img_bk, L"background.jpg",1000,640,true);//����

	loadimage(&img_f1, L"food1.jpg",40,30,true);
	loadimage(&img_f1bei, L"food1bei.jpg",40,30,true);//1����
	loadimage(&img_f_f1, L"f_food1.jpg",40,30,true);
	loadimage(&img_f_f1bei, L"f_food1bei.jpg",40,30,true);//1���㷴��

	loadimage(&img_f2, L"food2.jpg",65,40,true);
	loadimage(&img_f2bei, L"food2bei.jpg",65,40,true);//2����
	loadimage(&img_f_f2, L"f_food2.jpg",65,40,true);
	loadimage(&img_f_f2bei, L"f_food2bei.jpg",65,40,true);//2���㷴��

	loadimage(&img_f3, L"food3.jpg",80,80,true);
	loadimage(&img_f3bei, L"food3bei.jpg",80,80,true);//3����
	loadimage(&img_f_f3, L"f_food3.jpg",80,80,true);
	loadimage(&img_f_f3bei, L"f_food3bei.jpg",80,80,true);//3���㷴��

	loadimage(&img_f4, L"food4.jpg",120,110,true);
	loadimage(&img_f4bei, L"food4bei.jpg",120,110,true);//4����
	loadimage(&img_f_f4, L"f_food4.jpg",120,110,true);
	loadimage(&img_f_f4bei, L"f_food4bei.jpg",120,110,true);//4���㷴��

	loadimage(&img_f5, L"food5.jpg",250,125,true);
	loadimage(&img_f5bei, L"food5bei.jpg",250,125,true);//5����
	loadimage(&img_f_f5, L"f_food5.jpg",250,125,true);
	loadimage(&img_f_f5bei, L"f_food5bei.jpg",250,125,true);//5���㷴��
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
	startMenu();//��ʼ�˵�����
	initgraph(length,high);//�����С
	BeginBatchDraw();
}

void gameover()
{
	int length=1000,high=640;
	//��Ϸ���� ��ʾ���շ���
	mciSendString(L"stop gemusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
	mciSendString(L"close gemusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
	mciSendString(L"open overmusic.mp3 alias gemusic", NULL, 0, NULL); // ����������
	mciSendString(L"play gemusic", NULL, 0, NULL); // ������һ��
	setbkmode(TRANSPARENT);
	setcolor(BLACK);
	if (score>35)
	{
		putimage(0,0,&last2);
	}
	else
		putimage(0,0,&last1);
	settextcolor(RGB(123,90,254));
	settextstyle(70,0, _T("��������"));
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
	fish food1(0,rand()%400,1.8),f_food1(length+(rand()%10)*100,rand()%400,1.8);//1����
    fish food2(-200,rand()%400,1.5),f_food2(length+length+(rand()%15)*100,rand()%400,1.5);//2����
    fish food3(-500,rand()%400,1.6),f_food3(length+length+(rand()%20)*100,rand()%400,1.6);//3����
    fish food4(-800,rand()%400,1.5),f_food4(length+length+(rand()%20)*150,rand()%400,1.5);//4����
    fish food5(-10000,rand()%400,1.5),f_food5(length+length+(rand()%10)*1000,rand()%400,1.5);//5����
    fish gui(length,rand()%400,1.1);//�ڹ�
	player player(1000.0/2.0,640.0/2.0,2.2,2.2);//���
	cartoon();
	prepare();
	p1size=40;//��ҳ�ʼ��СΪ40
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
		if(!gameStatus) //�ж�ֵ�Ƿ�Ϊ0
			break;

	}
	cleardevice();
	gameover();
	return 0;
}