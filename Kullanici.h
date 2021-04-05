#ifndef KULLANICI_H
#define KULLANICI_H

#include <string>
#include "Oyuncu.h"
#include "Sporcu.h"

using namespace std;

class Kullanici : public Oyuncu {
    typedef Oyuncu super;

public:
    Kullanici(int skor, int id, string kullanici_adi) : super(skor, id, kullanici_adi) {}
    Kullanici() : super(0, 1, "Oyuncu1") {}

    bool KartSec(cocos2d::Vec2 pos, int i) {
        // 1-8 aras� kartlar�n bounding boxlar�n� all�p posun (mouse�n x ve ye si)
        // o bounding boxun i�inde olup olmad���na bakar
        auto kart = KartListesi[i];
        auto bx = kart->getKart()->getBoundingBox(); // bounding boxu al�r
        return bx.containsPoint(pos) && !kart->isKullanildiMi() && kart->getKart()->getNumberOfRunningActions() == 0; // poz i�indemi de�ilmi bakar
    }

};


#endif // KULLANICI_H