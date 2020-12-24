# include "iGraphics.h"
#include<windows.h>
#include<MMSystem.h>
int maze1[17][17]=
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1},
    {1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,3,1,0,1},
    {1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1},
    {1,0,0,0,1,3,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,1,0,1,0,1,0,0,1,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1},
    {0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0},
    {1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,1,0,0,1,0,1,0,1,0,1},
    {1,0,0,0,1,0,0,0,0,0,0,3,1,0,0,0,1},
    {1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1},
    {1,0,1,3,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1},
    {1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
int maze2[17][17]=
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1},
    {1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,3,1,0,1},
    {1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1},
    {1,0,0,0,1,3,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,1,0,1,0,1,0,0,1,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1},
    {0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0},
    {1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,1,0,0,1,0,1,0,1,0,1},
    {1,0,0,0,1,0,0,0,0,0,0,3,1,0,0,0,1},
    {1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1},
    {1,0,1,3,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1},
    {1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
char img[3][1000]= {"images\\block7.bmp","images\\block8.bmp","images\\block9.bmp"};
char pac[10][100]= {"images\\right1d.bmp","images\\right2d.bmp","images\\right1d.bmp","images\\left2d.bmp",
                    "images\\right1d.bmp","images\\up2d.bmp","images\\right1d.bmp","images\\down2d.bmp"
                   };

int food_pos[1000][1000];
int point=0;
int highscore[10]= {0};
int page=-1;
int flag=1;
char name[100];
int len=0;
int max_point=0;
char playmenuhighscore[20];
int maze_color=0;
bool sound1=true;
bool sound2=false;
void maze_color_changer()
{
    maze_color++;
    maze_color%=3;
}
void drawmaze()
{
    for(int y_c=600,i=0; i<17; y_c-=32,i++)
    {
        for(int x_c=40,j=0; j<17; x_c+=32,j++)
        {
            if(maze1[i][j]==1)
                iShowBMP(x_c,y_c,img[maze_color]);
            else if(maze2[i][j]==3 && (i>=3 && j>=3 && j<=14))
            {
                iShowBMP2(x_c,y_c,"images\\food2.bmp",0);
            }
            else if(maze2[i][j]==0)
            {

                //iSetColor(224,224,64);

                //iFilledCircle(x_c+16,y_c+20,2);
                iShowBMP2(x_c,y_c,"images\\food1.bmp",0);

            }

        }
    }
}
int idx=0;
int p_x=72;
int p_y=120;
char score[1000];
int grun1=0;
int grun2=1;
int grun3=3;
int grun4=2;
int g1_x=136;
int g1_y=504;
int g2_x=72;
int g2_y=568;
int g3_x=264;
int g3_y=312;
int g4_x=136;
int g4_y=184;
int life=3;
char blinky[2][100]={"images\\blinky.bmp","images\\blinky_2.bmp"};
int idxb=0;
void ghost1()
{
    iShowBMP2(g1_x,g1_y,blinky[idxb],0);

    if(grun1==0)
    {
        int cnt1=0;
        int temp=g1_x+33;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=g1_y+10;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            g1_x+=7;

    }

    else if(grun1==1)
    {
        int cnt1=0;
        int temp=g1_x-8;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=g1_y+10;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            g1_x-=7;
    }

    else if(grun1==2)
    {
        int cnt1=0;
        int temp=g1_x+10;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=g1_y+35;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            g1_y+=7;
    }

    else if(grun1==3)
    {
        int cnt1=0;
        int temp=g1_x+10;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=g1_y;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            g1_y-=7;
    }

}

char inky[2][100]={"images\\inky.bmp","images\\inky_2.bmp"};
int idxi=0;

void ghost2()
{
    iShowBMP2(g2_x,g2_y,inky[idxi],0);

    if(grun2==0)
    {
        int cnt1=0;
        int temp=g2_x+33;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=g2_y+10;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            g2_x+=7;

    }

    else if(grun2==1)
    {
        int cnt1=0;
        int temp=g2_x-8;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=g2_y+10;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            g2_x-=7;
    }

    else if(grun2==2)
    {
        int cnt1=0;
        int temp=g2_x+10;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=g2_y+35;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            g2_y+=7;
    }

    else if(grun2==3)
    {
        int cnt1=0;
        int temp=g2_x+10;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=g2_y;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            g2_y-=7;
    }

}

char pinky[2][100]={"images\\pinky.bmp","images\\pinky_2.bmp"};
int idxp=0;

void ghost3()
{
    iShowBMP2(g3_x,g3_y,pinky[idxp],0);

    if(grun3==0)
    {
        int cnt1=0;
        int temp=g3_x+33;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=g3_y+10;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            g3_x+=7;

    }

    else if(grun3==1)
    {
        int cnt1=0;
        int temp=g3_x-8;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=g3_y+10;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            g3_x-=7;
    }

    else if(grun3==2)
    {
        int cnt1=0;
        int temp=g3_x+10;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=g3_y+35;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            g3_y+=7;
    }

    else if(grun3==3)
    {
        int cnt1=0;
        int temp=g3_x+10;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=g3_y;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            g3_y-=7;
    }

}

char clyde[2][100]={"images\\clyde.bmp","images\\clyde_2.bmp"};
int idxc=0;

void ghost4()
{
    iShowBMP2(g4_x,g4_y,clyde[idxc],0);

    if(grun4==0)
    {
        int cnt1=0;
        int temp=g4_x+33;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=g4_y+10;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            g4_x+=7;

    }

    else if(grun4==1)
    {
        int cnt1=0;
        int temp=g4_x-8;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=g4_y+10;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            g4_x-=7;
    }

    else if(grun4==2)
    {
        int cnt1=0;
        int temp=g4_x+10;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=g4_y+35;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            g4_y+=7;
    }

    else if(grun4==3)
    {
        int cnt1=0;
        int temp=g4_x+10;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=g4_y;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            g4_y-=7;
    }

}

void ghost_index_changer(){
  idxb++;
  idxb%=2;
  idxc++;
  idxc%=2;
  idxi++;
  idxi%=2;
  idxp++;
  idxp%=2;
}

void charconv1(int point)
{
    int k=0;
    while(point)
    {
        score[k++]=point%10+'0';
        point/=10;
    }
    score[k]=0;
    strrev(score);
}


void scorefn()
{
    //PlaySound(TEXT("eating.wav"),NULL,SND_ASYNC);
    int cnt1=0;
    int temp=p_x+10;
    while(temp>=32)
    {
        temp-=32;
        cnt1++;
    }
    temp=p_y+10;
    int cnt2=0;
    while(temp<=632)
    {
        temp+=32;
        cnt2++;
    }
    if(maze1[cnt2-1][cnt1-1]==3)
    {

        point+=30;
        maze1[cnt2-1][cnt1-1]=-4;
    }
    else if(maze1[cnt2-1][cnt1-1]==0)
    {
        point+=10;
        maze1[cnt2-1][cnt1-1]=-5;
    }
    maze2[cnt2-1][cnt1-1]=-1;
    charconv1(point);
    if(point==1630){
        page=5;
    }
}
void playmenu()
{
    iShowBMP(590,600,"images\\point.bmp");
    iShowBMP(590,500,"images\\lives.bmp");
    iSetColor(251,244,4);
    iText(900,630,score,GLUT_BITMAP_TIMES_ROMAN_24);
    //iText(900,540,lives,GLUT_BITMAP_TIMES_ROMAN_24);
    iShowBMP(640,240,"images\\mazecolor.bmp");
    iShowBMP(640,140,"images\\pause.bmp");
    for(int i=0; i<life && life>0; i++)
    {
        iShowBMP2(890+i*40,530,"images\\life.bmp",0);
    }

}

void pacmove()
{
    //corner holes
    //sides
    if(p_x<=48 && p_y>344)
    {
        p_x=550;
    }
    else if(p_x>550 && p_y>344)
    {
        p_x=50;
    }
    //up-down
    /*if(p_y<71 && p_x>298){
       p_y=600;
    }
    else if(p_y>=600 && p_x>298){
       p_y=72;
    }*/

    //pacman image
    iShowBMP2(p_x,p_y,pac[idx],0);
}

void eat()
{
    if((p_x>=g1_x&&p_x<=g1_x+32) && (p_y>=g1_y&&p_y<=g1_y+32)||(p_x<=g1_x&&p_x>=g1_x-32) && (p_y<=g1_y&&p_y>=g1_y-32))
    {
        life--;
        iDelay(2);
        p_x=72,p_y=120;
        g1_x=136;
        g1_y=504;
        g2_x=72;
        g2_y=568;
        g3_x=264;
        g3_y=312;
        g4_x=136;
        g4_y=184;
    }
    else if((p_x>=g2_x&&p_x<=g2_x+32) && (p_y>=g2_y&&p_y<=g2_y+32)||(p_x<=g2_x&&p_x>=g2_x-32) && (p_y<=g2_y&&p_y>=g2_y-32))
    {
        life--;
        iDelay(2);
        p_x=72,p_y=120;
        g1_x=136;
        g1_y=504;
        g2_x=72;
        g2_y=568;
        g3_x=264;
        g3_y=312;
        g4_x=136;
        g4_y=184;

    }
    else if((p_x>=g3_x&&p_x<=g3_x+32) && (p_y>=g3_y&&p_y<=g3_y+32)||(p_x<=g3_x&&p_x>=g3_x-32) && (p_y<=g3_y&&p_y>=g3_y-32))
    {
        life--;
        iDelay(2);
        p_x=72,p_y=120;
        g1_x=136;
        g1_y=504;
        g2_x=72;
        g2_y=568;
        g3_x=264;
        g3_y=312;
        g4_x=136;
        g4_y=184;

    }
    else if((p_x>=g4_x&&p_x<=g4_x+32) && (p_y>=g4_y&&p_y<=g4_y+32)||(p_x<=g4_x&&p_x>=g4_x-32) && (p_y<=g4_y&&p_y>=g4_y-32))
    {
        life--;
        iDelay(2);
        p_x=72,p_y=120;
        g1_x=136;
        g1_y=504;
        g2_x=72;
        g2_y=568;
        g3_x=264;
        g3_y=312;
        g4_x=136;
        g4_y=184;

    }
    if(life==0)
    {
        page=3;
    }

}
void showhighscore();
void iDraw()
{
    //place your drawing codes here
    if(page==-1){
       iShowBMP(0,0,"images\\startgame.bmp");
    }
    else if(page==0)
    {
        iClear();
        if(!sound1){
            sound1=true;
            PlaySound(TEXT("PacMan.wav"),NULL,SND_LOOP|SND_ASYNC);

        }
        iShowBMP(0,0,"images\\mainmenu.bmp");
    }
    else if(page==2)
    {
        iClear();
        iShowBMP(0,0,"images\\helpmenu.bmp");
    }
    else if(page==1)
    {
        iClear();
        if(sound1){
            sound1=false;
            PlaySound(TEXT("siren.wav"),NULL,SND_LOOP|SND_ASYNC);
        }
        drawmaze();
        pacmove();
        eat();
        playmenu();
        ghost1();
        ghost2();
        ghost3();
        ghost4();
    }
    else if(page==3)
    {
        PlaySound(0,0,0);
        iShowBMP(0,0,"images\\gameover.bmp");
        iText(510,150,score,GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(page==4)
    {
        iShowBMP(0,0,"images\\highscoremenu.bmp");
        showhighscore();
    }
    else if(page==5){
       iShowBMP(0,0,"images\\congrat.bmp");
    }
}


void reset()
{
    life=3;
    for(int i=0; i<17; i++)
    {
        for(int j=0; j<17; j++)
        {
            if(maze1[i][j]==-4)
                maze1[i][j]=3;
            else if(maze1[i][j]==-5)
                maze1[i][j]=0;
            if(maze2[i][j]==-1)
                maze2[i][j]=0;
        }
    }
    FILE *p;
    p=fopen("hscore.txt","a");
    if(point!=0)
        fprintf(p,"%d\n",point);
    fclose(p);
    strcpy(score,"0");
    point=0;

}




/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(page==-1){
            if(mx>=400&&mx<=710 && my>=130 && my<=200){
                page=0;
            }
        }
        if(page==0)
        {
            if(mx>=350&&mx<=640 && my>=550 && my<=600)
            {
                p_x=72;
                p_y=120;
                idx=0;
                reset();
                page=1;
            }
            else if(mx>=350&&mx<=640 && my>=470 && my<=530)
                page=1;
            else if(mx>=350&&mx<=640 && my>=310 && my<=360)
                page=2;
            else if(mx>=350&&mx<=640 && my>=380 && my<=450)
                page=4;
            else if(mx>=350&&mx<=640 && my>=230 && my<=290)
                exit(0);
        }
        if(page==1)
        {
            if(mx>=640 && mx<=920 && my>=150 && my<=215)
                page=0;
            if(mx>=640 && mx<=1020 && my>=240 && my<=300)
                maze_color_changer();
        }
        if(page==3)
        {
            if(mx>=360 && mx<=750 && my>=40 && my<=90)
                flag=1;
        }
        if(page==2)
        {
            if(mx>=890 && mx<=1050 && my>=40 && my<=90)
                page=0;
        }
        if(page==3)
        {
            if(mx>=900 && mx<=1080 && my>=30 && my<=80)
            {
                reset();
                page=0;
            }
        }
        if(page==4)
        {
            if(mx>=940 && mx<=1080 && my>=40 && my<=80)
                page=0;
        }
        if(page==5){
            if(mx>=940 && mx<=1090 && my>=30 && my<=50)
                page=0;
        }
    }
    /*if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
       r=255,g=0,b=0;
    }*/
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{


    if(flag)
    {
        name[len++]=key;
    }

}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
int k1=0;
int k2=0;
int k3=0;
int k4=0;
bool right=false;
void ghostimer()
{
    grun1=rand()%4;
    grun2=rand()%4;
    grun3=rand()%4;
    grun4=rand()%4;
}
void iSpecialKeyboard(unsigned char key)
{

    if(key==GLUT_KEY_END)
    {
        exit(0);
    }

    if(key == GLUT_KEY_RIGHT)
    {
        scorefn();
        k1++;
        int temp1[]= {0,0,0,0,0,1,1,1,1};
        idx=temp1[k1%9];
        int cnt1=0;
        int temp=p_x+33;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=p_y+10;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            p_x+=9;
        /*grun1=0;
        grun2=1;
        grun3=3;
        grun4=2;*/
    }



    if(key == GLUT_KEY_LEFT)
    {
        scorefn();
        k2++;
        int temp2[]= {2,2,2,2,2,3,3,3,3};
        idx=temp2[k2%9];
        int cnt1=0;
        int temp=p_x-8;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=p_y+10;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            p_x-=9;
        /*grun1=2;
        grun2=0;
        grun3=1;
        grun4=3;*/
    }
    if(key == GLUT_KEY_UP)
    {
        scorefn();
        k3++;
        int temp3[]= {4,4,4,4,4,5,5,5,5};
        idx=temp3[k3%9];
        int cnt1=0;
        int temp=p_x+10;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=p_y+35;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            p_y+=9;
        /*grun1=3;
        grun2=2;
        grun3=0;
        grun4=1;*/
    }
    if(key == GLUT_KEY_DOWN)
    {
        scorefn();
        k4++;
        int temp4[]= {6,6,6,6,6,7,7,7,7};
        idx=temp4[k4%9];
        int cnt1=0;
        int temp=p_x+10;
        while(temp>=40)
        {
            temp-=32;
            cnt1++;
        }
        temp=p_y;
        int cnt2=0;
        while(temp<=632)
        {
            temp+=32;
            cnt2++;
        }
        if(maze1[cnt2-1][cnt1-1]!=1)
            p_y-=9;
        /*grun1=2;
        grun2=3;
        grun3=2;
        grun4=0;*/
    }
    /*if(key == GLUT_KEY_UP)
    {
        y+=10;
    }
    else if(key == GLUT_KEY_DOWN)
    {
        y-=10;
    }
    if(key == GLUT_KEY_LEFT)
    {
        x-=10;
    }
    if(key == GLUT_KEY_RIGHT)
    {
        x+=10;
    }
    if(key == GLUT_KEY_HOME)
    {
        r=255,g=0,b=0;
    }
    if(key == GLUT_KEY_END)
    {
        r=0,g=0,b=255;
    }*/
    //place your codes for other keys here

}
char hscore[20];
void charconv2(int point)
{
    int k=0;
    while(point)
    {
        hscore[k++]=point%10+'0';
        point/=10;
    }
    hscore[k]=0;
    strrev(hscore);
}


void showhighscore()
{
    FILE *fp;
    fp=fopen("hscore.txt","r");
    for(int i=0; i<8; i++)
    {
        fscanf(fp,"%d\n",&highscore[i]);
    }
    fclose(fp);

    //sorting highscore-->bubble sorting
    for (int i=0; i<7; i++)
        for (int j=i+1; j<8; j++)
            if (highscore[j] > highscore[i])
            {
                int s;
                s=highscore[i];
                highscore[i]=highscore[j];
                highscore[j]=s;
            }


    iSetColor(255,201,14);
    charconv2(highscore[0]);
    strcpy(playmenuhighscore,hscore);
    iText(900,535,hscore,GLUT_BITMAP_TIMES_ROMAN_24);
    charconv2(highscore[1]);
    iText(900,470,hscore,GLUT_BITMAP_TIMES_ROMAN_24);
    charconv2(highscore[2]);
    iText(900,410,hscore,GLUT_BITMAP_TIMES_ROMAN_24);
    charconv2(highscore[3]);
    iText(900,360,hscore,GLUT_BITMAP_TIMES_ROMAN_24);
    charconv2(highscore[4]);
    iText(900,300,hscore,GLUT_BITMAP_TIMES_ROMAN_24);
    charconv2(highscore[5]);
    iText(900,240,hscore,GLUT_BITMAP_TIMES_ROMAN_24);
    charconv2(highscore[6]);
    iText(900,185,hscore,GLUT_BITMAP_TIMES_ROMAN_24);
    charconv2(highscore[7]);
    iText(900,125,hscore,GLUT_BITMAP_TIMES_ROMAN_24);
}


int main()
{
    //place your own initialization codes here.
    iSetTimer(5000,pacmove);
    iSetTimer(550,ghostimer);
    iSetTimer(500,ghost_index_changer);
    //iSetTimer(500,maze_color_changer);
    if(sound1)
    PlaySound(TEXT("PacMan.wav"),NULL,SND_LOOP|SND_ASYNC);
    iInitialize(1100, 690, "PACMAN!");

    return 0;
}

