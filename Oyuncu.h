#ifndef OYUNCU_H
#define OYUNCU_H

#include <string>
#include "Sporcu.h"

using namespace std;

class Oyuncu {
public:

    Oyuncu(int skor, int oyuncu_id, string oyuncu_ad) : _Skor(skor), _oyuncuID(oyuncu_id), _oyuncuAd(oyuncu_ad) { }
    Oyuncu() :Oyuncu(0, 0, "HÝKMET") {}

    Sporcu *KartListesi[8];

    void setSkor(int s) { _Skor = _Skor + s; }
    int getSkor() { return _Skor; }

    void setOyuncuID(int s) { _oyuncuID = s; }
    int getOyuncuID() { return _oyuncuID; }

    void setOyuncuAD(string s) { _oyuncuAd = s; }
    string getOyuncuAD() { return _oyuncuAd; }

private:
    int _Skor = 0;
    int _oyuncuID = 0;
    string _oyuncuAd = "";



};

#endif // OYUNCU_H

