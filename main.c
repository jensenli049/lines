#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {
  int i, j;
  screen s;
  color c;

  c.red = MAX_COLOR;
  c.green = 0;
  c.blue = 0;

  clear_screen(s);

  for(i = 0, j = YRES-1; i < XRES, j >= 0; i+=5, j-=5)
    draw_line(0, j, i, 0, s, c);
  
  c.green = MAX_COLOR;
  for(i = 0, j = YRES-1; i < XRES, j >= 0; i+=5, j-=5)
    draw_line(i, 0, XRES, i, s, c);
  
  c.red = 0;
  c.green = 128;
  for(i = 0, j = YRES-1; i < XRES, j >= 0; i+=5, j-=5)
    draw_line(XRES, i, j, YRES, s, c);
  
  c.green = 0;
  c.blue = MAX_COLOR;
  for(i = 0, j = YRES-1; i < XRES, j >= 0; i+=5, j-=5)
    draw_line(0, i, i, YRES, s, c);
  
  display(s);
  save_extension(s, "lines.png");
}
