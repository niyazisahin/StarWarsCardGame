#ifndef SPORCU_H
#define SPORCU_H

#include <string>
#include "cocos2d.h"

using namespace std;

class Sporcu {
    // rastgele sol yukarýda capslock çýkýp duruyor bilgisayarýn lanetli
public:

    Sporcu(string ad, string takim) : _sprocuAdi(ad), _sporcuTakim(takim) {
        string bas = "kartlar/";
        string son = ".png";
        setKart(bas + ad + son);
    }

    Sporcu() {
        setSporcuAdi("Test");
        setSporcuTakim("Osmanlýspor");
    }


    void setSporcuTakim(string x) { _sporcuTakim = x; }
    string getSporcuTakim() { return _sporcuTakim; }

    string getSporcuAdý() { return _sprocuAdi; }
    void setSporcuAdi(string y) { _sprocuAdi = y; }

    int SporcuPuaniGoster(Sporcu* i1, Sporcu* b1, bool futbolcumu);
    void setKart(string dosya_adi);
    cocos2d::Sprite* getKart();
    void setPos(double x, double y);
    void setPos2(double x, double y, double x2, double y2);
    cocos2d::Vec2 getPos();
    void TersDondur(); 

    bool isKullanildiMi() { return _kullanildiMi; }
    void setKullanildiMi(bool kullanildiMi) { _kullanildiMi = kullanildiMi; }

    virtual int getOzellik1() { return -1; }
    virtual void setOzellik1(int ozellik1) {}
    virtual int getOzellik2() { return -1; }
    virtual void setOzellik2(int ozellik2) {}
    virtual int getOzellik3() { return -1; }
    virtual void setOzellik3(int ozellik3) {}
    void setAnaPos(cocos2d::Vec2 pos) { AnaPos = pos; }
    cocos2d::Vec2 getAnaPos() { return AnaPos; }
    

private:
    cocos2d::Sprite *kart;
    string _sprocuAdi;
    string _sporcuTakim;
    bool _kullanildiMi = false;
    bool tersmi = false;
    cocos2d::Vec2 AnaPos;


};

#endif //SPORCU_H
