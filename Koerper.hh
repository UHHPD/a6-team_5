#ifndef KOERPER_HH
#define KOERPER_HH

#include "Vektor.hh"
#include <iostream>

class Koerper {
public:
  Koerper(){std::cout << "KO"<< std::endl;}
  virtual Vektor punkt()=0;
  virtual std ::string name() {return "Koerper";}
};

#endif
