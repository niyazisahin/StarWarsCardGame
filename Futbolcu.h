#ifndef FUTBOLCU_H
#define FUTBOLCU_H
#include "Sporcu.h"

using namespace std;

class Futbolcu : public Sporcu {
    typedef Sporcu super;

public:


    Futbolcu(string futbolcuAdi, string futbolcuTakim, int x, int y, int z)
        : super(futbolcuAdi, futbolcuTakim)
    {
        setOzellik1(x);
        setOzellik2(y);
        setOzellik3(z);
    }

    Futbolcu()
        : super("KAYINCO", "DEREBOYU")
    {
        setOzellik1(0);
        setOzellik2(0);
        setOzellik3(0);
    }


    int getOzellik1() { return _penalti; }
    void setOzellik1(int penalti) { _penalti = penalti; }

    int getOzellik2() { return _serbestVurus; }
    void setOzellik2(int serbestVurus) { _serbestVurus = serbestVurus; }

    int getOzellik3() { return _karsiKarsiya; }
    void setOzellik3(int karsiKarsiya) { _karsiKarsiya = karsiKarsiya; }
    void SporcuPuaniGoster() {
        
    }
    
private:
    int _penalti;
    int _serbestVurus;
    int _karsiKarsiya;

    int baban = 125125;
};


#endif // FUTBOLCU_H
/*
class test{

    sporcu kartlar[16];

    Futbolcu drogba("Drogba", "TürkiyeSpor");
    drogba.penalti = 85;
    ...
    kartlar[0] = drogba;

};
*/