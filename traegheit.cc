#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>

double traegheit(Koerper * k, Vektor a, Vektor u, int Nk, double Mk) {
  double J=0;
  double mk=Mk/Nk;
  std :: cout << " berechne   fuer  " << k-> name () << '\n';
    for (int i = 0; i < Nk; ++i) {
    Vektor x = k->punkt();
    // Abstand Punkt x und Gerade a + t*u
    Vektor n = (x-a).kreuz(u);
    // Vektor n = ...;//Normalenvektor x-a kreuz u
    double r = n.betrag()/u.betrag(); //|n|/|u|
    //std::cout << x << " :" << r << std::endl;
    // addiere Beitrag des Massenpunktes zum Traegheitsmoment
    J += mk * r * r;
  }
  return J;
}
int main() {
  const int N = 10000;     // Anzahl Integrationspunkte
  const double M = 1;      // Masse des Zylindermantels
  const double ZM_R = 1.0; // Radius der Zylindermantels
  const double ZM_L = 1.0; // Laenge des Zylindermantels

  Vektor a; // Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u; // Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;

  std :: unique_ptr < Koerper > k( new Zylindermantel (ZM_R , ZM_L ));
  double Jzm=traegheit(k.get(),a,u,N,M);

  std::cout << "Massentraegheitsmoment fuer einen Zylindermantel"
            << " mit a = " << a << " und u = " << u << ": " << Jzm << std::endl;

  std :: unique_ptr < Koerper > k2( new Vollzylinder (ZM_R , ZM_L ));
  double Jvz=traegheit(k2.get(),a,u,N,M);

  std::cout << "Massentraegheitsmoment fuer einen Vollzylinder"
            << " mit a = " << a << " und u = " << u << ": " << Jvz << std::endl;
  return 0;
}
