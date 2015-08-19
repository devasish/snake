void c_window(){//creating the window
	int a,b;
	clrscr();
	for(a=9;a<=61;a++){
		gotoxy(a,4);
		textcolor(BROWN);
		cprintf("%c",219);
		gotoxy(a,21);
		cprintf("%c",219);
		/*gotoxy(a-1,3);
		textcolor(RED);
		cprintf("%c",220); */
	}


	for(a=4;a<=21;a++){
		textcolor(BROWN);
		gotoxy(9,a);
		cprintf("%c",219);
		gotoxy(61,a);
		cprintf("%c",219);
	}
	/*for(a=4;a<21;a++){
		gotoxy(8,a);
		textcolor(RED);
		cprintf("%c",219);
	} */

}