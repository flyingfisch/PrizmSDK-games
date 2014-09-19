/* COPTER SPRITE
 * size: width=66, height=19
*/

const color_t copter_palette[2] = {0xffff, 0x0000};

const unsigned char copter[171] = {
	0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,
	0x00,0x07,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,
	0x00,0x00,0x00,0x00,0x02,0x80,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xff,0xf0,0x00,0x00,0x00,
	0x00,0x00,0x00,0x3f,0x80,0x0c,0x00,0x00,0x00,
	0x00,0x00,0x00,0x22,0xaa,0xab,0x00,0x00,0x00,
	0xfb,0xe0,0x00,0x24,0x00,0x01,0xc0,0x00,0x00,
	0x06,0x00,0x00,0x38,0x15,0x50,0xa0,0x00,0x00,
	0x03,0x00,0x00,0x20,0x00,0xa8,0x50,0x00,0x00,
	0x01,0xff,0xff,0xc8,0x10,0x50,0xa8,0x00,0x00,
	0x01,0x15,0x40,0x00,0x00,0xa8,0x56,0x00,0x00,
	0x00,0xe0,0x3f,0xf8,0x10,0x00,0x01,0x80,0x00,
	0x00,0x00,0x00,0x08,0x00,0x80,0x00,0x40,0x00,
	0x00,0x00,0x00,0x08,0x10,0x00,0x00,0x40,0x00,
	0x00,0x00,0x00,0x06,0x00,0x80,0x00,0x80,0x00,
	0x00,0x00,0x00,0x01,0xff,0xff,0xff,0x00,0x00,
	0x00,0x00,0x00,0x00,0x08,0x00,0x40,0x00,0x00,
	0x00,0x00,0x00,0x00,0xff,0xff,0xf8,0x00,0x00
};

/* MAN (HANGING) SPRITE
 * size: width=6, height=13
*/

const color_t man_hanging_palette[2] = {0x0000, 0xffff};

const unsigned char man_hanging[13] = {
	0x78,
	0x78,
	0x48,
	0xb4,
	0xcc,
	0xcc,
	0xcc,
	0xb4,
	0xb4,
	0xb4,
	0xb4,
	0x6c,
	0x6c
};


/* MAN (FALLING) SPRITE
 * size: width=6, height=15
*/

const color_t man_falling_palette[2] = {0xffff, 0x0000};

const unsigned char man_falling[30] = {
	0x00,0x00,
	0x00,0x00,
	0x00,0x00,
	0x80,0x00,
	0x80,0x00,
	0x58,0x00,
	0x40,0x00,
	0x3e,0x00,
	0x19,0x00,
	0x18,0x80,
	0x24,0x00,
	0x24,0x00,
	0x24,0x00,
	0x24,0x00,
	0x48,0x00
};

/* MAN (DIEING) SPRITE
 * size: width=10, height=9
*/

const color_t man_dieing_palette[2] = {0xffff, 0x0000};

const unsigned char man_dieing[18] = {
	0x00,0x40,
	0x0c,0x80,
	0xc1,0x00,
	0x3e,0x00,
	0x0c,0x00,
	0x0c,0x00,
	0x1e,0x00,
	0x12,0x00,
	0xfb,0xc0
};

/* MAN (DEAD) SPRITE
 * size: width=13, height=3
*/

const color_t man_dead_palette[2] = {0xffff, 0x0000};

const unsigned char man_dead[6] = {
	0x46,0x80,
	0x3f,0xc0,
	0xff,0xf0
};

/* CART SPRITE
 * size: width=70, height=22
*/

const color_t cart_palette[2] = {0xffff, 0x0000};

const unsigned char cart[2][198] = {
	{0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x00,
	0x00,0x00,0x10,0x00,0x1e,0x00,0x00,0x00,0x00,
	0x00,0x0a,0xe8,0x00,0x0c,0x00,0x00,0x00,0x00,
	0x00,0x30,0x92,0xc0,0x18,0x00,0x00,0x00,0x40,
	0x00,0x48,0x08,0x20,0x1f,0xa8,0x00,0x00,0x60,
	0x01,0x60,0x00,0x08,0x28,0x05,0x00,0x15,0xf0,
	0x02,0x80,0x80,0x8d,0x38,0x00,0xa0,0x21,0xf8,
	0x15,0x05,0x01,0x01,0xbf,0x80,0x15,0x43,0xfc,
	0x22,0x02,0x02,0x02,0x5d,0x50,0x00,0x07,0xcc,
	0x80,0x00,0x00,0x00,0x21,0x20,0xbe,0x3f,0x80,
	0xff,0xff,0xff,0xff,0xff,0xc1,0xff,0xff,0x00,
	0xb8,0xba,0xaa,0xaa,0xaa,0xc3,0xff,0xbd,0x80,
	0xf8,0x9d,0x55,0x55,0x55,0x42,0xff,0xd7,0x00,
	0xa5,0x1a,0xaa,0xaa,0xfa,0xc2,0xf7,0xbf,0x00,
	0xc5,0x65,0x55,0x55,0xf5,0x44,0x6f,0xff,0x00,
	0xf7,0xd7,0xff,0xff,0xa7,0xc0,0x60,0x3b,0x00,
	0x4e,0xe4,0x00,0x02,0x69,0xaa,0x6a,0xc3,0x00,
	0x43,0x9c,0x00,0x02,0x3f,0x00,0x20,0x02,0x00,
	0x4d,0x44,0x00,0x03,0xf1,0x00,0x90,0x02,0x80,
	0x31,0x48,0x00,0x02,0x59,0x00,0x88,0x04,0x80,
	0x32,0x38,0x00,0x01,0x96,0x03,0x04,0x18,0x40,
	0x1a,0x30,0x00,0x00,0x94,0x00,0x02,0x00,0x60},

	{0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x00,
	0x00,0x00,0x18,0x00,0x1e,0x00,0x00,0x00,0x00,
	0x00,0x01,0xa4,0x00,0x0c,0x00,0x00,0x00,0x00,
	0x00,0x24,0x82,0xc0,0x18,0x00,0x00,0x00,0x40,
	0x00,0x5b,0x01,0x10,0x1f,0x28,0x00,0x00,0x60,
	0x03,0xc2,0x02,0x08,0x28,0x05,0x00,0x15,0xf0,
	0x06,0x00,0x02,0x0d,0x38,0x00,0xaa,0xa1,0xf8,
	0x08,0x20,0x20,0x20,0x3f,0x80,0x00,0x03,0xfc,
	0x40,0x10,0x10,0x10,0x5d,0x50,0x00,0x07,0xcc,
	0x28,0x09,0x08,0x08,0x21,0x20,0xbe,0x3f,0x80,
	0xff,0xff,0xff,0xff,0xff,0xc1,0xff,0xff,0x00,
	0xb9,0x3a,0xaa,0xaa,0xaa,0xc3,0xff,0xbd,0x80,
	0xf5,0x5d,0x55,0x55,0x55,0x42,0xff,0xd7,0x00,
	0xab,0xaa,0xaa,0xaa,0xfa,0xc2,0xf7,0xbf,0x00,
	0xc5,0x45,0x55,0x55,0xd5,0x46,0x6f,0xff,0x00,
	0xeb,0xaf,0xff,0xff,0xb6,0xc0,0x60,0x3b,0x00,
	0x7f,0xfc,0x00,0x02,0x59,0xaa,0x6a,0xc2,0x80,
	0x43,0x84,0x00,0x03,0xf1,0x00,0x20,0x06,0xc0,
	0x45,0x44,0x00,0x02,0x3f,0x00,0x90,0x04,0x40,
	0x29,0x28,0x00,0x02,0x69,0x01,0x88,0x08,0x40,
	0x31,0x18,0x00,0x01,0xa6,0x01,0x08,0x08,0x80,
	0x19,0x30,0x00,0x00,0xa4,0x01,0x00,0x10,0x00}
};