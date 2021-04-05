#ifndef TEST_H
#define TEST_H


#include <string>
#include "Futbolcu.h"
#include "Basketbolcu.h"
#include "Sporcu.h"
#include "Bilgisayar.h"
#include "Kullanici.h"
#include "algorithm"

#define KART_POZ 157

using namespace std;

class Test {
public:

    Test(cocos2d::Scene* sahne) : _sahne(sahne){ }
    Test() { }

    Sporcu *deste[16] = {
        /* FUTBOLCULAR */
        new Futbolcu("Cristiano Ronaldo", "Juventus", 70, 92, 85), // Cristiano Ronaldo.png
        new Futbolcu("Neymar", "PSG",70, 89, 87),
        new Futbolcu("Kylian Mbappe", "PSG", 70, 94, 70),
        new Futbolcu("Trent-Arnold", "Liverpool", 70, 70, 87),
        new Futbolcu("Marcelo", "Real Madrid", 70, 77, 79),
        new Futbolcu("Van Dijk", "Liverpool", 70, 50, 40),
        new Futbolcu("Kevin Debruyne", "Manchester City", 70, 80, 88),
        new Futbolcu("Sergio Ramos", "Real Madrid", 70, 55, 75),
        /* BASKETBOLCULAR */
        new Basketbolcu("Stephen Curry", "Golden Stare Warriors", 95, 96, 94),
        new Basketbolcu("James Harden", "Houston Rockets", 93, 90, 90),
        new Basketbolcu("Anthony Davis", "Los Angeles Lakers", 80, 75, 45),
        new Basketbolcu("Jason Tatum", "Boston Celtics", 88, 90, 87),
        new Basketbolcu("Jimmy Butler", "Miami Heat", 89, 85, 81),
        new Basketbolcu("Kevin Durant", "Brooklyn Nets", 94, 92, 91),
        new Basketbolcu("Bam Adebayo", "Miami Heat", 78, 77, 39),
        new Basketbolcu("Klay Thompson", "Golden State Warriors", 90, 86, 91)
    };
    

    enum x_kart_pos
    {
        poz1 = KART_POZ,
        poz2 = KART_POZ * 2,
        poz3 = KART_POZ * 3,
        poz4 = KART_POZ * 4,
        poz5 = KART_POZ * 5,
        poz6 = KART_POZ * 6,
        poz7 = KART_POZ * 7,
        poz8 = KART_POZ * 8,

    };
    
    enum er_meydani {
        meydan1 = 600,
        meydan2 = 800
    };

    
    void kartDagit();
    void adlarýYaz();
    void adlarýYenile();

    void setSahne(cocos2d::Scene * sahne);
    Kullanici getKullanýcý();
    Bilgisayar getBilgisayar();
    string getKullaniciAd();
    void BilgisayarKartOyna(int tip);
    void oyunuBitir();
  


private:
    cocos2d::Scene* _sahne;
    Kullanici _insan;
    Bilgisayar _robot;

    cocos2d::Label* kullanici_skor;
    cocos2d::Label* bilgisayar_skor;


};




#endif
