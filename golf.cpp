/*******************************************************
Course		:	CO1302 Programming for Engineers
Year		:	2020
Name        :   Unique Golf
Group No	:	9
Index No	:	18_ENG_118 , 18_ENG_011 , 18_ENG_043 , 18_ENG_073
Date		:	09-01-2020
*******************************************************/

/**Note: before compiling the project need to include graphic.h library files and should change the linker settings**/

#include<iostream>
#include<graphics.h>
#include<fstream>
#include <math.h>
#include <string>


using namespace std;

//declare functions
void newGame();
void start();
void home(string);
void hittingProcess(int,int,int);
void ground(int,int);
int setBall(int,int);
int forceSelect();
void moveBall(float,float,float,float,int);
void golfClub(int,int);
void addLederBoard(int);
void readLeaderBoard();
void orbit();
void doll();
void dolldraw(int );
void dollmoll(int );



int main()
{

    initwindow(1080, 720);          //load a extra graphic window
    newGame();                      //function for new game
    getch();                        //wait for a key press
    closegraph();                   //close window
    return 0;
}

void newGame()
{

     home("1");                     //display home window
     start();                       //input name
     hittingProcess(100,500,100);   //x coordinate , y coordinate , score

}

void hittingProcess(int x,int y,int score)
{
    //declare variables
    int force,angle;
    ground(900,200);        //set default position for golf hole
    angle =setBall(x,y);    //call the angle setting function
    force=forceSelect();    //call the angle setting function
    golfClub(x,y);          //move the golf club
    moveBall(x,y,angle,force*100,score);//move the ball

}
void start()
{


    int x=900,y=500,ch;       //hole coordinate
    string name="";           //player name

    setcolor(YELLOW);
    setfillstyle(3, 4);
    setcolor(RED);
    circle(x,y,30);           //drawing of hole
    floodfill(x,y,RED);
    setcolor(10);


    setcolor(YELLOW);
  //flag drawing int the hole
    rectangle(x-1,y,x+1,y-105);
    arc(x+27,y-137,240,300,50);
    arc(x+27,y-97,240,300,50);
    arc(x+77,y-52,60,120,50);
    arc(x+77,y-12,60,120,50);
    line(x+102,y-94,x+102,y-54);


    settextstyle(8, 0, 7);
    outtextxy(50, 50,"Enter name");             //display text

    while(1){


     ch = getch();                              //getting key press
cout<<ch;
if(ch > 64 && ch < 123)                         //check for character validity*ascii range*
    {
        setcolor(10);
    settextstyle(8, 0, 5);
    name=name+char(ch);
char * lev = new char[name.length()];
    strcpy(lev,name.c_str());                   //copy string to char array
    outtextxy(200, 130,lev);                    //displaying player name
    }


if(ch==13)                                      //when press enter it will continue
    break;
}



    ofstream file("LederBoard.dat",ios::app);   //open the file for appending purpose

    while (file)                                //writing player name to the dat file
    {
        file<<name<<"\t";
        if(file.eof());
        break;
    }



cleardevice();                                  //clear the screen
}

void addLederBoard(int score)                   //adding score to the file
{

    ofstream file("LederBoard.dat",ios::app);   //open the file

    while (file){
        if(score<10)
    file<<"0"<<score<<endl;                     //if score is less than 10 adding a extra '0' at begining
    else
        file<<score<<endl;
    if(file.eof());
    break;
    }
cleardevice();                                  //clear the screen

}
void home(string level)                         //home page
{

    setcolor(10);
    rectangle(10,10, 1070, 710);
//displaying game name
    setcolor(YELLOW);
    settextstyle(5, 0, 10);
    outtextxy(100, 280, "Unique ");
    settextstyle(1, 0, 10);
    outtextxy(100, 420, "Golf");

    settextstyle(8, 0, 10);
    settextstyle(8, 0, 5);
    outtextxy(630, 450, "Level ");
    outtextxy(100, 640, "Loading...");

//flag holder
   line(700,50,1050,550);
    line(700,50,695,55);
    line(695,55,1045,555);
    line(1045,555,1050,550);
    line(442,250,530,375);






    setcolor(10);
    settextstyle(8, 0, 5);

    char * lev = new char[level.length() + 1];
    strcpy(lev,level.c_str());                  //copy string to char array
    outtextxy(800, 450,lev);                    //output level
    orbit();                                    //call function of animation

cleardevice();
}

void orbit()                                     //animations in home window
 {
     int R=5;
     float xx,yy,aa=15,bb=50,x,y,X,Y,a=34,b=0,A=100,B=60,ex,sq;
   setcolor(14);
   int j=0;
for(float i=0;j<=970;i+=.1,j+=5)
   {


   if(j%100==50)                 //to get 500ms delay
    {

            setcolor(0);
    //flag2
    arc(557,268,255,350,110);
    arc(469,143,255,350,110);
    arc(773,305,75,170,110);
    arc(685,180,75,170,110);

    setcolor(YELLOW);
    //flag1
    arc(600,55,255,350,110);
    arc(688,180,255,350,110);
    arc(550,268,75,170,110);
    arc(638,393,75,170,110);
    }
   if(j%100==0)                     //to get 500ms delay
    {
            setcolor(0);
    //flag1
    arc(600,55,255,350,110);
    arc(688,180,255,350,110);
    arc(550,268,75,170,110);
    arc(638,393,75,170,110);

       setcolor(YELLOW);
    //flag2
    arc(557,268,255,350,110);
    arc(469,143,255,350,110);
    arc(773,305,75,170,110);
    arc(685,180,75,170,110);
    }



setcolor(RED);
rectangle(60,680, 1030, 700);
setcolor(RED);
setfillstyle(1, RED);
circle(60+j,690,10);
floodfill(60+j,690,RED);
setcolor(0);


//displaying orbit
    x=a*cos(i+10)-a*sin(i+10);
    y=b*sin(i+10)+a*cos(i+10);

    X=A*cos(i+20)-B*sin(i+20+90);
    Y=B*sin(i+20)+B*cos(i+20+90);

    xx=aa*cos(i);
    yy=bb*sin(i);

    setcolor(14);
    setfillstyle(1,14);
    circle(x+100,y+100,R);
    floodfill(x+100,y+100,14);

    setcolor(14);
    setfillstyle(1,14);
    circle(xx+100,yy+100,R);
    floodfill(xx+100,yy+100,14);

    setcolor(14);
    setfillstyle(1,14);
    circle(X+100,Y+100,R);
    floodfill(X+100,Y+100,14);

    putpixel(X+100,Y+100,4);
    delay(50);

    setcolor(0);
    setfillstyle(1,0);
    circle(x+100,y+100,R);
    floodfill(x+100,y+100,0);

    setcolor(0);
    setfillstyle(1,0);
    circle(xx+100,yy+100,R);
    floodfill(xx+100,yy+100,0);

    setcolor(0);
    setfillstyle(1,0);
    circle(X+100,Y+100,R);
    floodfill(X+100,Y+100,0);
    for(float i=0;i<=60;i+=1)
        {
            float xx,yy,aa=15,bb=50,x,y,X,Y,a=34,b=0,A=100,B=60,ex,sq;
            x=a*cos(i)-a*sin(i);
            y=b*sin(i)+a*cos(i);

            X=A*cos(i)-B*sin(i+90);
            Y=B*sin(i)+B*cos(i+90);

            xx=aa*cos(i);
            yy=bb*sin(i);

            putpixel(x+100,y+100,14);
            putpixel(X+100,Y+100,14);
            putpixel(xx+100,yy+100,14);


        }


    }
}

void ground(int x,int y)
{


    setcolor(YELLOW);
    setfillstyle(3, 4);

    //golf hole
    setcolor(RED);
    circle(x,y,30);
    floodfill(x,y,RED);


    setcolor(10);



      //flag
    rectangle(x-1,y,x+1,y-105);
    arc(x+27,y-137,240,300,50);
    arc(x+27,y-97,240,300,50);
    arc(x+77,y-52,60,120,50);
    arc(x+77,y-12,60,120,50);
    line(x+102,y-94,x+102,y-54);

    //border of page
    rectangle(10,10, 1070, 710);
    floodfill(5, 5, 10);
    setfillstyle(1, 10);

    //objects in the ground
    setfillstyle(7, 10);
    rectangle(90,10,850,175);
    floodfill(95, 15, 10);
    setfillstyle(8, 10);
    rectangle(250,175,800,255);
    floodfill(300,200,10);
    setfillstyle(9, 10);
    rectangle(390,255,590,355);
    floodfill(400,300,10);
    setfillstyle(10, 10);
    rectangle(950,250,1070,550);
    floodfill(1000,300,10);
    setfillstyle(11, 10);
    rectangle(700,400,800,500);
    floodfill(750,450,10);
    rectangle(650,500,750,600);
    floodfill(700,550,10);
    setfillstyle(11, 9);
    rectangle(250,500,350,600);
    floodfill(300,550,10);



     //water pond in the ground
     arc(300,500,0,180,50);
     floodfill(300,470,10);
     arc(350,550,-90,90,50);
     floodfill(375,550,10);
     arc(300,600,180,0,50);
     floodfill(300,630,10);
     arc(250,550,90,-90,50);
     floodfill(220,550,10);
}
int setBall(int xco,int yco)
{
    //declare variables
    int r=60,ch;
    float x,y,theta;
    int angle=0;
	int i,a;


    //check for user input of spacebar
    while(ch!=32)
	{

        setcolor(RED);
        circle(xco,yco,15);
        floodfill(xco,yco,RED);
        setfillstyle(1, 10);
        setcolor(YELLOW);

        theta=M_PI*angle/180;
		x=xco+r*cos(theta)+4;
		y=yco+r*sin(theta);
		line(xco,yco,x,y);

		delay(20);

        setcolor(0);
        setfillstyle(1,0);
        line(xco,yco,x,y);

        angle+=1;

        ground(900,200);
			if(kbhit())
                {
                    ch = getch();
                    break;
                }




	}


        angle%=360;
        return angle;


}

//function of moving golf bat
void golfClub(int x,int y)
{
    Beep(587.3295,200);             //output beep sound

    setcolor(YELLOW);

    //1st bat
    line(x-75,y-130,x-35,y+10);
    line(x-85,y-130,x-45,y+10);
    line(x-75,y-130,x-85,y-130);
    line(x-35,y+10,x-45,y+10);
    arc(x-36.8,y+3.2,-71.565,113.5,8);
    delay(500);
    setcolor(0);
    line(x-75,y-130,x-35,y+10);
    line(x-85,y-130,x-45,y+10);
    line(x-75,y-130,x-85,y-130);
    line(x-35,y+10,x-45,y+10);
    arc(x-36.8,y+3.2,-71.565,113.5,8);

    setcolor(YELLOW);
    //2nd bat
     line(x-85,y-130,x-25,y+10);
    line(x-75,y-130,x-15,y+10);
    line(x-85,y-130,x-75,y-130);
    line(x-25,y+10,x-15,y+10);
    arc(x-17.8,y+3.2,-71.565,113.5,8);
    delay(500);
    setcolor(0);
    line(x-85,y-130,x-25,y+10);
    line(x-75,y-130,x-15,y+10);
    line(x-85,y-130,x-75,y-130);
    line(x-25,y+10,x-15,y+10);
    arc(x-17.8,y+3.2,-71.565,113.5,8);

    setcolor(YELLOW);
    //3rd bat
    line(x-85,y-130,x+5,y+10);
    line(x-75,y-130,x+15,y+10);
    line(x-85,y-130,x-75,y-130);
    line(x+5,y+10,x+15,y+10);
    arc(x+13.2,y+3.2,-71.565,130.5,8);
    delay(500);
    setcolor(0);
    line(x-85,y-130,x+5,y+10);
    line(x-75,y-130,x+15,y+10);
    line(x-85,y-130,x-75,y-130);
    line(x+5,y+10,x+15,y+10);
    arc(x+13.2,y+3.2,-71.565,130.5,8);

    setcolor(RED);
    Beep(783.9909,200);          //output beep sound
}

//function for selecting force
int forceSelect()
{

    int force;
    int ch;

    for (force=0;force<150;force++)
        {

        rectangle(60,675, 210, 685);
        setcolor(0);
        circle(60+force,680,10);

        setfillstyle(1, RED);

        }


    setcolor(YELLOW);
    while(ch!=32)
    {

    setcolor(YELLOW);
    settextstyle(8, 0, 3);
    outtextxy(65, 645, "Force");
        for (force=0;force<150;force++)
    {

        rectangle(60,675, 210, 685);
        setcolor(RED);
        circle(60+force,680,10);
        //floodfill(60+i,680,RED);
        setfillstyle(1, RED);
        if(kbhit())
        {
            ch = getch();
            break;
        }

        delay(15);

    }
    if(ch!=32)
    {
            for (force=0;force<150;force++)
        {

            rectangle(60,675, 210, 685);
            setcolor(0);
            circle(60+force,680,10);

            setfillstyle(1, RED);

        }
    }
}

    return force;
}

int checkWalls(float x,float y)
{

    if((x>10-8)&&(x<1070+8)&&(y>10-8)&&(y<710+8))
    {
    cout<<"x"<<x<<endl<<"y"<<y;


    if((x>90-8)&&(x<850+8)&&(y>10-8)&&(y<170+8))
    return 1;

    else if((x>250-8)&&(x<800+8)&&(y>175-8)&&(y<255+8))
    return 1;

    else if((x>390-8)&&(x<590+8)&&(y>255-8)&&(y<355+8))
    return 1;

    else if((x>950-8)&&(x<1070+8)&&(y>250-8)&&(y<550+8))
    return 1;

    else if((x>700-8)&&(x<800+8)&&(y>400-8)&&(y<500+8))
    return 1;

    else if((x>650-8)&&(x<500+8)&&(y>750-8)&&(y<600+8))
    return 1;

    else if((x>200-8)&&(x<400+8)&&(y>450-8)&&(y<650+8))
    return 1;


}
    else
    {
        doll();
        readLeaderBoard();
    }

}

void moveBall(float currentx,float currenty,float angle,float force,int score)
{
     //declare variables
     float velocity,time,xmove,ymove;
	 float newx,newy,verticleAngle=45;

	 //function for velocity calculation
     velocity=(force*0.01)*0.5;

     //function for time calculation
     time=(2*velocity*cos(verticleAngle*M_PI/180))/9.81;

     //new coordinates according to the user input
     newx=velocity*sin(verticleAngle*M_PI/180)*cos(angle*M_PI/180)*time;
     newy=velocity*sin(verticleAngle*M_PI/180)*sin(angle*M_PI/180)*time;

    //check for the sign of the new moving position
    if(newx>=0)
        {
            //loop for moving
            for( xmove=0;xmove<newx;xmove+=4)
            {

            //calculate y coordinate
            ymove =((newy)/(newx))*xmove;


            //drawing the ball according to new position
            setcolor(RED);
            circle(xmove+currentx,ymove+currenty,15);
            setfillstyle(1,10);
            floodfill(xmove+currentx,ymove+currenty,RED);
            setcolor(YELLOW);
            delay(50);

            //erasing the ball
            setcolor(0);
            circle(xmove+currentx,ymove+currenty,15);
            setfillstyle(1,0);
            floodfill(xmove+currentx,ymove+currenty,0);
            setcolor(0);
            if(xmove>5)
                {
                    if(checkWalls((xmove+currentx),(ymove+currenty))==1)
                    break;
                }
                 }
        }

        else
        {
            //loop for moving
            for( xmove=0;xmove>newx;(xmove-=2))
            {

                ymove =((newy)/(newx))*xmove;

                //drawing the ball according to new position
                setcolor(RED);
                circle(xmove+currentx,ymove+currenty,15);
                setfillstyle(1,10);
                floodfill(xmove+currentx,ymove+currenty,RED);
                setcolor(YELLOW);
                delay(100);

                //erasing the ball
                setcolor(0);
                circle(xmove+currentx,ymove+currenty,15);
                setfillstyle(1,0);
                floodfill(xmove+currentx,ymove+currenty,0);
                setcolor(0);
                if(xmove>5)
                {
                    if(checkWalls((xmove+currentx),(ymove+currenty))==1)
                    break;
                }
            }
        }

        //drawing the ball according to new position
        setcolor(RED);
        circle(xmove+currentx,ymove+currenty,15);
        setfillstyle(1,10);
        floodfill(xmove+currentx,ymove+currenty,RED);
        setcolor(YELLOW);
        delay(100);

//check for the range of the golf hole **if the golf ball goes to hole**
if((((xmove+currentx)>880)&&((xmove+currentx)<920))&&(((ymove+currenty)>180)&&((ymove+currenty)<220)))
{
    addLederBoard(score);       //function for adding score to file
    readLeaderBoard();          //reading leader board
}
else
    //hitting again
    hittingProcess((xmove+currentx),(ymove+currenty),score-=5);
}


//drawing of a man with hand in up direction
void dolldraw(int x)
	{
	    //drawing of a man
		int y=100;
		circle(x,y+10,10);
		line(x,y+20,x,y+100);
		line(x,y+40,x-20,y+70);
		line(x,y+40,x+20,y+70);
		line(x,y+100,x-20,y+120);
		line(x,y+100,x+20,y+120);
	}

//drawing of a man with hand in down direction
void dollmoll(int x)
	{

		int y=100;
		circle(x,y+10,10);
		line(x,y+20,x,y+100);
		line(x,y+50,x-20,y+30);
		line(x,y+50,x+20,y+30);
		line(x,y+100,x-20,y+90);
		line(x,y+100,x+20,y+90);
	}

//drawing the ball lose window
void doll()
	{
	    //output set of beep sounds
        Beep(523.2511,400);
        Beep(587.3295,400);
        Beep(659.2551,400);
        Beep(698.4565,400);
        Beep(783.9909,400);
	    //declare variables
	    int w=50;
        int h,i,j,k;
        //wait for key press of user
	while(!kbhit())
	{
	    //drawing couple of men with hands in upward
	    setcolor(YELLOW);
	    w=220;
		dolldraw(w);
		h=w+45;
		dolldraw(h);
		j=h+45;
		dolldraw(j);
		i=j+45;
		dolldraw(i);
		k=i+45;
		dolldraw(k);
		delay(500);
		cleardevice();

		//drawing couple of men with hands in downward
		dollmoll(w);
		dollmoll(h);
		dollmoll(i);
		dollmoll(j);
		dollmoll(k);


    settextstyle(1, 0, 5);
    outtextxy(150, 280, "You Lost The Ball !!!");


		delay(1000);        //delay 1 second
		cleardevice();      //clear screen
	}

	}

void readLeaderBoard()
{
    cleardevice();          //clear screen

     //declare variables
     string name,nameA[100],tempName;
     int location = 210;
     string score,scoreA[100],tempScore;
     int count=0;

    //display leader board
    outtextxy(0, 100, "===============================================================================");
    outtextxy(0, 130, "                            ---Current LeaderBoard---");
    outtextxy(0, 160, "===============================================================================");
    outtextxy(100, 190, "Name");
    outtextxy(300, 190, "Score");

        //getting name and the score from the file
        ifstream file("LederBoard.dat");

        while (file)
        {
            file>>name>>score;      //get the player name from the file
            scoreA[count]=score;    //get the player score from the file
            nameA[count]=name;
            count++;
            if(file.eof());
        }
    count--;
    //sorting player score - DESCENDING ORDER
	for(int i=0;i<count;i++)
	{
		for(int j=i+1;j<count;j++)
		{
			if(scoreA[i]<scoreA[j])
			{
				tempScore  =scoreA[i];      //storing to a temporary variable
				scoreA[i]=scoreA[j];
				scoreA[j]=tempScore;

				tempName  =nameA[i];        //storing to a temporary variable
				nameA[i]=nameA[j];
				nameA[j]=tempName;
			}
		}
	}


    for(int i=0;i<7;i++)
    {
        char * charName = new char[nameA[i].length() + 1];
        strcpy(charName,nameA[i].c_str());      //copy string to char array

        char * charScore = new char[scoreA[i].length() + 1];
        strcpy(charScore,scoreA[i].c_str());    //copy string to char array

        outtextxy(100, location,charName);      //display player name
        outtextxy(300, location,charScore);     //display player score
        location+=20;
    }

        outtextxy(0, location, "===============================================================================");

      //output set of beep sounds
      Beep(523.2511,400);
      Beep(587.3295,400);
      Beep(659.2551,400);
      Beep(698.4565,400);
      Beep(783.9909,400);

      int ch =getch();        //wait for a key press

      cleardevice();          //clear screen
      newGame();              //call for a new game

}

