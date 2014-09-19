#include <display_syscalls.h>
#include <keyboard_syscalls.h>

int main() {
	int key;

	while (1) {
		Bdisp_AllClr_VRAM();
		GetKey(&key);
	}

	return 1;
}