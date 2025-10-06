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

//Kvitko se zelenym listkem vlevo
void kvitko(int height, int width) {
    int stred = width / 2;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            if (i == stred && j == stred) {
                set_yellow_color(); 
                draw_pixel();
            } else if ((i - stred) <= 1 && (j - stred) <= 1) {
                set_red_color(); 
                draw_pixel();
            } else {
                move_right();
                continue;
            }
            move_right();
        }
        move_down();
        for (int k = 0; k < width; k++) move_left();
    }

    move_to(width + 1, stred + 1);
    for (int i = 0; i < height; i++) {
        set_green_color();
        draw_pixel();

        if (i == height / 2) {
            move_left();
            set_green_color();
            draw_pixel();
            move_right();
        }

        move_down();
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
    kvitko(4, 3);
  }
  else {
    printf("To je zatim vse");
  }

  end_drawing();

  return 0;
}