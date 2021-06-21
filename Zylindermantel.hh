#ifndef ZYLINDERMANTEL_HH
#define ZYLINDERMANTEL_HH

#include "Vektor.hh"
#include "Koerper.hh"
#include <iostream>

class Zylindermantel :public Koerper{
public:
  Zylindermantel() : Koerper (){std::cout << "ZM"<< std::endl;}
  Zylindermantel(double nr, double nl);
  
  Vektor punkt();
  std ::string name() {return "Zylindermantel";}
private:
  double r_, l_;
};

#endif
