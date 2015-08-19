void start_style(){
	int si,sj,sk,v=0,ry,y,rx,x;

	clrscr();

	for(si=0,y=1,ry=25;si<=11;si++,y++,ry--){
		textcolor(WHITE);
		gotoxy(35,y);cprintf("g.Z");
		delay(20);
		textcolor(BLUE);
		gotoxy(35,y);cprintf("%c%c%c%c%c%c",219,219,219,219,219,219);

		textcolor(WHITE);
		gotoxy(38,ry);cprintf("oNE");
		delay(20);
		textcolor(BLUE);
		gotoxy(35,ry);cprintf("%c%c%c%c%c%c",219,219,219,219,219,219);


		//clrscr();
	}

	gotoxy(35,y);
	textcolor(WHITE);
	cprintf("g.ZoNE");
	sleep(2);




	for(si=0,rx=35,x=38;si<4;si++,x++,rx--){

		textcolor(RED);
		gotoxy(rx,y);cprintf("g.Z");
		delay(1);
		gotoxy(rx,y);
		cprintf("%c%c%c",219,219,219);
		textcolor(RED);
		delay(1);
		gotoxy(x,y);
		cprintf("%c%c%c",219,219,219);

	}
	textcolor(RED);
	//textbackground(BLACK);
	gotoxy(23,y);
	cprintf(" I T S  g A M E R  S P A C E ");


	sleep(2);
	 clrscr();
	 gotoxy(20,12);
	 textcolor(GREEN);
	 cprintf("S       N       A       K       E");
	 gotoxy(20,14);
	 textcolor(GREEN);
	 cprintf("_________________________________");

	 sleep(2);

}
