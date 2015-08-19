void c_window();

void snake(int level){

	int x=10,y=12,i=0,j=0,a,flag=1,bf_flag=1,score=0,food_timer,food_timer_ini;
	int xx[100],yy[100],k=0,x_food,y_food,c,lc,food_count=0;
	int len=5,speed,target=0,l_flag=1;
	int divy[]={5,9,13,17,19,15};
	int divx[]={15,25,35,45,55,40};
	char ch=77,old_ch=65,chr=80,ch2;

	for(c=0;c<100;c++){     //reseting the arrays
		xx[c]=0;
		yy[c]=0;
	}


	if(level==1)	{speed=180;food_timer_ini=30;}
	if(level==2)	{speed=140;food_timer_ini=32;}
	if(level==3)	{speed=110;food_timer_ini=34;}
	if(level==4)	{speed=80;food_timer_ini=35;}
	if(level==5)	{speed=65;food_timer_ini=38;}
	if(level==6)	{speed=50;food_timer_ini=42;}
	if(level==7)	{speed=45;food_timer_ini=44;}
	if(level==8)	{speed=35;food_timer_ini=48;}
	if(level==9)	{speed=30;food_timer_ini=50;}

	food_timer=food_timer_ini;

	textcolor(GREEN);
	gotoxy(65,5);
	cprintf("SCORE : %d",score);
	gotoxy(65,7);
	cprintf("LEVEL : %d",level);
	gotoxy(65,21);
	textcolor(RED);
	cprintf("S N A K E");

	gotoxy(58,25);
	textcolor(CYAN);
	cprintf("dev.achieve@gmail.com");


	gotoxy(25,14);
	textcolor(BLUE);
	cprintf("SET YOUR TARGET :-----> ");
	gotoxy(25,16);
	textcolor(CYAN);
	//cprintf("PRESS w TO INCR s TO DECR");

	gotoxy(65,14);
	textcolor(BLUE);
	cprintf("TARGET : ");

	while(1){
		gotoxy(74,14);
		textcolor(GREEN);
		cprintf("%d      ",target);
		ch2=getch();
		if(ch2==13)break;
		else if(ch2==72){
			target=target+50;
			if(target>=32750)target=32750;
		}
		else if(ch2==80){
			target=target-25;
			if(target<0)target=0;
		}

	}
	gotoxy(25,14); printf("\t\t\t\t");
	gotoxy(25,16); printf("\t\t\t\t");


	while(ch!=27){
		 if(flag==1){                 //generating food
			randomize();
			x_food=random(125); //if(x_food<=9)x_food=10;
			randomize();
			y_food=random(119); //if(y_food<=4)y_food=5;

			x_food=(x_food*y_food)%20;if(x_food<=9)x_food=divx[food_count];
			y_food=((x_food+y_food)*7)%20;if(y_food<=4)y_food=divy[5-food_count];
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
			}

			gotoxy(x_food,y_food);


			textcolor(GREEN);    //small food generated always
			cprintf("%c",1);

			if(food_count==5){

				/*x_food=random(125); //if(x_food<=9)x_food=10;
				randomize();
				y_food=random(119); //if(y_food<=4)y_food=5;

				x_food=(x_food*y_food)%20;if(x_food<=9)x_food=divx[food_count];
				y_food=((x_food+y_food)*7)%20;if(y_food<=4)y_food=divy[5-food_count];
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
				} */
				gotoxy(x_food,y_food);

				textcolor(CYAN);
				cprintf("%c",176);
				food_count=0;
				bf_flag=0;
				gotoxy(4,23);
				printf("TIMER:");
				for(c=food_timer+10;c>=10;c--){
					gotoxy(c,23);
					printf("%c",222);
				}

			}
			else if(len%12==0){
				gotoxy(x_food,y_food);
				textcolor(YELLOW);
				cprintf("%c",171);
				//food_count=0;
				l_flag=0;
				gotoxy(4,23);
				printf("TIMER:");
				for(c=food_timer+10;c>=10;c--){
					gotoxy(c,23);
					printf("%c",222);
				}
			}

			flag=0;  //0 indicates food has been generated

		 }

		  a=kbhit();
		  if(a!=0){
			ch=getch();
			ch=getch();

		  if(ch==77 && old_ch==75)ch=old_ch;
		  if(ch==75 && old_ch==77)ch=old_ch;
		  if(ch==72 && old_ch==80)ch=old_ch;
		  if(ch==80 && old_ch==72)ch=old_ch;}

		  //printf("%c=%d,%c=%d ",old_ch,old_ch,ch,ch);

		 if(ch!=75 && ch!=72 && ch!=80 && ch!='f' && ch!=77 && ch!=27){
		 // if(ch=='f')
		  ch='f';while(1){ch=getch();if(ch=='f' || ch==13){ch=old_ch;break;}}}

		  textcolor(BLUE);      //snake color

		  //if(ch!=75 && ch!=72 && ch!=80 && ch!='f'){     //right...d
		  if(ch==77){
			xx[k]=x;yy[k]=y;k++;

			gotoxy(x,y);
			print;
			if(x==x_food && y==y_food) flag=1;
			x++;
			if(x>=61)x=10;
		  }
		 // if(ch!=75 && ch!=72 && ch!=77 && ch!='f'){   //down s
		  if(ch==80){

			xx[k]=x;yy[k]=y;k++;

			gotoxy(x,y);
			print;
			if(x==x_food && y==y_food) flag=1;
			y++;
			if(y>=21)y=5;
		  }
		  //if(ch!=77 && ch!=72 && ch!=80 && ch!='f'){  //left a
		  if(ch==75){


			xx[k]=x;yy[k]=y;k++;
			gotoxy(x,y);
			print;
			if(x==x_food && y==y_food) flag=1;
			x--;
			if(x<=9)x=60;
		  }
		  //if(ch!=75 && ch!=77 && ch!=80 && ch!='f'){  //up w
		  if(ch==72){

			xx[k]=x;yy[k]=y;k++;

			gotoxy(x,y);
			print;
			if(x==x_food && y==y_food) flag=1;

			y--;
			if(y<=4)y=20;
		  }

		  if(flag==1){
			len=len+1;
			score=score+level;
			if(bf_flag==0){         //big food eaten then what hpn
				score=score+(food_timer*10);
				gotoxy(65,10);
				printf("                 ");
				gotoxy(65,10);

				cprintf("SCORE +%d/%d",food_timer*10,food_timer_ini*10);
				bf_flag=1; food_timer=food_timer_ini;
				for(c=4;c<=60;c++){
					gotoxy(c,23);
					printf(" ");
				}



			}

			if(l_flag==0){
				len=len/2+1;
				l_flag=1;food_timer=food_timer_ini;
				for(c=4;c<=60;c++){
					gotoxy(c,23);
					printf(" ");
				}
				gotoxy(65,10);
				printf("              ");
				gotoxy(65,10);
				cprintf("LENGTH HALVED");

				food_count--; //food_count not incr when len_food eaten

				while(j>len){                      //erasing tail of snake
					gotoxy(xx[i],yy[i]);       //when length is 1/2
					putch(' ');  i++;
					if(i==100)i=0;
					j--;

				}
			}


			textcolor(GREEN);
			gotoxy(65,5);
			cprintf("SCORE : %d",score);
			food_count++;
		  }
		  if(flag==0 && bf_flag==0){
			food_timer--;
			gotoxy(food_timer+10,23);
			printf("%c",176);
			if(food_timer==0){
				flag=1;bf_flag=1;
				food_timer=food_timer_ini;

				gotoxy(x_food,y_food);putch(' '); //erasing food
				for(c=4;c<=60;c++){
					gotoxy(c,23);
					printf(" ");    //ersing timer
				}
			}
		  }

		  if(flag==0 && l_flag==0){
			food_timer--;
			gotoxy(food_timer+10,23);  //erasing timer unit step
			printf("%c",176);
			if(food_timer==0){
				flag=1;l_flag=1;
				food_timer=food_timer_ini;
				len=len+1;
				gotoxy(x_food,y_food);putch(' '); //erasing food
				for(c=4;c<=60;c++){
					gotoxy(c,23);
					printf(" ");    //ersing timer
				}
			}
		  }




		  if(j>=len && ch!='f'){        //erasing tail of snake

			gotoxy(xx[i],yy[i]);i++;
			//textcolor(BLACK);
			putch(' ');    gotoxy(80,25);
			if(i==100)i=0;

		  }



		  for(c=k-3,lc=0;lc<=len-3;c--,lc++){    //dead condition
				if(c<0)c=99;
				if(xx[c]==xx[k-1] && yy[c]==yy[k-1]){
					gotoxy(40,12);
					textcolor(YELLOW);
					cprintf("GAME OVER");
					gotoxy(37,14);
					cprintf("YOUR SCORE : %d",score);
					if(score>=target){

						randomize();
						while(ch!=27){
							x=random(60);if(x<10)x=10;
							y=random(20);if(y<5)x=5;
							gotoxy(x,y);
							textcolor(x+y);
							cprintf("*");

							gotoxy(40,12);
							textcolor(YELLOW);
							cprintf("GAME OVER");
							gotoxy(37,14);
							cprintf("YOUR SCORE : %d",score);
							gotoxy(21,13);
							textcolor(CYAN);
							cprintf("YOU ARE WINNER");
							a=kbhit();
							if(a!=0){
								ch=getch();
							}

							delay(10);

						}

					}
					else{
						gotoxy(21,13);
						textcolor(CYAN);
						cprintf("YOU LOSE");

						gotoxy(21,15);
						textcolor(CYAN);
						cprintf("TRY AGAIN, ALL THE BEST");
						sleep(2);
					}

					ch=27;

			}
		  }

		  if(j<len)j++;

		  if(k==100)k=0; //recycling array
		  old_ch=ch;		     //holding previous key stroke
		  //printf("%c=%d,%c=%d ",old_ch,old_ch,ch,ch);
		   //getch();

		  delay(speed);  //speed of snake
	}
}
