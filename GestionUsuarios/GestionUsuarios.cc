#include <cmath>
#include <sstream>
#include <iostream>
#include <iomanip>

#include <ESAT/window.h>
#include <ESAT/draw.h>
#include <ESAT/sprite.h>
#include <ESAT/input.h>
#include <ESAT/time.h>

typedef struct {
	char firstName[30];
	char lastName[50];
	char bDate[12];
	char provinc[30];
	char country[30];
	char user[12];
	char password[12];
	char mail[40];
	short credits;
}user;

void changeColor(int var, int c1, int c2, int c3, int t = 255);
void changeTxt(int size, int color[3]);
void index();

/* TOOLS */
void changeColor(int var, int c1, int c2, int c3, int t) {
	if (var == 1) {
		ESAT::DrawSetFillColor(c1, c2, c3, t);
	}
	else {
		ESAT::DrawSetStrokeColor(c1, c2, c3, t);
	}
}

void changeTxt(int size) {
	ESAT::DrawSetTextSize(size);
}

void button(int x, int y, char txt[]) {
	float p[] = {
		0 + x, 0 + y,
		350 + x, 0 + y,
		350 + x, 50 + y,
		0 + x, 50 + y,
		0 + x, 0 + y
	};
	ESAT::DrawPath(p, 5);
	ESAT::DrawText(x+50, y+43, txt);
}

/* INDEX MENU */
void index() {
	changeColor(0, 255, 255, 255);
	changeTxt(36);
	ESAT::DrawText(150, 150, "USER ADMIN PANEL");
	changeColor(0, 255, 255, 255);
	changeColor(1, 99, 99, 99);
	button(200, 250, "LOGIN");
}

int ESAT::main(int argc, char **argv){
	ESAT::WindowInit(800, 600);
	ESAT::DrawSetTextFont("atari.ttf");
	while (ESAT::WindowIsOpened() && !ESAT::IsSpecialKeyDown(ESAT::kSpecialKey_Escape)){
		ESAT::DrawClear(0, 0, 0);
		index();
		ESAT::WindowFrame();
	}

	ESAT::WindowDestroy();
	return 0;
}
