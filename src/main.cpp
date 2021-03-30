#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"


int main(int argc, char **argv)
{

  if (argc < 2) {
    std::cout << std::endl;
    std::cout << " Brak opcji okreslajacej rodzaj testu." << std::endl;
    std::cout << " Dopuszczalne nazwy to:  latwy, trudny." << std::endl;
    std::cout << std::endl;
    return 1;
  }

  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    std::cerr << " Inicjalizacja testu nie powiodla sie." << std::endl;
    return 1;
  }

  std::cout << std::endl;
  std::cout << "Start testu arytmetyki zespolonej: " << argv[1] << std::endl;
  std::cout << std::endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona popr_odpowiedz;
  LZespolona odpowiedz;
  Statystyka stat;

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    std::cout << WyrZ_PytanieTestowe << std::endl;

    try
    {
    popr_odpowiedz = Oblicz(WyrZ_PytanieTestowe);
    }

    catch (std::runtime_error& e)
    {  
      std::cout << "Pojawil sie wyjatek." << std::endl << e.what();
      std::cout << std::endl;
      break;
    }

    int proby = 3;
    while(proby != 0)
    {
      std::cout << std::endl << "Podaj wynik dzialania: ";
      std::cin >> odpowiedz;
      std::cout << std::endl;
      if(!std::cin.good())
      {
        if(proby > 1)
        {
          std::cout << "Niepoprawny format liczby zespolonej. Odpowiedzi podawaj w formacie: (A+Bi)" << std::endl;
        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        proby--;
      }
      else
      {
        if(odpowiedz == popr_odpowiedz)
        {
          std::cout << "Odpowiedz poprawna." << std::endl;
          std::cout << std::endl;
          stat.poprawne++;
          stat.ilosc++;
          break;
        }
        else if((odpowiedz != popr_odpowiedz) && (std::cin.good()))
        {
          std::cout << "Udzielona odpowiedz jest niepoprawna." << std::endl;
          std::cout << "Poprawna odpowiedz to: " << popr_odpowiedz << std::endl;
          std::cout << std::endl;
          stat.niepoprawne++;
          stat.ilosc++;
          break;
        }
      } 
      if(proby == 0)
      {
      std::cout << "Wykorzystales wszystkie proby. Odpowiedz zostaje uznana za niepoprawna." << std::endl; 
      stat.niepoprawne++;
      stat.ilosc++;
      }
      std::cout << std::endl;
    } 
  }
  
  std::cout << std::endl;
  Statystyki(stat.poprawne, stat.niepoprawne, stat.ilosc);
  std::cout << std::endl;
  std::cout << "Koniec testu" << std::endl;
  std::cout << std::endl;
}
