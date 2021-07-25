#include<graphics.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<dos.h>
#include<constream.h>
#include<process.h>
#include<iomanip.h>
#include<fstream.h>


#define  up     72
#define  down   80
#define  left   75
#define  right  77



void animate(){
  int gd = DETECT, gm,x=40,y=150;
  initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

    for(x=0;x<110;x+=5){
     textcolor(BLUE);
     settextstyle(0,0,4);
      outtextxy(x, y, "Periodic table");
      delay(50);
      clrscr();
    }
    outtextxy(x, y, "Periodic table");
     settextstyle(0,0,2);
    outtextxy(x+50, y+40, "BY- SOURABH BUCHA");
   textcolor(RED);
  getch();
  closegraph();

}


struct eleinfo
  {
	int atm,mass;
	char name[50],symb[5];
	float ion;
  };


void data(eleinfo elem[150])
 {
  ifstream dat("text.txt");
   char element[50],symbol[5];
   int atomic_number,mass_number,i=0;
   float ion;
	while(dat >> atomic_number >> mass_number >> element >> symbol >> ion)
	{
		elem[i].atm=atomic_number;
		elem[i].mass=mass_number;
		elem[i].ion=ion;
		strcpy(elem[i].name,element);
		strcpy(elem[i].symb,symbol);
		i++;
	}
   dat.close();
}



void print(int x1,int y1,eleinfo elem[],int p)
{
   gotoxy(x1,y1);
   cout<<elem[p].symb;
}


void detail(int p,eleinfo einf[])
{
clrscr();
  gotoxy(15,10);
   cout<<"Name of Element";
  gotoxy(42,10);
   cout<<":"<<einf[p].name;
  gotoxy(15,11);
   cout<<"Symbol of Element";
  gotoxy(42,11);
   cout<<":"<<einf[p].symb;
  gotoxy(15,12);
   cout<<"Atomic Number of Element";
  gotoxy(42,12);
   cout<<":"<<einf[p].atm;
  gotoxy(15,13);
   cout<<"Mass Number of Element";
  gotoxy(42,13);
   cout<<":"<<einf[p].mass;
  gotoxy(15,14);
   cout<<"Ionisation Energy";
  gotoxy(42,14);
   cout<<":"<<einf[p].ion;
 getch();
}

void disp(int x,int y,eleinfo einf[]){
if(x==4&&y==7){
detail(0,einf);
}
if(x==72&&y==7){
detail(1,einf);
}
if(x==4&&y==8){
detail(2,einf);
}
if(x==8&&y==8){
detail(3,einf);
}
for(int i=13;i<19;i++){
if(x==4*i&&y==8){
detail(i-9,einf);
}
}

if(x==4&&y==9){
detail(10,einf);
}
if(x==8&&y==9){
detail(11,einf);
}
for(i=13;i<19;i++){
if(x==4*i&&y==9){
detail(i-1,einf);
}
}

for(i=1;i<19;i++){
if(x==4*i&&y==10){
detail(17+i,einf);
}
}

for(i=1;i<19;i++){
if(x==4*i&&y==11){
detail(35+i,einf);
}
}


for(i=1;i<19;i++){
if(x==4*i&&y==12){
detail(53+i,einf);
}
}


for(i=1;i<19;i++){
if(x==4*i&&y==13){
detail(71+i,einf);
}
}
for(i=1;i<9;i++){
if(x==4*i&&y==14){
detail(85+i,einf);
}
}

}

void move(eleinfo einf[])
 {
  char ch;
  int x=2,y=2;
   lable:
    if(x<2)
     x=2;
    if(y<2)
     y=2;
    if(x>78)
     x=78;
    if(y>19)
     y=19;
    gotoxy(x,y);
    ch=getch();
    switch(ch){
	case up: y--; break;
	case down: y++; break;
	case left: x--; break;
	case right: x++; break;
	case 'y': textcolor(3)	;
		disp(x,y,einf);
		textcolor(RED);
		goto back;
		break;
	case 'x': exit(0); break;
	}
    goto lable;
   back:
 }

void main(){
animate();
lable1:
clrscr();
eleinfo einf[150];
data(einf);
print(4,7,einf,0);
print(4*18,7,einf,1);
print(4,8,einf,2);
print(4*2,8,einf,3);
print(4*13,8,einf,4);
print(4*14,8,einf,5);
print(4*15,8,einf,6);
print(4*16,8,einf,7);
print(4*17,8,einf,8);
print(4*18,8,einf,9);
print(4,9,einf,10);
print(4*2,9,einf,11);
print(4*13,9,einf,12);
print(4*14,9,einf,13);
print(4*15,9,einf,14);
print(4*16,9,einf,15);
print(4*17,9,einf,16);
print(4*18,9,einf,17);
for(int i=1;i<19;i++){
print(4*i,10,einf,17+i);}
for(i=1;i<19;i++){
print(4*i,11,einf,35+i);}
for(i=1;i<19;i++){
print(4*i,12,einf,53+i);}
for(i=1;i<19;i++){
print(4*i,13,einf,71+i);}
gotoxy(2,20);
cout<<"=============================================================================="<<endl;
cout<<"			Use Arrow Keys to Move The Cursor"<<endl;
cout<<"				Press X to EXIT"<<endl;
cout<<"		      	    Press Y to View DETAILS"<<endl;
move(einf);
goto lable1;
}
