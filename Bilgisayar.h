#ifndef BILGISAYAR_H

#define BILGISAYAR_H

#include "Oyuncu.h"
#include "Sporcu.h"

class Bilgisayar : public Oyuncu {
    typedef Oyuncu super;

public:
    Bilgisayar(int skor, int id) : super(skor, id, "Bilgisayar") {}
    Bilgisayar() : super(0, 2, "Bilgisayar") {}

    int KartSec(int insan_index) {
        int robot_index;

        if (insan_index >= 4) {
            robot_index = 4 + rand() % 4;

            while (KartListesi[robot_index]->isKullanildiMi()) {
                robot_index = 4 + rand() % 4;
            }
        }
        else {
            robot_index = rand() % 4;

            while (KartListesi[robot_index]->isKullanildiMi()) {
                robot_index = rand() % 4;
            }
        }
        return robot_index;
    }
};

#endif
