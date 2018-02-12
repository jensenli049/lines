#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main(){
  int i, j;
  screen s;
  color c;

  c.red = MAX_COLOR;
  c.green = 0;
  c.blue = 0;
  
  clear_screen(s);
  
  for(i = 1, j = YRES-1; i < XRES, j > 0; i++, j++)
    draw_line(0, j, i, 0, s, c);
  
  c.green = MAX_COLOR;
  for(i = 1, j = YRES-1; i < XRES, j > 0; i++, j++)
    draw_line(i, 0, 0, j, s, c);

  c.red = 0;
  c.green = 128;
  for(i = 1, j = YRES-1; i < XRES, j > 0; i++, j++)
    draw_line(j, 0, 0, i, s, c);

  c.green = 0;
  c.blue = MAX_COLOR;
  for(i = 1, j = YRES-1; i < XRES, j > 0; i++, j++)
    draw_line(0, i, j, 0, s, c);

  display(s);
  save_extension(s, "lines.png");
}
