#include <color.h>
#include <display.h>
#include <display_syscalls.h>
#include <keyboard.hpp>
#include <keyboard_syscalls.h>

#include "sprites.h"

#define true  1
#define false 0

#define dash_height 20
#define cart_height 22
#define man_height  15

/* VARIABLES */
int key;

int copter_speed;
int cursor_speed;
int man_speed;

int copter_pos[2];
int cursor_pos[2];
int man_pos[2];

int cart_pos;
int cart_counter;
int cart_frame;

int man_is_hanging;
int man_is_dead;

int gravity;
int cart_speed;
int try_num;

/* FUNCTIONS */
// (from routines.c)
void CopySpriteNbit(const unsigned char* data, int x, int y, int width, int height, const color_t* palette, unsigned int bitwidth);
void CopySpriteNbitMasked(const unsigned char* data, int x, int y, int width, int height, const color_t* palette, color_t maskColor, unsigned int bitwidth);
int PRGM_GetKey(void);
void keyupdate(void);
int keydownlast(int basic_keycode);
int keydownhold(int basic_keycode);
void plot(int x0, int y0, int color);
void drawLine(int x1, int y1, int x2, int y2, int color);
void fillArea(int x, int y, int width, int height, int color);
void wait(int ms);


void draw_cursor(int x, int y) {
	// a simple crosshair cursor
	drawLine(x-3, y, x+3, y, COLOR_BLACK);
	drawLine(x, y-3, x, y+3, COLOR_BLACK);
}

void draw_copter(int x, int y, int man_is_hanging) {
	// center copter on x,y
	CopySpriteNbitMasked(copter, x-33, y-10, 66, 19, copter_palette, COLOR_WHITE, 1);

	// if man is hanging from the helicopter
	if (man_is_hanging) {
		CopySpriteNbitMasked(man_hanging, x, y+9, 6, 13, man_hanging_palette, COLOR_WHITE, 1);
	}
}

void draw_cart(int x, int y, int frame) {
	CopySpriteNbit(cart[frame], x, y, 70, 22, cart_palette, 1);
}

void draw_man(int x, int y) {
	CopySpriteNbitMasked(man_falling, x-4, y, 9, 15, man_falling_palette, COLOR_WHITE, 1);
}

void draw_dash() {
	unsigned char text[4] = "test";
	unsigned char *text_pointer = text;
	int x = 1;
	int *x_pointer = &x;
	fillArea(0, LCD_HEIGHT_PX-dash_height, LCD_WIDTH_PX, dash_height, COLOR_BLACK);
	PrintMini(x_pointer, x_pointer, text_pointer, 0, 0, 0, 0, 0, 0, 0, 0);
}

void next_try() {
	copter_speed = 2;
	cursor_speed = 4;
	man_speed = 4;

	man_pos[0] = 0;
	man_pos[1] = 0;

	man_is_hanging = true;
	man_is_dead = false;

	wait(300);
}

void die_animation(int x, int y) {
	man_is_dead = true;
	if (y<(LCD_HEIGHT_PX-dash_height-cart_height)) {
		draw_man(x, y);
	} else if (y<(LCD_HEIGHT_PX-dash_height-9)) {
		CopySpriteNbitMasked(man_dieing, x-5, LCD_HEIGHT_PX-dash_height-9, 10, 9, man_dieing_palette, COLOR_WHITE, 1);
		wait(3);
	} else if (y<(LCD_HEIGHT_PX-dash_height-3)) {
		CopySpriteNbitMasked(man_dead, x-6, LCD_HEIGHT_PX-dash_height-3, 13, 3, man_dead_palette, COLOR_WHITE, 1);
		wait(3);
	} else if (y<(LCD_HEIGHT_PX-dash_height)) {
		next_try();
	}
}


void setup() {
	Bdisp_EnableColor(1);

	copter_speed = 2;
	cursor_speed = 4;
	man_speed = 4;
	
	copter_pos[0] = LCD_WIDTH_PX/2;
	copter_pos[1] = LCD_HEIGHT_PX/2;

	cursor_pos[0] = LCD_WIDTH_PX/2;
	cursor_pos[1] = LCD_HEIGHT_PX/2;

	man_pos[0] = 0;
	man_pos[1] = 0;

	cart_pos = 0;
	cart_counter = 70;
	cart_frame = 0;

	man_is_hanging = true;
	man_is_dead = false;
}

void game() {
	/* MAIN LOOP, DO NOT BREAK */
	while (1) {
		/* GETKEY */
		keyupdate();
		// handle [menu]
		if (PRGM_GetKey()==48) {
			GetKey(&key);
		}

		// direction keys
		if (keydownlast(KEY_PRGM_LEFT) && cursor_pos[0]>33) {
			cursor_pos[0] -= cursor_speed;
		} else if (keydownlast(KEY_PRGM_RIGHT) && cursor_pos[0]<LCD_WIDTH_PX-33) {
			cursor_pos[0] += cursor_speed;
		}
		if (keydownlast(KEY_PRGM_UP) && cursor_pos[1]>0) {
			cursor_pos[1] -= cursor_speed;
		} else if (keydownlast(KEY_PRGM_DOWN) && cursor_pos[1]<(LCD_HEIGHT_PX-dash_height-cart_height-man_height-10)) {
			cursor_pos[1] += cursor_speed;
		}

		// control keys
		// shift
		if (keydownlast(KEY_PRGM_SHIFT) && man_is_hanging) {
			// drop man
			man_is_hanging = false;
			man_pos[0] = copter_pos[0];
			man_pos[1] = copter_pos[1]+9;
		}

		/* OPERATIONS */
		// move copter
		if (cursor_pos[0] > copter_pos[0]) {
			copter_pos[0]+=copter_speed;
		} else if (cursor_pos[0] < copter_pos[0]) {
			copter_pos[0]-=copter_speed;
		}

		if (cursor_pos[1] > copter_pos[1]) {
			copter_pos[1]+=copter_speed;
		} else if (cursor_pos[1] < copter_pos[1]) {
			copter_pos[1]-=copter_speed;
		}

		// if man is falling, drop him
		if (!man_is_hanging) {
			man_pos[1] += man_speed;
		}
		// if man is below cart level, check if he is in the cart
		if (!man_is_hanging && man_pos[1]>(LCD_HEIGHT_PX-dash_height-cart_height-5)) {
			if (!man_is_dead && man_pos[0]>cart_pos && man_pos[0]<cart_pos+35) {
				next_try();
			} else {
				die_animation(man_pos[0], man_pos[1]);
			}
		}

		// move cart
		cart_counter = (cart_counter+1) % LCD_WIDTH_PX;
		cart_pos = cart_counter-70;
		// update frame
		cart_frame = (cart_frame+1) % 2;

		/* GRAPHICS */
		// clear screen
		Bdisp_AllClr_VRAM();

		// display functions
		draw_copter(copter_pos[0], copter_pos[1], man_is_hanging);
		draw_cart(cart_pos, LCD_HEIGHT_PX-dash_height-cart_height, cart_frame);

		// if man is falling, draw him
		if (!man_is_hanging /* && !man_is_dead */) {
			draw_man(man_pos[0], man_pos[1]);
		}

		// draw dash
		draw_dash();

		// draw cursor on top of everything
		draw_cursor(cursor_pos[0], cursor_pos[1]);
		
		// copy VRAM to screen
		Bdisp_PutDisp_DD();
	}
}

int main() {
	setup();
	game();

	return 1;
}