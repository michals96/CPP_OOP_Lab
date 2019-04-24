// Nazwa pliku wykonywalnego: Wyjatki

// UWAGA! Nie wolno korzystać ze zmiennych i funkcji statycznych, ani ze
// zmiennych globalnych.

// Prosze zaimplementowac klasy:
// - ObiektMiotajacy
// - typ1
// - typ2
// - typ3
// - typ4
// ObiektMiotajacy musi miec zaimplementowana metoda Rzuc(),
// natomiast klasy od typ1 do typ4 metode PrzedstawSie(), ktora wypisuje
// na ekranie z jakiego typu obiektem mamy do czynienia.

// Funkcja Przetworz i instrukcje w blokach catch(typ3*) i
// catch(typ4*) wypisuja na ekran adres przechowywany we wskazniku
// wyjatek.

// Prosze zwrocic uwage na zarzadzanie pamiecia. Bardzo wazne jest aby
// nie bylo zadnych wyciekow pamieci.

// Pliku Main.cpp, nie wolno modyfikowac.

// Komentarz w kodzie mowia jakie wyjscie powinna generowac dana linia.

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
/* Wynik działania programu:
Wprowadzenie
Nazywam sie 1 (adres obiektu: <adres_obiektu>)
Nazywam sie 2 (adres obiektu: <adres_obiektu>)
Nazywam sie 3 (adres obiektu: <adres_obiektu>)
Nazywam sie 4 (adres obiektu: <adres_obiektu>)
Koniec wprowadzenia
Przetworz - wyjatek typu 1 o adresie: <adres_wyjatku>
Zlapalem wyjatek typu 4 w linii 95. Adres wyjatku: <adres_wyjatku>
___________________________________________________________________
Wynik działania programu z uwzględnieniem  wartości adresów:
Wprowadzenie
Nazywam sie 1 (adres obiektu: 0x7ffea0f4cb0d)
Nazywam sie 2 (adres obiektu: 0x7ffea0f4cb0e)
Nazywam sie 3 (adres obiektu: 0x7ffea0f4cb0f)
Nazywam sie 4 (adres obiektu: 0x7ffea0f4cb10)
Koniec wprowadzenia
Przetworz - wyjatek typu 1 o adresie: 0x559b85b1b330
Zlapalem wyjatek typu 4 w linii 95. Adres wyjatku: 0x559b85b1b330
*/