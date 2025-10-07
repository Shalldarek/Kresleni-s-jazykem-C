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

    for (int i = 0; i < height; i++) {
        move_right();
        set_green_color();
        draw_pixel();
        move_down();
        move_left();
    }

    move_right();
    //move_left();
    set_green_color();
    draw_pixel();
    move_down();
    move_down();
    move_down();
}

void louka(int height, int width) {
    int velikost_kvetu = 3;
    int delka_stonku = 3;
    int vodorovna_mezera = 2;
    int svisla_mezera = 1;
    int zacatek_radku = 1;
    int zacatek_sloupce = 1;

    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            int radek = zacatek_radku + r * (velikost_kvetu + delka_stonku + svisla_mezera);
            int sloupec = zacatek_sloupce + c * (velikost_kvetu + vodorovna_mezera);

            move_to(radek, sloupec);
            kvitko(delka_stonku, velikost_kvetu);
        }
    }

    move_to(zacatek_radku + height * (velikost_kvetu + delka_stonku + svisla_mezera), 1);
}

void animace() {

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
  else if (drawing == 3) {
    louka(2, 3);
  }
  else {
    printf("To je zatim vse");
  }

  end_drawing();

  return 0;
}