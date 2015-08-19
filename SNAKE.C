#include<conio.h>
#include<stdio.h>
#include<stdlib.h>


#define print printf("%c",254)
int len=5 ;
void snake(){
	int x=10,y=12,i=0,j=0,a,flag=1,score=0;
	int xx[100],yy[100],k=0,x_food,y_food,c,lc;
	char ch='d',old_ch='q';
	for(c=0;c<100;c++){     //reseting the arrays
		xx[c]=0;
		yy[c]=0;
	}


	while(ch!='0'){
		 if(flag==1){                 //generating food
			randomize();
			x_food=random(60); if(x_food<=9)x_food=10;
			randomize();
			y_food=random(20); if(y_food<=4)y_food=5;

			for(c=k,lc=0;lc<=len;c--,lc++){    //avoid when food is
							    //generated on the snake body
				if(c<0)c=99;
				if(xx[c]==x_food && yy[c]==y_food){
					 x_food++;
					 if(x_food<=9)x_food=10;
					 y_food++;
					 if(y_food<=4)y_food=5;
					c=k+1;lc=-1;
				}
				//else if(lc>len)break;
			}

			gotoxy(x_food,y_food);
			printf("%c",15);
			flag=0;

		 }

		  a=kbhit();
		  if(a!=0){
			ch=getch();
		  }
		  if(ch=='d' && old_ch=='a')ch=old_ch;
		  if(ch=='a' && old_ch=='d')ch=old_ch;
		  if(ch=='w' && old_ch=='s')ch=old_ch;
		  if(ch=='s' && old_ch=='w')ch=old_ch;

		  if(ch!='a' && ch!='w' && ch!='s' && ch!='f' && ch!='d'&& ch!='0')
		  ch='f';

		  if(ch!='a' && ch!='w' && ch!='s' && ch!='f'){     //right...d
			xx[k]=x;yy[k]=y;k++;

			gotoxy(x,y);
			print;
			if(x==x_food && y==y_food) flag=1;
			x++;
			if(x>=61)x=10;
		  }
		  if(ch!='a' && ch!='w' && ch!='d' && ch!='f'){   //down s

			xx[k]=x;yy[k]=y;k++;

			gotoxy(x,y);
			print;
			if(x==x_food && y==y_food) flag=1;
			y++;
			if(y>=21)y=5;
		  }
		  if(ch!='d' && ch!='w' && ch!='s' && ch!='f'){  //left a


			xx[k]=x;yy[k]=y;k++;
			gotoxy(x,y);
			print;
			if(x==x_food && y==y_food) flag=1;
			x--;
			if(x<=9)x=60;
		  }
		  if(ch!='a' && ch!='d' && ch!='s' && ch!='f'){  //up w

			xx[k]=x;yy[k]=y;k++;

			gotoxy(x,y);
			print;
			if(x==x_food && y==y_food) flag=1;

			y--;
			if(y<=4)y=20;
		  }

		  if(flag==1){
			len=len+1;
			score=score+5;
			gotoxy(65,5);
			printf("SCORE : %d",score);
		  }

		  if(j>=len && ch!='f'){        //erasing tail of snake

			gotoxy(xx[i],yy[i]);i++;
			putch(' ');
			if(i==100)i=0;

		  }



		  for(c=k-3,lc=0;lc<=len-3;c--,lc++){    //dead condition
				if(c<0)c=99;
				if(xx[c]==xx[k-1] && yy[c]==yy[k-1]){
					gotoxy(40,12);
					printf("game over");
					getch();
					exit(0);
				}
		  }

		  if(j<len)j++;

		  if(k==100)k=0; //resetting array
		  old_ch=ch;    //holding previous key stroke

		  delay(100);  //speed of snake
	}
}

void c_window(){           //creating thw window
	int a,b;
	for(a=9;a<=61;a++){
		gotoxy(a,4);
		printf("%c",219);
		gotoxy(a,21);
		printf("%c",219);
	}
	for(a=4;a<=21;a++){
		gotoxy(9,a);
		printf("%c",219);
		gotoxy(61,a);
		printf("%c",219);
	}
}



void main(){
	clrscr();
	c_window();
	snake();
}