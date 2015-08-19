void snake(int);
void reset();
void help();
void credits();



void show_menu(){
	int k=0;
	char chr=80;

	while(1){
		clrscr();

		gotoxy(15,23);
		textcolor(BLUE);
		//cprintf("PRESS '^'AND '' TO NAVIGATE AND 'e' TO SELECT");

		if(chr==80 && k==0)k=1;

		switch(k){
			case 1:

				gotoxy(15,10);
				textcolor(RED+BLINK);
				cprintf("START NEW GAME");

				textcolor(WHITE);

				gotoxy(15,11);	cprintf("OPTION");
				gotoxy(15,12);	cprintf("CREDITS");
				gotoxy(15,13);	cprintf("HELP");
				gotoxy(15,14);	cprintf("QUIT");

				chr=getch();
				if(chr==13){
					reset();
					//c_window();
					//snake(1);

				}
				else if(chr==80)k++;
				else if(chr==72)k=5;
				break;
			case 2:
				gotoxy(15,11);
				textcolor(RED+BLINK);
				cprintf("OPTION        ");


				 textcolor(WHITE);
				gotoxy(15,10);	cprintf("START NEW GAME");

				gotoxy(15,12);	cprintf("CREDITS");
				gotoxy(15,13);	cprintf("HELP");
				gotoxy(15,14);	cprintf("QUIT");
				chr=getch();
				if(chr==13){
					reset();
				}
				else if(chr==80)k++;
				else if(chr==72)k--;
				break;

			case 3:
				gotoxy(15,12);
				textcolor(RED+BLINK);
				cprintf("CREDITS       ");


				textcolor(WHITE);
				gotoxy(15,10);	cprintf("START NEW GAME");
				gotoxy(15,11);	cprintf("OPTION");
				gotoxy(15,13);	cprintf("HELP");
				gotoxy(15,14);	cprintf("QUIT");

				chr=getch();
				if(chr==13)credits();

				else if(chr==80)k++;
				else if(chr==72)k--;
				break;

			case 4:
				gotoxy(15,13);
				textcolor(RED+BLINK);
				cprintf("HELP          ");


				textcolor(WHITE);
				gotoxy(15,10);	cprintf("START NEW GAME");
				gotoxy(15,11);	cprintf("OPTION");
				gotoxy(15,12);	cprintf("CREDITS");
				gotoxy(15,14);	cprintf("QUIT");

				chr=getch();
				if(chr==13)help();

				else if(chr==80)k++;
				else if(chr==72)k--;
				break;

			case 5:
				gotoxy(15,14);
				textcolor(RED+BLINK);
				cprintf("QUIT          ");


				 textcolor(WHITE);
				gotoxy(15,10);	cprintf("START NEW GAME");
				gotoxy(15,11);	cprintf("OPTION");
				gotoxy(15,12);	cprintf("CREDITS");
				gotoxy(15,13);	cprintf("HELP");


				chr=getch();
				if(chr==13)exit(0);
				else if(chr==80)k=0;
				else if(chr==72)k--;

		}
	}
}
