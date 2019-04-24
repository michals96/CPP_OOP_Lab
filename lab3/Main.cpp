
#include"Main.h"
#include<iostream>
//////////////////////////////////////////////////////////////////////////
//
void Funkcja ()
{
  try {
    ObiektMiotajacy* miotacz = new ObiektMiotajacy;
    miotacz->Rzuc();
    std::cout<<"Ukryty przekaz"<<std::endl;
  }
  catch (typ1* wyjatek)
    {
      Przetworz (wyjatek);  // Przetworz - wyjatek typu 1 o adresie: ....
    }
  catch (typ2* wyjatek)
    {
      Przetworz (wyjatek);  // Przetworz - wyjatek typu 2 o adresie: ....
    }
}

//////////////////////////////////////////////////////////////////////////
//
int main ()
{
  using namespace std;
  
  cout<<"Wprowadzenie\n";
  typ1 a; a.PrzedstawSie(); // Nazywam sie 1
  typ2 b; b.PrzedstawSie(); // Nazywam sie 2
  typ3 c; c.PrzedstawSie(); // Nazywam sie 3
  typ4 d; d.PrzedstawSie(); // Nazywam sie 4
  cout<<"Koniec wprowadzenia\n";

  
  try {
    Funkcja();
    cout<<"Ukryty przekaz"<<endl;
  }
  catch (typ3* wyjatek) {
    cout<<"Zlapalem wyjatek typu 3 w linii "<<__LINE__<<". Adres wyjatku: "<<wyjatek<<endl;
    delete wyjatek;
  }
  catch (typ4* wyjatek) {
    cout<<"Zlapalem wyjatek typu 4 w linii "<<__LINE__<<". Adres wyjatku: "<<wyjatek<<endl;
    delete wyjatek;
  }

  return 0;
}
