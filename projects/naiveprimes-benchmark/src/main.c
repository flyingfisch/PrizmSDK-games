#include <display_syscalls.h>
#include <keyboard_syscalls.h>
#include <keyboard.hpp>
#include <color.h>

// Getkey routine
const unsigned short* keyboard_register = (unsigned short*)0xA44B0000;
unsigned short lastkey[8];
unsigned short holdkey[8];

void keyupdate(void) {
memcpy(holdkey, lastkey, sizeof(unsigned short)*8);
memcpy(lastkey, keyboard_register, sizeof(unsigned short)*8);
}
int keydownlast(int basic_keycode) {
int row, col, word, bit; 
row = basic_keycode%10; 
col = basic_keycode/10-1; 
word = row>>1; 
bit = col + 8*(row&1); 
return (0 != (lastkey[word] & 1<<bit)); 
}
int keydownhold(int basic_keycode) {
int row, col, word, bit; 
row = basic_keycode%10; 
col = basic_keycode/10-1; 
word = row>>1; 
bit = col + 8*(row&1); 
return (0 != (holdkey[word] & 1<<bit)); 
}

int main() {
	int n=100;
	int key;
	// clear screen
	Bdisp_AllClr_VRAM();
	PrintXY(1,1,"Wait...",0,COLOR_BLACK);
	Bdisp_PutDisp_DD();

	for (int k = 3; k <= n; ++k) {
		for (int j = 2; j <= k-1; ++j) {
			if(k%j==0) {
				j = k-1;
			}
		}
	}

	PrintXY(1,1,"  done",0,COLOR_BLACK);
	Bdisp_PutDisp_DD();
	GetKey(&key);

	// second time around...
	n=1000;
	// clear screen
	Bdisp_AllClr_VRAM();
	PrintXY(1,1,"  Wait...",0,COLOR_BLACK);
	Bdisp_PutDisp_DD();

	for (int k = 3; k <= n; ++k) {
		for (int j = 2; j <= k-1; ++j) {
			if(k%j==0) {
				j = k-1;
			}
		}
	}

	PrintXY(1,1,"  done2",0,COLOR_BLACK);
	Bdisp_PutDisp_DD();

	GetKey(&key);

	// third time around...
	n=10000;
	// clear screen
	Bdisp_AllClr_VRAM();
	PrintXY(1,1,"  Wait...",0,COLOR_BLACK);
	Bdisp_PutDisp_DD();

	for (int k = 3; k <= n; ++k) {
		for (int j = 2; j <= k-1; ++j) {
			if(k%j==0) {
				j = k-1;
			}
		}
	}

	PrintXY(1,1,"  done3",0,COLOR_BLACK);
	Bdisp_PutDisp_DD();

	GetKey(&key);

	// fourth time...
	n=100000;
	// clear screen
	Bdisp_AllClr_VRAM();
	PrintXY(1,1,"  Wait...",0,COLOR_BLACK);
	Bdisp_PutDisp_DD();

	for (int k = 3; k <= n; ++k) {
		for (int j = 2; j <= k-1; ++j) {
			if(k%j==0) {
				j = k-1;
			}
		}
	}

	PrintXY(1,1,"  done4",0,COLOR_BLACK);
	Bdisp_PutDisp_DD();


	while(1) {
		GetKey(&key);
	}

	return 1;
}