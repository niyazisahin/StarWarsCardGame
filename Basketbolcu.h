#ifndef BASKETBOLCU_H
#define BASKETBOLCU_H
#include "Sporcu.h"

using namespace std;

class Basketbolcu : public Sporcu {
    typedef Sporcu super;

public:

    Basketbolcu(string basketciAdi, string basketciTakim, int x, int y, int z)
        : super(basketciAdi, basketciTakim)
    {
        // pozisyonlar
        setOzellik1(x);
        setOzellik2(y);
        setOzellik3(z);
    }

    Basketbolcu()
        : super("KAYINCO", "DEREBOYU")
    {
        setOzellik1(0);
        setOzellik2(0);
        setOzellik3(0);
    }


    int getOzellik1() { return _sebestAtis; }
    void setOzellik1(int serbestAtis) { _sebestAtis = serbestAtis; }

    int getOzellik2() { return _ikilik; }
    void setOzellik2(int ikilik) { _ikilik = ikilik; }

    int getOzellik3() { return _ucluk; }
    void setOzellik3(int ucluk) { _ucluk = ucluk; }


private:
    int _sebestAtis;
    int _ikilik;
    int _ucluk;
   

};


#endif // FUTBOLCU_H