#include <iostream>
#include <map>
#include <vector>

// Student krene u prodavnicu sa nekim iznosom novca n i napravi
// račun od m KM. Od kasirke zatraži da mu vrati kusur sa što
// manje novcanica. Za kusur se koriste apoeni od 10, 5, 2 i 1 KM.
// Napisati program koji računa najmanji broj novcanica koje
// student dobije kao kusur.
//
// 100 KM = 10 * 10KM;
// 7   KM = 5 + 2;
//        = 2 + 2 + 2 + 1;

const int apoeni[] = { 10, 5, 2, 1 };

int broj_novcanica(int kusur)
{
  if (kusur == 0)
  {
    return 0;
  }
  int min = 10000000; // kad bi kusur puta vratili 1KM
  for (const auto a : apoeni)
  {
    if (a <= kusur)
    {
      // std::cout << "Racunam kusur " << kusur << " minus " << a << std::endl;
      min = std::min(min, 1 + broj_novcanica(kusur - a));
    }
  }
  return min;
}

int lookup_table[200000];
int broj_novcanica_mem(int kusur)
{
  if (kusur == 0)
  {
    return 0;
  }
  if (lookup_table[kusur] != 0)
  {
    return lookup_table[kusur];
  }
  int min = 10000000; // kad bi kusur puta vratili 1KM
  for (const auto a : apoeni)
  {
    if (a <= kusur)
    {
      min = std::min(min, 1 + broj_novcanica_mem(kusur - a));
    }
  }
  lookup_table[kusur] = min;
  return min;
}

// bez globalne varijable
int broj_novcanica_mem_impl(int kusur, std::vector<int>& lookup_table)
{
  if (kusur == 0)
  {
    return 0;
  }
  if (lookup_table[kusur] != 0)
  {
    return lookup_table[kusur];
  }

  int min = broj_novcanica_mem_impl(kusur - 1, lookup_table);
  for (auto a : apoeni)
  {
    if (kusur >= a)
    {
      min = std::min(1 + broj_novcanica_mem_impl(kusur - a, lookup_table), min);
    }
  }
  lookup_table[kusur] = min;
  return min;
}

int broj_novcanica_mem_1(int kusur)
{
  std::vector<int> table;
  table.resize(kusur + 1);
  return broj_novcanica_mem_impl(kusur, table);
}

int broj_novcanica_din(int kusur)
{
  std::vector<int> table;
  table.resize(kusur + 1);

  table[0] = 0;

  for (int i = 1; i <= kusur; i++)
  {
    int min = 1 + table[i - 1];
    for (auto a : apoeni)
    {
      if (kusur >= a)
      {
        min = std::min(1 + table[i - a], min);
      }
    }
    table[i] = min;
  }
  return table[kusur];
}

int main()
{
  int kusur;
  std::cout << "Unesite kusur: ";
  std::cin >> kusur;
  std::cout << broj_novcanica_din(kusur) << std::endl;
  return 0;
}
