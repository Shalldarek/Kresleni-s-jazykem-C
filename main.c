#include <stdio.h>
#include "drawing.h"

#define RADEK_MICKU 15      
#define MAX_SLOUPEC 70      
#define MIN_SLOUPEC 10      
#define POCET_SNIMKU 300 

void prerusovana_cara(int cislo) {
    for (int i = 0; i < cislo * 2; i++) {
        if (i % 2 == 0) {
            set_blue_color();  
            draw_pixel();
        } else {
            move_right();
        }
        move_right();
    }

    move_down();
    move_left();

    for (int i = 0; i < cislo * 2; i++) {
        if (i % 2 == 0) {
            set_green_color();  
            draw_pixel();
        } else {
            move_right();
        }
        move_right();
    }

    move_down();
    move_left();

    for (int i = 0; i < cislo * 2; i++) {
        if (i % 2 == 0) {
            set_red_color();  
            draw_pixel();
        } else {
            move_right();
        }
        move_right();
    }
}

void schody(int kroky) {
    for (int i = 0; i < kroky; i++) {
        if (i % 2 == 0) {
            set_blue_color();
        } else {
            set_red_color();
        }
        
        draw_pixel();
        move_right();
        set_green_color(); 
        move_down();
    }
}

void kvitko(int vyska, int sirka) {
    int stred = sirka / 2;

    for (int i = 0; i < sirka; i++) {
        for (int j = 0; j < sirka; j++) {

            if (i == stred && j == stred) {
                set_white_color();
                draw_pixel();
            } 
            else if ((i - stred) <= 1 && (j - stred) <= 1) {
                set_yellow_color();
                draw_pixel();
            } 
            else {
                move_right();
                continue;
            }

            move_right();
        }

        move_down();

        for (int k = 0; k < sirka; k++) {
            move_left();
        }
    }

    for (int i = 0; i < vyska; i++) {
        move_right();
        set_green_color();
        draw_pixel();
        move_down();
        move_left();
    }

    move_right();
    set_green_color();
    draw_pixel();

    move_down();
    move_down();
    move_down();
}

void louka(int vyska, int sirka) {
    int velikost_kvetu = 3;
    int delka_stonku = 3;
    int vodorovna_mezera = 3;
    int svisla_mezera = 2;
    int zacatek_radku = 1;
    int zacatek_sloupce = 1;

    int vyska_kvetiny = velikost_kvetu + delka_stonku + svisla_mezera;

    for (int r = 0; r < vyska; r++) {
        for (int c = 0; c < sirka; c++) {
            int radek = zacatek_radku + r * vyska_kvetiny;
            int sloupec = zacatek_sloupce + c * (velikost_kvetu + vodorovna_mezera);

            move_to(radek, sloupec);
            kvitko(delka_stonku, velikost_kvetu);
        }
    }

    move_to(zacatek_radku + vyska * vyska_kvetiny + 1, 1);
    //Stonky spodnich kvetin jsou dvojnasobne mensi, nevim, jak to opravit
}

void animace() {
    int sloupec = MIN_SLOUPEC;
    int smer = 1; 
    
    clear_screen();

    set_red_color(); 

    for (int snimek = 0; snimek < POCET_SNIMKU; snimek++) {
        clear_screen(); 
        set_red_color(); 

        move_to(RADEK_MICKU, sloupec);
        draw_pixel();
        move_right();
        draw_pixel();
        move_down();
        move_left();
        draw_pixel();
        move_right();
        draw_pixel();

        animate_ms(20);

        sloupec += smer;

        if (sloupec >= MAX_SLOUPEC) {
            smer = -1; 
        } else if (sloupec <= MIN_SLOUPEC) {
            smer = 1; 
        }
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
    schody(10);
  }
  else if (drawing == 2) {
    kvitko(2, 3);
  }
  else if (drawing == 3) {
    louka(2, 3);
  }
  else if (drawing == 4) {
    animace();

    end_drawing();
  }
  else {
    printf("Spatne zadani. Zadejte cislo od 0 - 6");
  }

  end_drawing();

  return 0;
}