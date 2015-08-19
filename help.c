void help(){
	clrscr();
	gotoxy(33,10);
	textcolor(CYAN);
	cprintf("CONTROL KEY");

	gotoxy(22,12);
	textcolor(RED);
	cprintf("'USE ARROW KEYS TO CONTROL SNAKE MOVEMENT ");

	gotoxy(22,14);
	textcolor(GREEN);
	cprintf("'ENTER' TO SELECT");

	gotoxy(22,16);
	textcolor(YELLOW);
	cprintf("SPACE TO PAUSE");

	gotoxy(30,18);
	textcolor(MAGENTA);
	cprintf("ESC TO QUIT");


	gotoxy(58,25);
	textcolor(BLUE);
	cprintf("dev.achieve@gmail.com");

	getch();


}
