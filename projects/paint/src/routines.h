// sprite drawing routine
void CopySpriteNbit(const unsigned char* data, int x, int y, int width, int height, color_t* palette, unsigned int bitwidth) {
   color_t* VRAM = (color_t*)0xA8000000;
   VRAM += (LCD_WIDTH_PX*y + x);
   int offset = 0;
   unsigned char buf;
   for(int j=y; j<y+height; j++) {
      int availbits = 0;
      for(int i=x; i<x+width;  i++) {
         if (!availbits) {
            buf = data[offset++];
            availbits = 8;
         }
         color_t this = ((color_t)buf>>(8-bitwidth));
         *VRAM = palette[(color_t)this];
         VRAM++;
         buf<<=bitwidth;
         availbits-=bitwidth;
      }
      VRAM += (LCD_WIDTH_PX-width);
   }
}

// alpha sprite
void CopySpriteNbitMasked(const unsigned char* data, int x, int y, int width, int height, const color_t* palette, color_t maskColor, unsigned int bitwidth) {
   color_t* VRAM = (color_t*)0xA8000000;
   VRAM += (LCD_WIDTH_PX*y + x);
   int offset = 0;
   unsigned char buf;
   for(int j=y; j<y+height; j++)  
   {
      int availbits = 0;
      for(int i=x; i<x+width;  i++)  
      {
         if (!availbits)  
         {
            buf = data[offset++];
            availbits = 8;
         }
         color_t this = ((color_t)buf>>(8-bitwidth));
         color_t color = palette[this];
         if(color != maskColor)
         {
            *VRAM = color;
         }
         VRAM++;
         buf<<=bitwidth;
         availbits-=bitwidth;
      }
      VRAM += (LCD_WIDTH_PX-width);
   }
}

// getkey
int PRGM_GetKey(void) {
  unsigned char buffer[12];
  PRGM_GetKey_OS( buffer );
  return ( buffer[1] & 0x0F ) * 10 + ( ( buffer[2] & 0xF0 ) >> 4 );
}

// floor
float floor2(int x) {
   return ((int)x) - (x < 0);
}

//fills a rectangular area of (width,height) with upper-left
//corner at (x,y) with color color
void fillArea(int x, int y, int width, int height, color_t color) {
   //only use lower two bytes of color
   char* VRAM = (char*)0xA8000000;
   VRAM += 2*(LCD_WIDTH_PX*y + x);
   for(int j=y; j<y+height; j++) {
      for(int i=x; i<x+width;  i++) {
         *(VRAM++) = (color&0x0000FF00)>>8;
         *(VRAM++) = (color&0x000000FF);
      }
      VRAM += 2*(LCD_WIDTH_PX-width);
   }
}

// make 16-bit RGB color


int makeColor(int r, int g, int b) {
   return ((r / 8) << 11) | ((g / 4) << 5) | (b / 8);
}
