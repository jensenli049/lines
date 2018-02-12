#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if(x0 > x1)
    draw_line(x1,y1,x0,y0,s,c);
  int a = y1-y0;
  int b = x0-x1;
  int d;
	
  double m = (double)a / b;
	
  //octants 1 and 5
  if(m >= 0 && m <= 1){
    d = 2 * a + b;
		
    while(x0 <= x1 && x0 < XRES){
      plot(s, c, x0, y0);
			
      if(d > 0){
	y0++;
	d += 2 * b;
      }
			
      x0++;
      d += 2 * a;
    }
  }
  //octants 2 and 6
  else if(m > 1){
    d = a + 2 * b;
    while (y0 <= y1 && y0 < YRES){
      plot(s, c, x0, y0);
			
      if(d < 0){
	x0++;
	d += 2 * a;
      }
			
      y0++;
      d += 2 * b;
    }
  }
  //octants 3 and 7
  else if(m < -1){
    d = a - 2 * b;
    while (y0 >= y1 && y0 < YRES){
      plot(s, c, x0, y0);
			
      if(d > 0){
	x0++;
	d += 2 * a;
      }
			
      y0--;
      d -= 2 * b;
    }
  }
  //octants 4 and 8
  else if(m < 0 && m >= -1){		
    d = 2 * a - b;
    while (x0 <= x1 && x0 < XRES){
      plot(s, c, x0, y0);
      
      if(d < 0){
	y0--;
	d -= 2 * b;
      }
			
      x0++;
      d += 2 * a;
    }
  }
}
