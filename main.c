#include <stdio.h>
#include "drawing.h"

void prerusovana_cara(int length) {
    for (int i = 0; i < length * 2; i++) {
        if (i % 2 == 0) {
            set_blue_color();  
            draw_pixel();
        } else {
            move_right();
        }
        move_right();
    }
}

void schody(int steps) {
    for (int i = 0; i < steps; i++) {
        set_red_color();
        draw_pixel();
        move_right();

        set_green_color();
        move_down();
    }
}

//nedokoncene
void kvitko(int height, int width) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            if (i == width/2 && j == width/2) {
            } else {
                set_red_color();    
            }
            draw_pixel();
            move_right();
        }
        move_down();
        move_left();
        for (int k = 0; k < width-1; k++) {
            move_left();
        }
    }

    for (int i = 0; i < height; i++) {
        move_right();
        set_green_color();
        draw_pixel();
        move_down();
        move_left();
    }
}



int main() {
  clear_screen();

  int drawing = 0;
  scanf("%d", &drawing);

  if (drawing == 0) {
    prerusovana_cara(10); 
  }
  else if (drawing == 1) {
    schody(5);
  }
  else if (drawing == 2) {
    kvitko(3, 3);
  }
  else {
    printf("To je zatim vse");
  }

  end_drawing();

  return 0;
}