void c_window();
void snake(int);

void reset(){

	int speed,l;
	char ch2;
	clrscr();

	gotoxy(15,23);
	textcolor(BLUE);
	//cprintf("PRESS 's'AND 'w' TO NAVIGATE AND 'e' TO SELECT");


	gotoxy(15,12);
	textcolor(WHITE);
	cprintf("SPEED LEVEL");

	while(1){
		gotoxy(27,12);
		textcolor(GREEN);
		cprintf("%d",l);
		ch2=getch();
		if(ch2==13)break;
		else if(ch2==72){
			l++;
			if(l>9)l=9;
		}
		else if(ch2==80){
			l--;
			if(l<1)l=1;
		}

	}

	clrscr();
	//textbackground(BLACK);
	c_window();
	snake(l);

}
