#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

#include "snakef.c"
#include "cwindow.c"
#include "start.c"
#include "reset.c"
#include "credit.c"
#include "help.c"
#include "menu.c"




#define print cprintf("%c",254)
void start_style();
void show_menu(); 



void main(){
	clrscr();
	start_style();
	show_menu();
}