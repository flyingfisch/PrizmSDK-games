#include <color.h>
#include <display.h>
#include <display_syscalls.h>
#include <keyboard.hpp>
#include <keyboard_syscalls.h>
/* USEFUL ROUTINES */
#include "routines.h"


/* FUNCTIONS */
void dispCanvas(int x, int y, int width, int height, int zoom, color_t **canvas) {
	int i;
	int j;
	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			if (canvas[i][j]) {
				fillArea(i*zoom+x, j*zoom+y, zoom, zoom, canvas[i][j]);
			}
		}
	}
}

void dispCursor(int origin_x, int origin_y, int x, int y, int zoom) {
	fillArea(x*zoom+origin_x, y*zoom+origin_y, zoom, zoom, COLOR_RED);
}

/* MAIN FUNCTION */
int main() {
	/* SETUP */
	// enable fullcolor
	Bdisp_EnableColor(1);
	/* VARS */
	char buffer[10];

	int key;
	int key_dump;

	int cursor[2] = {0,0};
	int origin[2] = {1,1};

	int canvas_height = 8;
	int canvas_width = 8;
	color_t canvas[8][8];

	int zoom = 4;

	int i;
	int j;

	for (i = 0; i < canvas_height; i++) {
		for (j = 0; j < canvas_width; j++) {
			canvas[i][j] = COLOR_WHITE;
		}
	}

	/* MAIN LOOP, NEVER BREAK */
	while (1) {
		// clear screen
		Bdisp_AllClr_VRAM();

		/* GETKEY */
		if (PRGM_GetKey()==KEY_PRGM_MENU) {
			// handle menu
			GetKey(&key_dump);
		}

		// move cursor
		if ((PRGM_GetKey()==KEY_PRGM_UP) && (cursor[1]>0)) {
			cursor[1]--;
		}

		if ((PRGM_GetKey()==KEY_PRGM_DOWN) && (cursor[1]<canvas_height)) {
			cursor[1]++;
		}

		if ((PRGM_GetKey()==KEY_PRGM_LEFT) && (cursor[0]>0)) {
				cursor[0]--;
		}

		if ((PRGM_GetKey()==KEY_PRGM_RIGHT) && (cursor[0]<canvas_width)) {
				cursor[0]++;
		}

		// display the canvas
		dispCanvas(origin[0], origin[1], canvas_width, canvas_height, zoom, canvas);

		// display the cursor
		dispCursor(origin[0], origin[1], cursor[0], cursor[1], zoom);

		// debug
		strcpy(buffer, "  ");
		itoa(cursor[1], buffer+2);
		PrintXY(1, 7, buffer, TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);

		// refresh screen
		Bdisp_PutDisp_DD();
	}


	return 1;
}