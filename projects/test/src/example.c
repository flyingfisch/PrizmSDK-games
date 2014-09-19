#include <color.h>
#include <display.h>
#include <display_syscalls.h>
#include <keyboard.hpp>
#include <keyboard_syscalls.h>
#include <CONVERT_syscalls.h>
/* SPRITES */
#include "sprites.h"
/* ROUTINES */
#include "routines.h"

/* MAP */
int map[7][12] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 2,0,0,0,0,0,0,0,0,0,0,2 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1 }
};

/* GAME ROUTINES */
void drawMap(int x, int y, int width, int height) {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			switch (map[i][j]) {
				case 1:
					CopySpriteNbitMasked(ground, j*32+x, i*32+y, 32, 32, ground_palette, COLOR_WHITE, 8);
					break;
				case 2:
					CopySpriteNbitMasked(grass, j*32+x, i*32+y, 32, 32, grass_palette, COLOR_WHITE, 8);
					break;
			}
		}
	}
}

/* MAIN LOOP */
int main() {
	/* VARIABLES */
	int key;
	int key_dump;

	int player_x = 64;
	int player_y = 1;

	int player_x_floored;
	int player_y_floored;

	int origin_x = 0;
	int origin_y = 0;

	char buffer[4];


	/* SETUP */
	// enable fullcolor mode
	Bdisp_EnableColor(1);

	/* MAIN LOOP */
	while (1) {
		/* GETKEY */
		key = PRGM_GetKey();

		if (key==KEY_PRGM_MENU) {
			GetKey(&key_dump);
		}

		/* COLLISIONS, ETC. */
		// check if a tile is under player
		player_x_floored = floor2((player_x/32)-1);
		player_y_floored = floor2(player_x/32);

		if (map[player_y_floored][player_x_floored]==0 && map[player_y_floored][player_x_floored+1]==0) {
			player_y++;
		}


		/* DRAWING */
		// draw BG
		Bdisp_Fill_VRAM(COLOR_LIGHTCYAN, 3);

		// draw map
		drawMap(origin_x, origin_y, 12, 7);

		// draw player
		CopySpriteNbitMasked(egg, player_x, player_y, 32, 32, egg_palette, COLOR_WHITE, 8);

		// debug
		strcpy(buffer, "  ");
		itoa(player_x_floored, buffer+2);
		PrintXY(1, 1, buffer, TEXT_MODE_NORMAL, TEXT_COLOR_BLACK);

		// refresh screen
		Bdisp_PutDisp_DD();
	}
	return 1;
}