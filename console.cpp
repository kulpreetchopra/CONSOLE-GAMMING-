#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define v 219,219
#include<stdlib.h>
using namespace std;
int _shape_,s_v,speed=1,dir_x,count,score;
void gotoxy(int x,int y){
	COORD c;
    c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void delay(){
	int x;
	for(x=0;x<100000000/speed;x++);
}
int ordinate[80][80];
int shape_ordinate[8][2],prev[8][2];
int b_o[30][2];
void check(){
	int i,j,temp=0,k;
	for(i=22;i<52;i++)
	if(ordinate[i][8]==1){
	system("cls");
	exit(0);
	}

	for(i=5;i<31;i++){
	temp=0;
		for(j=22;j<52;j++)
		if(ordinate[j][i]==1){
		temp++;
		}
		if(temp==30){
			score+=100;
		break;
		}
		}
		if(temp==30)
		for(j=22;j<52;j++)
		ordinate[j][i]=0;
		if(temp==30)
		for(;i>=0;i--)
			for(j=22;j<52;j++)
		ordinate[j][i]=ordinate[j][i-1];
	if(temp==30)
	for(i=5;i<31;i++){
	gotoxy(22,i);
	for(k=22;k<52;k++)
	printf(" ");
	}
	if(temp==30)
	for(i=5;i<31;i++){
		for(j=22;j<52;j++)
		if(ordinate[j][i]==1){
		gotoxy(j,i);
		printf("%c",219);
		}
	}
	}
void clean(){
	int i,j;
	for(i=0;i<7;i++){
	    gotoxy(7,4+i);
		for(j=0;j<10;j++){
			printf(" ");
		}
	}
}
void constructor(){
	int i,j,count=0,k;
	for(i=0;i<26;i++){
		for(j=0;j<30;j++)
		ordinate[i][j]=0;
	}
	for(i=22;i<=53;i++){
		b_o[count][0]=i;
		b_o[count][1]=30;
		count++;
	}
	dir_x=0;
	count=0;
	s_v=0;
	_shape_=1;
	score=0;
}
void update(){
        shape_ordinate[0][0]=0;
		shape_ordinate[0][1]=0;
		shape_ordinate[1][0]=0;
	    shape_ordinate[1][1]=0;
		shape_ordinate[2][0]=0;
		shape_ordinate[2][1]=0;
		shape_ordinate[3][0]=0;
		shape_ordinate[3][1]=0;
		shape_ordinate[4][0]=0;
		shape_ordinate[4][1]=0;
		shape_ordinate[5][0]=0;
		shape_ordinate[5][1]=0;
		shape_ordinate[6][0]=0;
		shape_ordinate[6][1]=0;
		shape_ordinate[7][0]=0;
		shape_ordinate[7][1]=0;
}
void border(){
	int i,j;
	for(i=1;i<=30;i++){
		gotoxy(5,2+i);
		for(j=1;j<=50;j++){
		if(i==1||i==30||j==1||j==50||j==15||(i==10&&j<=15))
		printf("%c",219);
		else if(j==17||j==48||(i==2&&j>15)||(i==29&&j>15))
		printf("#");
		else{
		printf(" ");
        }
		}
		printf("\n");
	}
	gotoxy(7,11);
	printf("Next :");
	gotoxy(7,17);
	printf("Hlw, Player");
	gotoxy(7,19);
	printf("Your Score: ");
	gotoxy(7,23);
	printf("Press X to ");
	gotoxy(7,25);
	printf("Exit");
	gotoxy(7,27);
	printf("Press N for ");
	gotoxy(7,29);
	printf(" New Game");
}
void shape_(int x,int y,int shape,int s_v,int p){
	int i,temp=0;
	gotoxy(x,y);
	switch(shape){
		case 0: switch(s_v){
			case 0:
			if(p==1){
			shape_ordinate[0][0]=x+2;
			shape_ordinate[0][1]=y;
			shape_ordinate[1][0]=x+3;
			shape_ordinate[1][1]=y;
			shape_ordinate[2][0]=x;
			shape_ordinate[2][1]=y+1;
			shape_ordinate[3][0]=x+1;
			shape_ordinate[3][1]=y+1;
			shape_ordinate[4][0]=x+2;
			shape_ordinate[4][1]=y+1;
			shape_ordinate[5][0]=x+3;
			shape_ordinate[5][1]=y+1;
			shape_ordinate[6][0]=x+4;
			shape_ordinate[6][1]=y+1;
			shape_ordinate[7][0]=x+5;
			shape_ordinate[7][1]=y+1;
			}
			for(i=0;i<8;i++)
	        if(shape_ordinate[i][0]>=52)
	        temp=1;
	        if(temp==1){
	        dir_x-=2;
	        x-=2;
	        for(i=0;i<8;i++)
	        shape_ordinate[i][0]-=2;
			}
			gotoxy(x+2,y);
			printf("%c%c",v);
			gotoxy(x,y+1);
			printf("%c%c%c%c%c%c",v,v,v);
			break;
			case 1:
			if(p==1){
			shape_ordinate[0][0]=x;
			shape_ordinate[0][1]=y;
			shape_ordinate[1][0]=x+1;
			shape_ordinate[1][1]=y;
			shape_ordinate[2][0]=x+2;
			shape_ordinate[2][1]=y;
			shape_ordinate[3][0]=x+3;
			shape_ordinate[3][1]=y;
			shape_ordinate[4][0]=x+4;
			shape_ordinate[4][1]=y;
			shape_ordinate[5][0]=x+5;
			shape_ordinate[5][1]=y;
			shape_ordinate[6][0]=x+2;
			shape_ordinate[6][1]=y+1;
			shape_ordinate[7][0]=x+3;
			shape_ordinate[7][1]=y+1;
			}
			for(i=0;i<8;i++)
	        if(shape_ordinate[i][0]>=52)
	        temp=1;
	        if(temp==1){
	        dir_x-=2;
	        x-=2;
	        for(i=0;i<8;i++)
	        shape_ordinate[i][0]-=2;
			}
			printf("%c%c%c%c%c%c",v,v,v);
			gotoxy(x+2,y+1);
			printf("%c%c",v);
			break;
			case 2:
			if(p==1){
			shape_ordinate[0][0]=x;
			shape_ordinate[0][1]=y;
			shape_ordinate[1][0]=x+1;
			shape_ordinate[1][1]=y;
			shape_ordinate[2][0]=x;
			shape_ordinate[2][1]=y+1;
			shape_ordinate[3][0]=x+1;
			shape_ordinate[3][1]=y+1;
			shape_ordinate[4][0]=x+2;
			shape_ordinate[4][1]=y+1;
			shape_ordinate[5][0]=x+3;
			shape_ordinate[5][1]=y+1;
			shape_ordinate[6][0]=x;
			shape_ordinate[6][1]=y+2;
			shape_ordinate[7][0]=x+1;
			shape_ordinate[7][1]=y+2;
			}
			for(i=0;i<8;i++)
	        if(shape_ordinate[i][0]>=52)
	        temp=1;
	        if(temp==1){
	        dir_x-=2;
	        x-=2;
			for(i=0;i<8;i++)
	        shape_ordinate[i][0]-=2;
			}
			printf("%c%c",v);
			gotoxy(x,y+1);
			printf("%c%c%c%c",v,v);
			gotoxy(x,y+2);
			printf("%c%c",v);
			break;
			case 3:
			if(p==1){
			shape_ordinate[0][0]=x+2;
			shape_ordinate[0][1]=y;
			shape_ordinate[1][0]=x+3;
			shape_ordinate[1][1]=y;
			shape_ordinate[2][0]=x;
			shape_ordinate[2][1]=y+1;
			shape_ordinate[3][0]=x+1;
			shape_ordinate[3][1]=y+1;
			shape_ordinate[4][0]=x+2;
			shape_ordinate[4][1]=y+1;
			shape_ordinate[5][0]=x+3;
			shape_ordinate[5][1]=y+1;
			shape_ordinate[6][0]=x+2;
			shape_ordinate[6][1]=y+2;
			shape_ordinate[7][0]=x+3;
			shape_ordinate[7][1]=y+2;
			}
			for(i=0;i<8;i++)
	        if(shape_ordinate[i][0]>=52)
	        temp=1;
	        if(temp==1){
	        dir_x-=2;
	        x-=2;
	        for(i=0;i<8;i++)
	        shape_ordinate[i][0]-=2;
			}
			gotoxy(x+2,y);
			printf("%c%c",v);
			gotoxy(x,y+1);
			printf("%c%c%c%c",v,v);
			gotoxy(x+2,y+2);
			printf("%c%c",v);
			break;
		}
		break;
		case 1:
		if(p==1){
		    shape_ordinate[0][0]=x;
			shape_ordinate[0][1]=y;
			shape_ordinate[1][0]=x+1;
			shape_ordinate[1][1]=y;
			shape_ordinate[2][0]=x;
			shape_ordinate[2][1]=y+1;
			shape_ordinate[3][0]=x+1;
			shape_ordinate[3][1]=y+1;
			shape_ordinate[4][0]=x;
			shape_ordinate[4][1]=y+2;
			shape_ordinate[5][0]=x+1;
			shape_ordinate[5][1]=y+2;
			shape_ordinate[6][0]=x;
			shape_ordinate[6][1]=y+3;
			shape_ordinate[7][0]=x+1;
			shape_ordinate[7][1]=y+3;
		}
		for(i=0;i<8;i++)
	        if(shape_ordinate[i][0]>=52)
	        temp=1;
	        if(temp==1){
	        dir_x-=2;
	        x-=2;
			for(i=0;i<8;i++)
	        shape_ordinate[i][0]-=2;
			}
		printf("%c%c",v);
		gotoxy(x,y+1);
		printf("%c%c",v);
		gotoxy(x,y+2);
		printf("%c%c",v);
		gotoxy(x,y+3);
		printf("%c%c",v);
		break;
		case 2:
		if(p==1){
		    shape_ordinate[0][0]=x;
			shape_ordinate[0][1]=y;
			shape_ordinate[1][0]=x+1;
			shape_ordinate[1][1]=y;
			shape_ordinate[2][0]=x+2;
			shape_ordinate[2][1]=y;
			shape_ordinate[3][0]=x+3;
			shape_ordinate[3][1]=y;
			shape_ordinate[4][0]=x;
			shape_ordinate[4][1]=y+1;
			shape_ordinate[5][0]=x+1;
			shape_ordinate[5][1]=y+1;
			shape_ordinate[6][0]=x+2;
			shape_ordinate[6][1]=y+1;
			shape_ordinate[7][0]=x+3;
			shape_ordinate[7][1]=y+1;
		}
		for(i=0;i<8;i++)
	        if(shape_ordinate[i][0]>=52)
	        temp=1;
	        if(temp==1){
	        dir_x-=2;
	        x-=2;
			for(i=0;i<8;i++)
	        shape_ordinate[i][0]-=2;
			}
		printf("%c%c%c%c",v,v);
		gotoxy(x,y+1);
		printf("%c%c%c%c",v,v);
		break;
		case 3:switch(s_v){
			case 1:
		    if(p==1){
			shape_ordinate[0][0]=x;
			shape_ordinate[0][1]=y;
			shape_ordinate[1][0]=x+1;
			shape_ordinate[1][1]=y;
			shape_ordinate[2][0]=x;
			shape_ordinate[2][1]=y+1;
			shape_ordinate[3][0]=x+1;
			shape_ordinate[3][1]=y+1;
			shape_ordinate[4][0]=x;
			shape_ordinate[4][1]=y+2;
			shape_ordinate[5][0]=x+1;
			shape_ordinate[5][1]=y+2;
			shape_ordinate[6][0]=x+2;
			shape_ordinate[6][1]=y+2;
			shape_ordinate[7][0]=x+3;
			shape_ordinate[7][1]=y+2;
			}
			for(i=0;i<8;i++)
	        if(shape_ordinate[i][0]>=52)
	        temp=1;
	        if(temp==1){
	        dir_x-=2;
	        x-=2;
			for(i=0;i<8;i++)
	        shape_ordinate[i][0]-=2;
			}
			printf("%c%c",v);
		    gotoxy(x,y+1);
		    printf("%c%c",v);
		    gotoxy(x,y+2);
		    printf("%c%c%c%c",v,v);
			break;
			case 0:
			if(p==1){
			shape_ordinate[0][0]=x;
			shape_ordinate[0][1]=y;
			shape_ordinate[1][0]=x+1;
			shape_ordinate[1][1]=y;
			shape_ordinate[2][0]=x+2;
			shape_ordinate[2][1]=y;
			shape_ordinate[3][0]=x+3;
			shape_ordinate[3][1]=y;
			shape_ordinate[4][0]=x;
			shape_ordinate[4][1]=y+1;
			shape_ordinate[5][0]=x+1;
			shape_ordinate[5][1]=y+1;
			shape_ordinate[6][0]=x;
			shape_ordinate[6][1]=y+2;
			shape_ordinate[7][0]=x+1;
			shape_ordinate[7][1]=y+2;
			}
			for(i=0;i<8;i++)
	        if(shape_ordinate[i][0]>=52)
	        temp=1;
	        if(temp==1){
	        dir_x-=2;
	        x-=2;
			for(i=0;i<8;i++)
	        shape_ordinate[i][0]-=2;
			}
			printf("%c%c%c%c",v,v);
			gotoxy(x,y+1);
			printf("%c%c",v);
			gotoxy(x,y+2);
			printf("%c%c",v);
			break;
		}
	    break;
	    case 4:switch(s_v){
			case 0:
	        if(p==1){
	        shape_ordinate[0][0]=x+2;
			shape_ordinate[0][1]=y;
			shape_ordinate[1][0]=x+3;
			shape_ordinate[1][1]=y;
			shape_ordinate[2][0]=x+2;
			shape_ordinate[2][1]=y+1;
			shape_ordinate[3][0]=x+3;
			shape_ordinate[3][1]=y+1;
			shape_ordinate[4][0]=x;
			shape_ordinate[4][1]=y+2;
			shape_ordinate[5][0]=x+1;
			shape_ordinate[5][1]=y+2;
			shape_ordinate[6][0]=x+2;
			shape_ordinate[6][1]=y+2;
			shape_ordinate[7][0]=x+3;
			shape_ordinate[7][1]=y+2;
			}
			for(i=0;i<8;i++)
	        if(shape_ordinate[i][0]>=52)
	        temp=1;
	        if(temp==1){
	        dir_x-=2;
	        x-=2;
			for(i=0;i<8;i++)
	        shape_ordinate[i][0]-=2;
			}
			gotoxy(x+2,y);
		    printf("%c%c",v);
		    gotoxy(x+2,y+1);
		    printf("%c%c",v);
	        gotoxy(x,y+2);
	        printf("%c%c%c%c",v,v);
			break;
			case 1:
			if(p==1){
			shape_ordinate[0][0]=x;
			shape_ordinate[0][1]=y;
			shape_ordinate[1][0]=x+1;
			shape_ordinate[1][1]=y;
			shape_ordinate[2][0]=x+2;
			shape_ordinate[2][1]=y;
			shape_ordinate[3][0]=x+3;
			shape_ordinate[3][1]=y;
			shape_ordinate[4][0]=x+2;
			shape_ordinate[4][1]=y+1;
			shape_ordinate[5][0]=x+3;
			shape_ordinate[5][1]=y+1;
			shape_ordinate[6][0]=x+2;
			shape_ordinate[6][1]=y+2;
			shape_ordinate[7][0]=x+3;
			shape_ordinate[7][1]=y+2;
			}
			for(i=0;i<8;i++)
	        if(shape_ordinate[i][0]>=52)
	        temp=1;
	        if(temp==1){
	        dir_x-=2;
	        x-=2;
	        for(i=0;i<8;i++)
	        shape_ordinate[i][0]-=2;
			}
			printf("%c%c%c%c",v,v);
			gotoxy(x+2,y+1);
			printf("%c%c",v);
			gotoxy(x+2,y+2);
			printf("%c%c",v);
			break;
		}
		break;
		case 5:switch(s_v){
			case 0:
			if(p==1){
			shape_ordinate[0][0]=x+2;
			shape_ordinate[0][1]=y;
			shape_ordinate[1][0]=x+3;
			shape_ordinate[1][1]=y;
			shape_ordinate[2][0]=x;
			shape_ordinate[2][1]=y+1;
			shape_ordinate[3][0]=x+1;
			shape_ordinate[3][1]=y+1;
			shape_ordinate[4][0]=x+2;
			shape_ordinate[4][1]=y+1;
			shape_ordinate[5][0]=x+3;
			shape_ordinate[5][1]=y+1;
			shape_ordinate[6][0]=x;
			shape_ordinate[6][1]=y+2;
			shape_ordinate[7][0]=x+1;
			shape_ordinate[7][1]=y+2;
			}
			for(i=0;i<8;i++)
	        if(shape_ordinate[i][0]>=52)
	        temp=1;
	        if(temp==1){
	        dir_x-=2;
	        x-=2;
			for(i=0;i<8;i++)
	        shape_ordinate[i][0]-=2;
			}
			gotoxy(x+2,y);
			printf("%c%c",v);
			gotoxy(x,y+1);
			printf("%c%c%c%c",v,v);
			gotoxy(x,y+2);
			printf("%c%c",v);
			break;
			case 1:
			if(p==1){
			shape_ordinate[0][0]=x;
			shape_ordinate[0][1]=y;
			shape_ordinate[1][0]=x+1;
			shape_ordinate[1][1]=y;
			shape_ordinate[2][0]=x;
			shape_ordinate[2][1]=y+1;
			shape_ordinate[3][0]=x+1;
			shape_ordinate[3][1]=y+1;
			shape_ordinate[4][0]=x+2;
			shape_ordinate[4][1]=y+1;
			shape_ordinate[5][0]=x+3;
			shape_ordinate[5][1]=y+1;
			shape_ordinate[6][0]=x+2;
			shape_ordinate[6][1]=y+2;
			shape_ordinate[7][0]=x+3;
			shape_ordinate[7][1]=y+2;
			}
			for(i=0;i<8;i++)
	        if(shape_ordinate[i][0]>=52)
	        temp=1;
	        if(temp==1){
	        dir_x-=2;
	        x-=2;
			for(i=0;i<8;i++)
	        shape_ordinate[i][0]-=2;
			}
			printf("%c%c",v);
			gotoxy(x,y+1);
			printf("%c%c%c%c",v,v);
			gotoxy(x+2,y+2);
			printf("%c%c",v);
			break;
			case 2:
			if(p==1){
			shape_ordinate[0][0]=x+2;
			shape_ordinate[0][1]=y;
			shape_ordinate[1][0]=x+3;
			shape_ordinate[1][1]=y;
			shape_ordinate[2][0]=x+4;
			shape_ordinate[2][1]=y;
			shape_ordinate[3][0]=x+5;
			shape_ordinate[3][1]=y;
			shape_ordinate[4][0]=x;
			shape_ordinate[4][1]=y+1;
			shape_ordinate[5][0]=x+1;
			shape_ordinate[5][1]=y+1;
			shape_ordinate[6][0]=x+2;
			shape_ordinate[6][1]=y+1;
			shape_ordinate[7][0]=x+3;
			shape_ordinate[7][1]=y+1;
			}
			for(i=0;i<8;i++)
	        if(shape_ordinate[i][0]>=52)
	        temp=1;
	        if(temp==1){
	        dir_x-=2;
	        x-=2;
			for(i=0;i<8;i++)
	        shape_ordinate[i][0]-=2;
			}
			gotoxy(x+2,y);
			printf("%c%c%c%c",v,v);
			gotoxy(x,y+1);
			printf("%c%c%c%c",v,v);
			break;
			case 3:
			if(p==1){
			shape_ordinate[0][0]=x;
			shape_ordinate[0][1]=y;
			shape_ordinate[1][0]=x+1;
			shape_ordinate[1][1]=y;
			shape_ordinate[2][0]=x+2;
			shape_ordinate[2][1]=y;
			shape_ordinate[3][0]=x+3;
			shape_ordinate[3][1]=y;
			shape_ordinate[4][0]=x+2;
			shape_ordinate[4][1]=y+1;
			shape_ordinate[5][0]=x+3;
			shape_ordinate[5][1]=y+1;
			shape_ordinate[6][0]=x+4;
			shape_ordinate[6][1]=y+1;
			shape_ordinate[7][0]=x+5;
			shape_ordinate[7][1]=y+1;
			}
			for(i=0;i<8;i++)
	        if(shape_ordinate[i][0]>=52)
	        temp=1;
	        if(temp==1){
	        dir_x-=2;
	        x-=2;
			for(i=0;i<8;i++)
	        shape_ordinate[i][0]-=2;
			}
			printf("%c%c%c%c",v,v);
			gotoxy(x+2,y+1);
			printf("%c%c%c%c",v,v);
			break;
		}
		break;
	}
   for(i=0;i<8;i++){
   	prev[i][0]=shape_ordinate[i][0];
   	prev[i][1]=shape_ordinate[i][1];
   }
}
void move(){
	gotoxy(7,21);
	printf("    %d",score);
	int i,j,k,temp=0;
	for(i=0;i<8;i++)
	if(ordinate[shape_ordinate[i][0]][shape_ordinate[i][1]+1]==1){
	for(k=0;k<8;k++)
	ordinate[shape_ordinate[k][0]][shape_ordinate[k][1]]=1;
	count=0;
	_shape_++;
	if(_shape_==7)
		_shape_=1;
		clean();
		if(dir_x>12)
		dir_x-=2;
		update();
		s_v=0;
	    check();
	    check();
	return;
	}
	for(i=0;i<30;i++){
	for(j=0;j<8;j++)
	if(b_o[i][0]==shape_ordinate[j][0]&&b_o[i][1]==shape_ordinate[j][1]){
		count=0;
		_shape_++;
		if(_shape_==7)
		_shape_=1;
		clean();
		for(k=0;k<8;k++)
	    ordinate[shape_ordinate[k][0]][shape_ordinate[k][1]]=1;
		if(dir_x>12)
		dir_x-=2;
		update();
		check();
		check();
		s_v=0;
		return;
    }
	}

	delay();
	for(i=0;i<8;i++){
		gotoxy(shape_ordinate[i][0],shape_ordinate[i][1]);
		printf(" ");
       }
       	shape_(34+dir_x,6+count,_shape_-1,s_v,1);
       count++;
       printf("");
}
void change_shape(){
	if(_shape_-1==0||_shape_-1==5){
		s_v++;
		if(s_v==4)
		s_v=0;
	}
	else if(_shape_-1==1||_shape_-1==2){
	s_v=0;
	}

	else if(_shape_-1==3||_shape_-1==4){
		s_v++;
		if(s_v==2)
		s_v=0;
	}
}
void input(){
int temp=0,i,k=0;
	if(kbhit()){
		switch(getch()){
			case 'w':for(i=0;i<8;i++)
	            if(ordinate[shape_ordinate[i][0]+1][shape_ordinate[i][1]]==1||
				ordinate[shape_ordinate[i][0]-1][shape_ordinate[i][1]]==1)
	            k=1;
	            if(k==0)
				change_shape();
				Beep(1700,500);
				break;
			case 'd':
				for(i=0;i<8;i++){
				if(shape_ordinate[i][0]>50)
				temp=1;
				}
			    if(temp==0){
			    for(i=0;i<8;i++)
	            if(ordinate[shape_ordinate[i][0]+1][shape_ordinate[i][1]]==1)
	            k=1;
	            if(k==0)
			    dir_x+=2;
				}
			    break;
			case 'a':if(dir_x>=-10){
			    for(i=0;i<8;i++)
	            if(ordinate[shape_ordinate[i][0]-1][shape_ordinate[i][1]]==1)
	            k=1;
	            if(k==0)
			    dir_x-=2;
			    }
			    break;
			case 's': speed=3;
				break;
			case 'x':
            Beep(1700,500);
			system("cls");exit(0);
			break;
			case 'n':
				for(temp=5;temp<31;temp++){
    	gotoxy(22,temp);
    	for(i=22;i<52;i++)
    	printf(" ");
	}
		score =0;
		Beep(1700,500);
		}
	}
}
void call()
{
	system("cls");
//system("COLOR F1");
	int i,j,k,count=0;
	//Beep(1700,500);
 printf("\n\t\t\tC PROGRAM TETRIS GAME\n");
     printf("\n\t\t________________________________________");

     printf("\n\t\t\t   WELCOME ");
     printf("\n\t\t\t      TO ");
     printf("\n\t\t\t   THE GAME ");
     printf("\n\t\t________________________________________");
     printf("\n\t\t________________________________________");
     printf("\n\n\t\t     THE BOSS TETRIS!!!!!!!!!!!    ") ;
     printf("\n\t\t   ===============================");
     printf("\n\n\t\t________________________________________\n");
     printf("\n\t\tDEVELOPED BY_:. KULPREET SINGH CHOPRA ");
     printf("\n\t\t\tSTUDENT OF ITM GOI");
     printf("\n\t\t________________________________________");
     printf("\n\n\t\tPRESS ANY KEY TO START THE TETRIS GAME.....");
     getch();
     system("cls");
     Beep(1700,500);
     printf("\n\t\t________________________________________");
     printf("\n\n\t\t   -----TETRIS GAME INSTRUCTIONS-----");
     printf("\n\t           ==================================");
     printf("\n\n\t\t_________________________________________\n");
printf("\n\n\n");
printf(" -> Here you will find different-different boxes that you have to arrange in line at bottom.\n -> If lines are drawn with the help of boxes then you will score and this line will be disappear and thus,like it is      game continues.\n -> Use following keys to move the boxes:\n\n                    1. Press 'w' to change size of the block.\n                    2. Press 'S' to go downward and continuously press it to increase speed in downward.\n                    3. Press 'A' to go left hand side.\n                    4. Press 'D' to go right hand side.\n                    \n -> Here you are provided with three lives.Your life decreases game restart .\n -> Press 'N' key to RESTART the new game.\n -> Press 'X' key to exit the game.\n -> Press any key to start the game......... ");
getch();
system("cls");
Beep(1700,500);
    border();
    constructor();
	while(1){
	input();
	if(_shape_==6)
	shape_(11,6,0,0,0);
	else
	shape_(11,6,_shape_,0,0);
	move();
	if(speed==3)
        speed=1;
	gotoxy(56,5);
	}

}
int width=30,height=30,food_x=15,food_y=15,x=20,y=21,flag=0,gameover=0,score1=0,tail_x[100],tail_y[100];
void delay1(){ int x;  for(x=0;x<10000000;x++);}
void gotoxy1(int x,int y){
	COORD c;
	c.X=x;c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void move1(){
	int i,prev_x=x,prev_y=y,prev1_x,prev1_y;
	for(i=0;i<score1/100;i++)	x==tail_x[i]&&y==tail_y[i]?gameover=1:1;
    for(i=0;i<score1/100;i++){
		prev1_x=tail_x[i]; prev1_y=tail_y[i];
		tail_x[i]=prev_x; tail_y[i]=prev_y;
		prev_x=prev1_x; prev_y=prev1_y;
	}
	switch(flag){
	   case 1: y>=3?y--:(gameover=1); break;
	   case 2: x<=28?x++:(gameover=1); break;
	   case 3: y<=28?y++:(gameover=1); break;
	   case 4: x>=3?x--:(gameover=1); break;
	}
}
void input1(){
	/* a=left side move
	   x=below side move
       s=right side move
       z=upper side move
    */
    if(kbhit()){
		switch(getch()){
			case 'a': flag=1; break;
			case 'x': flag=2; break;
			case 's': flag=3; break;
			case 'z': flag=4; break;
		}
	}
}
void border1(){
	if(x==food_x&&y==food_y){
		score+=100;
		name: food_x=rand()%height;
		if(food_x<=1) goto name;
		name1: food_y=rand()%width;
		if(food_y<=1) goto name1;
	}
	int i,j,k,temp=0;
	for(i=1;i<=width;i++){
		gotoxy1(7,i);
		for(j=1;j<=height;j++){
		if(i==1||j==1||j==height||i==width) printf("#");
		else{
			if(i==food_x&&j==food_y) printf("f");
			else if(i==x&&j==y) printf("O");
			else{
		    for(k=0;k<score1/100;k++) tail_x[k]==i&&tail_y[k]==j?printf("o"),temp=1:1;
		    temp==0?printf(" "):(temp=0);
			}
		  }
		}printf("\n");
	}
	gotoxy1(40,10); printf("Your Score is %d",score1);
}
void call2()
{
	system("COLOR FC");
 Beep(1700,500);
 printf("\t\t\tC PROGRAM  SNAKE GAME\n");
     printf("\n\t\t________________________________________");

     printf("\n\t\t\t   WELCOME ");
     printf("\n\t\t\t      TO ");
     printf("\n\t\t\t   THE GAME ");
     printf("\n\t\t________________________________________");
     printf("\n\t\t________________________________________");
     printf("\n\n\t\t   FOODI SNAKE!!!!!!!!!!!    ") ;
     printf("\n\t\t   ===================");
     printf("\n\n\t\t________________________________________\n");
     printf("\n\t\tDEVELOPED BY_:. JANHAVI SAHU");
     printf("\n\t\t\tSTUDENT OF ITM GOI");
     printf("\n\t\t________________________________________");
     printf("\n\n\t\tPRESS ANY KEY TO START THE SNAKE GAME.....");
     getch();
     system("cls");
     Beep(1700,500);
     printf("\n\t\t___________________________________________");
     printf("\n\n\t\t   -----SNAKE GAME INSTRUCTIONS-----");
     printf("\n\t\t   ==================================");
     printf("\n\n\t\t___________________________________________\n");
printf("\n\n");
printf(" ->You will be provided foods at the several coordinates of the screen which snake have to eat.\n Everytime snake eat a food the length of the snake will be increased by  one element and thus the score.\n -> Use following keys to move the snake:\n\n                    1. Press 'Z' to go upward\n                    2. Press 'X' to go downward\n                    3. Press 'A' to go left hand side\n                    4. Press 'S' to go right hand side\n                    5. Press 'ENTER' to exit the game.\n -> Here you are provided with three lives.Your life will decrease as you hit the wall or snake's body.\n -> Press any key to play the game.......... \n\n\n\t\t    ALL THE BEST!!!!");
getch();
system("cls");
Beep(1700,500);
while(!gameover)
{
border1();
input1();
move1();
}
Beep(1700,500);
system("cls");
}
void check(char,char);
char a[9] = {'1','2','3','4','5','6','7','8','9'};
void gameName()
{
printf("\n\t\t\t\tTic Tac Toe Game:\n");
}
void show()
{
printf("\n\n\t\t\t\tT---I---C---T\n");
printf("\t\t\t\t# %c # %c # %c #\n",a[0],a[1],a[2]);
printf("\t\t\t\tA---C---T---O\n");
printf("\t\t\t\t# %c # %c # %c #\n",a[3],a[4],a[5]);
printf("\t\t\t\tE---G---A---M\n");
printf("\t\t\t\t# %c # %c # %c #\n",a[6],a[7],a[8]);
printf("\t\t\t\tE---P---L---Y\n");
}
void inputSymbol()
{
printf("\nPlayer 1 Symbol :x:");
printf("\nPlayer 2 Symbol :0:\n");
}
void start()
{
char pa;
printf("\nStart The Game By Click Enter\n");
scanf("%c",&pa);
}
int count2=0;
void play()
{
char p,s;
printf("\nEnter position and symbol for the player:\n");
fflush(stdin);
scanf("%c",&p);
fflush(stdin);
scanf("%c",&s);
count2++;
system("cls");
check(p,s);
//system("cls");
}
void check(char P,char S)
{
int i;
for(i=0; i<=8; i++)
{
if(a[i]==P)
{
a[i]=S;
}
}
}
int end()
{
if ((a[0]=='x'&&a[1]=='x'&&a[2]=='x') || (a[0]=='x'&&a[3]=='x'&&a[6]=='x') || (a[0]=='x'&&a[4]=='x'&&a[8]=='x'))
return(100);
else
if ((a[0]=='0'&&a[1]=='0'&&a[2]=='0') || (a[0]=='0'&&a[3]=='0'&&a[6]=='0') || (a[0]=='0'&&a[4]=='0'&&a[8]=='0'))
return(200);
else
if(a[1]=='x'&&a[4]=='x'&&a[7]=='x')
return(100);
else
if(a[1]=='0'&&a[4]=='0'&&a[7]=='0')
return(200);
else
if(a[2]=='x'&&a[5]=='x'&&a[8]=='x')
return(100);
else
if(a[2]=='0'&&a[5]=='0'&&a[8]=='0')
return(200);
else
if(a[3]=='x'&&a[4]=='x'&&a[5]=='x')
return(100);
else
if(a[3]=='0'&&a[4]=='0'&&a[5]=='0')
return(200);
else
if(a[2]=='x'&&a[4]=='x'&&a[6]=='x')
return(100);
else
if(a[2]=='0'&&a[4]=='0'&&a[6]=='0')
return(200);
else
if(a[6]=='x'&&a[7]=='x'&&a[8]=='x')
return(100);
else
if(a[6]=='0'&&a[7]=='0'&&a[8]=='0')
return(200);
return(300);
}
void call4()
{
	system("COLOR F2");
int k;
char ch;
     Beep(1700,500);
     printf("\n\t\t    C PROGRAM TIC TAC TOE GAME\n");
     printf("\n\t\t________________________________________");

     printf("\n\t\t\t   WELCOME ");
     printf("\n\t\t\t      TO ");
     printf("\n\t\t\t   THE GAME ");
     printf("\n\t\t________________________________________");
     printf("\n\t\t________________________________________");
     printf("\n\n\t\t       ZERO V/S CROSS!!!!!!!!!!!    ") ;
     printf("\n\t\t   ===============================");
     printf("\n\n\t\t________________________________________\n");
     printf("\n\t\tDEVELOPED BY_:. KAPIL AGRAWAL");
     printf("\n\t\t\tSTUDENT OF ITM GOI");
     printf("\n\t\t________________________________________");
     printf("\n\n\t\tPRESS ANY KEY TO START THE QUIZE GAME.....");
     getch();
     system("cls");
     Beep(1700,500);
     printf("\n\t\t________________________________________");
     printf("\n\n\t\t     TIC TAC TOE GAME INSTRUCTIONS");
     printf("\n\t\t     ==============================");
     printf("\n\n\t\t_________________________________________\n");
     printf("\n\t\t > Press S to start the game");
     printf("\n\t\t > Press V to view the highest score  ");
     printf("\n\t\t > Press R to reset score");
     getch();
     system("cls");
     Beep(1700,500);
labell:

gameName();
show();
inputSymbol();
start();
play();
label:

show();
play();
k=end();

show();
if(count<9)
{
if(k==100)
{
printf("\nPlayer 1 won the game:");
Beep(1700,500);
count=0;
}
else
if(k==200)
{
printf("\nPlayer 2 won the game:");
Beep(1700,500);
count=0;
}
else
goto label;
}
else
{
printf("\nGame Draw:");
Beep(1700,500);
count=0;
}
printf("\nDo u want play continue: Enter y for YES and n for NO:");
fflush(stdin);
scanf("%c",&ch);
Beep(1700,500);
if(ch=='y' ||ch=='Y')
{
a[0]='1';
a[1]='2';
a[2]='3';
a[3]='4';
a[4]='5';
a[5]='6';
a[6]='7';
a[7]='8';
a[8]='9';
goto labell;
}
Beep(1700,500);
system("cls");
getch();
}
void show_record();
void reset_score();
void help();
void edit_score(float , char []);
void show_record()
    {system("cls");
	char name[20];
	float scr;
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%f",&name,&scr);
	printf("\n\n\t\t*************************************************************");
	printf("\n\n\t\t %s has secured the Highest Score %0.2f",name,scr);
	printf("\n\n\t\t*************************************************************");
	fclose(f);
	getch();}

void reset_score()
    {system("cls");
    float sc;
	char nm[20];
	FILE *f;
	f=fopen("score.txt","r+");
	fscanf(f,"%s%f",&nm,&sc);
	sc=0;
	fprintf(f,"%s,%.2f",nm,sc);
    fclose(f);}

void help()
	{system("cls");
    printf("\n\n                              HELP");
    printf("\n -------------------------------------------------------------------------");
    printf("\n ......................... C program Quiz Game...........");
    printf("\n >> There are two rounds in the game, WARMUP ROUND & CHALLANGE ROUND");
    printf("\n >> In warmup round you will be asked a total of 3 questions to test your general");
    printf("\n    knowledge. You will be eligible to play the game if you can give atleast 2");
    printf("\n    right answers otherwise you can't play the Game...........");
    printf("\n >> Your game starts with the CHALLANGE ROUND. In this round you will be asked");
    printf("\n    total 10 questions each right answer will be awarded $100,000.");
    printf("\n    By this way you can win upto ONE MILLION cash prize in USD...............");
    printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
    printf("\n    right option");
    printf("\n >> You will be asked questions continuously if you keep giving the right answers.");
    printf("\n >> No negative marking for wrong answers");

	printf("\n\n\t*********************BEST OF LUCK*********************************");
	printf("\n\n\t*****C PROGRAM QUIZ GAME is developed by CONSOLE GAMMING IN C AND C++********");}

void edit_score(float score, char plnm[20])
	{system("cls");
	float sc;
	char nm[20];
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%f",&nm,&sc);
	if (score>=sc)
	  { sc=score;
	    fclose(f);
	    f=fopen("score.txt","w");
	    fprintf(f,"%s\n%.2f",plnm,sc);
	    fclose(f);}}
void call3()
{
	system("COLOR F5");
     int countr,r,r1,count,i,n;
     float score;
     char choice;
     char playername[20];
     mainhome:
     Beep(1700,500);
     system("cls");
     printf("\n\t\t\tC PROGRAM QUIZ GAME\n");
     printf("\n\t\t________________________________________");

     printf("\n\t\t\t   WELCOME ");
     printf("\n\t\t\t      TO ");
     printf("\n\t\t\t   THE GAME ");
     printf("\n\t\t________________________________________");
     printf("\n\t\t________________________________________");
     printf("\n\n\t\t   BECOME A MILLIONAIRE!!!!!!!!!!!    ") ;
     printf("\n\t\t   ===============================");
     printf("\n\n\t\t________________________________________\n");
     printf("\n\t\tDEVELOPED BY_:. KANISHKA VERMA");
     printf("\n\t\t\tSTUDENT OF ITM GOI");
     printf("\n\t\t________________________________________");
     printf("\n\n\t\tPRESS ANY KEY TO START THE QUIZE GAME.....");
     getch();
     system("cls");
     Beep(1700,500);
     printf("\n\t\t________________________________________");
     printf("\n\n\t\t\tQUIZE GAME INSTRUCTIONS");
     printf("\n\t\t       ========================");
     printf("\n\n\t\t_________________________________________\n");
     printf("\n\t\t > Press S to start the game");
     printf("\n\t\t > Press V to view the highest score  ");
     printf("\n\t\t > Press R to reset score");
     printf("\n\t\t > press H for help            ");
     printf("\n\t\t > press Q to quit             ");
     printf("\n\t\t________________________________________\n\n");
     Beep(1700,500);
     choice=toupper(getch());
     if (choice=='V')
	{
	show_record();
	goto mainhome;
	}
     else if (choice=='H')
	{
	help();getch();
	goto mainhome;
	}
	else if (choice=='R')
	{reset_score();
	getch();
	goto mainhome;}
	else if (choice=='Q')
	exit(1);
    else if(choice=='S')
    {
     system("cls");
     Beep(1700,500);
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\tResister your name:");
     gets(playername);

    system("cls");
    Beep(1700,500);
    printf("\n ------------------  Welcome %s to C Program Quiz Game --------------------------",playername);
    printf("\n\n Here are some tips you might wanna know before playing:");
    printf("\n -------------------------------------------------------------------------");
    printf("\n >> There are 2 rounds in this Quiz Game,WARMUP ROUND & CHALLANGE ROUND");
    printf("\n >> In warmup round you will be asked a total of 3 questions to test your");
    printf("\n    general knowledge. You are eligible to play the game if you give atleast 2");
    printf("\n    right answers, otherwise you can't proceed further to the Challenge Round.");
    printf("\n >> Your game starts with CHALLANGE ROUND. In this round you will be asked a");
    printf("\n    total of 10 questions. Each right answer will be awarded $100,000!");
    printf("\n    By this way you can win upto ONE MILLION cash prize!!!!!..........");
    printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
    printf("\n    right option.");
    printf("\n >> You will be asked questions continuously, till right answers are given");
    printf("\n >> No negative marking for wrong answers!");
    printf("\n\n\t!!!!!!!!!!!!! ALL THE BEST !!!!!!!!!!!!!");
    printf("\n\n\n Press Y  to start the game!\n");
    printf("\n Press any other key to return to the main menu!");
    if (toupper(getch())=='Y')
		{
		    goto home;
        }
	else
		{
        goto mainhome;
       system("cls");
       }

     home:
     system("cls");
     count=0;
     for(i=1;i<=3;i++)
     {
    system("cls");
     r1=i;


     switch(r1)
		{
		case 1:
		printf("\n\nWhich of the following is a Palindrome number?");
		printf("\n\nA.42042\t\tB.101010\n\nC.23232\t\tD.01234");
		if (toupper(getch())=='C')
			{
			    printf("\n\nCorrect!!!");count++;
			    getch();
			    break;
}
		else
		       {
		           printf("\n\nWrong!!! The correct answer is C.23232");
		           getch();
		       break;
		       }

        case 2:
		printf("\n\n\nThe country with the highest environmental performance index is...");
		printf("\n\nA.France\t\tB.Denmark\n\nC.Switzerland\t\tD.Finland");
		if (toupper(getch())=='C')
			{printf("\n\nCorrect!!!");count++;
			getch();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is C.Switzerland");
		       getch();
		       break;}

        case 3:
		printf("\n\n\nWhich animal laughs like human being?");
		printf("\n\nA.Polar Bear\t\tB.Hyena\n\nC.Donkey\t\tD.Chimpanzee");
		if (toupper(getch())=='B')
			{printf("\n\nCorrect!!!");count++;
			getch();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is B.Hyena");
		       getch();
		       break;}

        case 4:
		printf("\n\n\nWho was awarded the youngest player award in Fifa World Cup 2006?");
		printf("\n\nA.Wayne Rooney\t\tB.Lucas Podolski\n\nC.Lionel Messi\t\tD.Christiano Ronaldo");
		if (toupper(getch())=='B')
			{printf("\n\nCorrect!!!");count++;
			getch();
			 break;}
		else
		       {printf("\n\nWrong!!! The correct answer is B.Lucas Podolski");
		       getch();
		       break;}

        case 5:
        printf("\n\n\nWhich is the third highest mountain in the world?");
        printf("\n\nA.Mt. K2\t\tB.Mt. Kanchanjungha\n\nC.Mt. Makalu\t\tD.Mt. Kilimanjaro");
        if (toupper(getch())=='B')
               {printf("\n\nCorrect!!!");count++;
               getch();
                break;}
        else
		       {printf("\n\nWrong!!! The correct answer is B.Mt. Kanchanjungha");
		       getch();
		       break;}

        case 6:
		printf("\n\n\nWhat is the group of frogs known as?");
		printf("\n\nA.A traffic\t\tB.A toddler\n\nC.A police\t\tD.An Army");
		if (toupper(getch())=='D' )
			{printf("\n\nCorrect!!!");count++;
			getch();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is D.An Army");
		       getch();
		       break;}}
		       }

	if(count>=2)
	{goto test;}
	else
	{
	system("cls");
	printf("\n\nSORRY YOU ARE NOT ELIGIBLE TO PLAY THIS GAME, BETTER LUCK NEXT TIME");
	getch();
	goto mainhome;
	}
     test:
     system("cls");
     printf("\n\n\t*** CONGRATULATION %s you are eligible to play the Game ***",playername);
     printf("\n\n\n\n\t!Press any key to Start the Game!");
     if(toupper(getch())=='p')
		{goto game;}
game:
     countr=0;
     for(i=1;i<=10;i++)
     {system("cls");
     r=i;

     switch(r)
		{
		case 1:
		printf("\n\nWhat is the National Game of England?");
		printf("\n\nA.Football\t\tB.Basketball\n\nC.Cricket\t\tD.Baseball");
		if (toupper(getch())=='C')
			{printf("\n\nCorrect!!!");countr++;getch();
			 break;getch();}
		else
		       {printf("\n\nWrong!!! The correct answer is C.Cricket");getch();
		       goto score;
		       break;}

		case 2:
		printf("\n\n\nStudy of Earthquake is called............,");
		printf("\n\nA.Seismology\t\tB.Cosmology\n\nC.Orology\t\tD.Etimology");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!!!");countr++;getch();
			 break;}
		else
		       {printf("\n\nWrong!!! The correct answer is A.Seismology");getch();
		      goto score;
		       break;
		       }

        case 3:
		printf("\n\n\nAmong the top 10 highest peaks in the world, how many lie in Nepal? ");
		printf("\n\nA.6\t\tB.7\n\nC.8\t\tD.9");
		if (toupper(getch())=='C')
			{printf("\n\nCorrect!!!");countr++;getch();
			 break;}
		else
		       {printf("\n\nWrong!!! The correct answer is C.8");getch();
		       goto score;
		       break;}

        case 4:
		printf("\n\n\nThe Laws of Electromagnetic Induction were given by?");
		printf("\n\nA.Faraday\t\tB.Tesla\n\nC.Maxwell\t\tD.Coulomb");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!!!");countr++;getch();
			 break;}
		else
		       {
                printf("\n\nWrong!!! The correct answer is A.Faraday");getch();
		       goto score;
		       break;
		       }

        case 5:
		printf("\n\n\nIn what unit is electric power measured?");
		printf("\n\nA.Coulomb\t\tB.Watt\n\nC.Power\t\tD.Units");
		if (toupper(getch())=='B')
			{printf("\n\nCorrect!!!");countr++;getch(); break;}
		else
		       {
		           printf("\n\nWrong!!! The correct answer is B.Power");
		       getch();
		       goto score;
		       break;
		       }

		case 6:
		printf("\n\n\nWhich element is found in Vitamin B12?");
		printf("\n\nA.Zinc\t\tB.Cobalt\n\nC.Calcium\t\tD.Iron");
		if (toupper(getch())=='B' )
			{printf("\n\nCorrect!!!");countr++;getch();
			 break;}
		else
		       {printf("\n\nWrong!!! The correct answer is B.Cobalt");goto score;
		       getch();
		       break;}

        case 7:
		printf("\n\n\nWhat is the National Name of Japan?");
		printf("\n\nA.Polska\t\tB.Hellas\n\nC.Drukyul\t\tD.Nippon");
		if (toupper(getch())=='D')
			{printf("\n\nCorrect!!!");countr++;getch();
			 break;}
		else
		       {printf("\n\nWrong!!! The correct answer is D.Nippon");getch();
		       goto score;
		       break;}

        case 8:
		printf("\n\n\nHow many times a piece of paper can be folded at the most?");
		printf("\n\nA.6\t\tB.7\n\nC.8\t\tD.Depends on the size of paper");
		if (toupper(getch())=='B')
			{printf("\n\nCorrect!!!");countr++;getch(); break;}
		else
		       {printf("\n\nWrong!!! The correct answer is B.7");getch();
		       goto score;
		       break;}

        case 9:
		printf("\n\n\nWhat is the capital of Denmark?");
		printf("\n\nA.Copenhagen\t\tB.Helsinki\n\nC.Ajax\t\tD.Galatasaray");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!!!");countr++; getch();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is A.Copenhagen");getch();
		       goto score;
		       break;}

        case 10:
		printf("\n\n\nWhich is the longest River in the world?");
		printf("\n\nA.Nile\t\tB.Koshi\n\nC.Ganga\t\tD.Amazon");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!!!");countr++;getch(); break;}
		else
		       {printf("\n\nWrong!!! The correct answer is A.Nile");getch();break;goto score;}

        case 11:
		printf("\n\n\nWhat is the color of the Black Box in aeroplanes?");
		printf("\n\nA.White\t\tB.Black\n\nC.Orange\t\tD.Red");
		if (toupper(getch())=='C')
			{printf("\n\nCorrect!!!");countr++;getch();
			 break;}
		else
              {printf("\n\nWrong!!! The correct answer is C.Orange");getch();
              break;goto score;}

        case 12:
		printf("\n\n\nWhich city is known at 'The City of Seven Hills'?");
		printf("\n\nA.Rome\t\tB.Vactican City\n\nC.Madrid\t\tD.Berlin");
		if (toupper(getch())=='A')
			  {printf("\n\nCorrect!!!");countr++;getch();
			   break;}
		else
              {printf("\n\nWrong!!! The correct answer is A.Rome");getch();
              break;goto score;}

		case 13:
		printf("\n\n\nName the country where there no mosquitoes are found?");
		printf("\n\nA.Japan\t\tB.Italy\n\nC.Argentina\t\tD.France");
		if (toupper(getch())=='D')
			{printf("\n\nCorrect!!!");countr++;getch();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is D.France");getch();
		       break;goto score;}

        case 14:
		printf("\n\n\nWho is the author of 'Pulpasa Cafe'?");
		printf("\n\nA.Narayan Wagle\t\tB.Lal Gopal Subedi\n\nC.B.P. Koirala\t\tD.Khagendra Sangraula");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!!!");countr++;getch();
			 break;}
		else
		       {printf("\n\nWrong!!! The correct answer is A.Narayan Wagle");getch();
		       break;goto score;}

		case 15:
		printf("\n\n\nWhich Blood Group is known as the Universal Recipient?");
		printf("\n\nA.A\t\tB.AB\n\nC.B\t\tD.O");
		if (toupper(getch())=='B')
			{printf("\n\nCorrect!!!");countr++;getch();
			 break;}
		else
		       {printf("\n\nWrong!!! The correct answer is B.AB");getch();
		       goto score;
		       break;}

		case 16:
		printf("\n\n\nWhat is the unit of measurement of distance between Stars?");
		printf("\n\nA.Light Year\t\tB.Coulomb\n\nC.Nautical Mile\t\tD.Kilometer");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!!!");countr++; getch();
			break;
			}
		else
		       {printf("\n\nWrong!!! The correct answer is A.Light Year");getch();
		       goto score;
		       break;}


		case 17:
		printf("\n\n\nThe country famous for Samba Dance is........");
		printf("\n\nA.Brazil\t\tB.Venezuela\n\nC.Nigeria\t\tD.Bolivia");
		if (toupper(getch())=='A')
			{printf("\n\nCorrect!!!");countr++; getch();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is A.Brazil");getch();goto score;
		       break;}

		case 18:
		printf("\n\n\nWind speed is measure by__________?");
		printf("\n\nA.Lysimeter\t\tB.Air vane\n\nC.Hydrometer\t\tD.Anemometer\n\n");
		if (toupper(getch())=='D')
			{printf("\n\nCorrect!!!");countr++; getch();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is D.Anemometer");getch();goto score;
		       break;}

		case 19:
		printf("\n\n\nWhich city in the world is popularly known as The City of Temple?");
		printf("\n\nA.Delhi\tB.Bhaktapur\n\nC.Kathmandu\tD.Agra\n\n");
		if (toupper(getch())=='C')
			{printf("\n\nCorrect!!!");countr++; getch();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is C.Kathmandu");getch();goto score;
		       break;}

		case 20:
		printf("\n\n\nWhich hardware was used in the First Generation Computer?");
		printf("\n\nA.Transistor\t\tB.Valves\n\nC.I.C\t\tD.S.S.I");
		if (toupper(getch())=='B')
			{printf("\n\nCorrect!!!");countr++; getch();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is B.Valves");getch();goto score;
		       break;}

		case 21:
		printf("\n\n\nOzone plate is being destroyed regularly because of____ ?");
		printf("\n\nA.L.P.G\t\tB.Nitrogen\n\nC.Methane\t\tD. C.F.C");
		if (toupper(getch())=='D')
			{printf("\n\nCorrect!!!");countr++; getch();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is D. C.F.C");getch();goto score;
		       break;}

		case 22:
		printf("\n\n\nWho won the Women's Australian Open Tennis in 2007?");
		printf("\n\nA.Martina Hingis\t\tB.Maria Sarapova\n\nC.Kim Clijster\t\tD.Serena Williams");
		if (toupper(getch())=='D')
			{printf("\n\nCorrect!!!");countr++; getch();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is D.Serena Williams");getch();goto score;
		       break;}

		case 23:
		printf("\n\n\nWhich film was awarded the Best Motion Picture at Oscar in 2010?");
		printf("\n\nA.The Secret in their Eyes\t\tB.Shutter Island\n\nC.The King's Speech\t\tD.The Reader");
		if (toupper(getch())=='C')
			{printf("\n\nCorrect!!!");countr++; getch();
			break;}
		else
		       {printf("\n\nWrong!!! The correct answer is C.The King's Speech");getch();goto score;
		       break;}}}
	score:
    system("cls");
	score=(float)countr*100000;
	if(score>0.00 && score<1000000)
	{
	   printf("\n\n\t\t**************** CONGRATULATION *****************");
	     printf("\n\t You won $%.2f",score);goto go;}

	 else if(score==1000000.00)
	{
	    printf("\n\n\n \t\t**************** CONGRATULATION ****************");
	    printf("\n\t\t\t\t YOU ARE A MILLIONAIRE!!!!!!!!!");
	    printf("\n\t\t You won $%.2f",score);
	    printf("\t\t Thank You!!");
	}
	 else
{
	 printf("\n\n\t******** SORRY YOU DIDN'T WIN ANY CASH ********");
	    printf("\n\t\t Thanks for your participation");
	    printf("\n\t\t TRY AGAIN");goto go;}

	go:
	puts("\n\n Press Y if you want to play next game");
	puts(" Press any key if you want to go main menu");
	if (toupper(getch())=='Y')
		goto home;
	else
		{
		edit_score(score,playername);
		goto mainhome;}}
}
int main(){
	Beep(1700,500);
         int c;
     system("cls");
     system("COLOR F3");
     printf("\n\t\tINSTITUTE OF TECHNOLOGY AND MANAGMENT GWALIOR(MP)\n\t\t\t        PBL PROJECT\n\t\t__________________________________________________\n\t\t\t     WELCOME\n\t\t\t       TO\n\t\t\t   THE GAME ZONE\n\t\t__________________________________________________\n\t\t__________________________________________________\n\n\t\t      CONSOLE GAMMING IN C AND C++\n\t\t   ====================================\n\n\t\t_________________________________________________\n\n\t\tDEVELOPED BY_:. KULPREET SINGH CHOPRA\n\t\t\t\tJANHAVI SAHU\n\t\t\t\tKANISHK VERMA\n\t\t\t\tKAPIL AGRAWAL\n\t\t\tSTUDENTS OF COMPUTER SCIENCE DEPARTMENT\n\t\t__________________________________________________\n\n\t\tCHOOSE BELOW GIVEN OPTIONS TO START THE QUIZE GAME.....\n\t\t__________________________________________________\n\n\t\t\t1.TETRIS THE BOS\n\t\t\t2.FOODY SNAKE\n\t\t\t3.WHO BECOME A MILLINOR\n\t\t\t4.TIC TAC TOE\n\n\t\t CHOOSE OPTION NUMBER\n\t\t\t");
     cin>>c;
     printf("\n\t\t_________________________________________\n");
     Beep(1700,500);
     switch(c)
     {
     	case 1:
     		call();
     		break;
     	case 2:
     		call2();
     		break;
     	case 3:
     		call3();
     		break;
     	case 4:
     		call4();
     		break;
	 }
     return 0;
getch();
}
