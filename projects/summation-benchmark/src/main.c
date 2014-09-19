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
	int i=0;
	int key;
	int ilim=21000000;
	int cont = 0;

	// clear screen
	Bdisp_AllClr_VRAM();
	while (1) {
		
		// increment i
		i++;
		if(i>ilim) {
			keyupdate();
			if (keydownlast(KEY_PRGM_ACON)) {
				char buffer[10];
				strcpy(buffer,"  ");
				itoa(i, buffer+2); 
				PrintXY(1,1,buffer,0,COLOR_BLACK);
				Bdisp_PutDisp_DD();
			}
			// handle [menu]
			if (keydownlast(KEY_PRGM_MENU)) {
				GetKey(&key);
			}
		}
	}

	return 1;
}