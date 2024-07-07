#include <iostream>
#include <string>

// Naci jedan broj koji ma sve binarne brojeve duzine n koji imaju tri jedinice
// u svom zapisu.

bool print_binary(std::string& binary, int n, int broj_jedinica)
{
  if (binary.size() == n)
  {
    // ako je tacno 3 jedinice
    if (broj_jedinica == 3)
    {
      std::cout << binary << std::endl;
      return true;
    }
    return false;
  }

  binary.push_back('0');
  if (print_binary(binary, n, broj_jedinica))
  {
    return true;
  }
  binary.pop_back();

  if (broj_jedinica < 3)
  {
    binary.push_back('1');
    if (print_binary(binary, n, broj_jedinica + 1))
      return true;
    binary.pop_back();
  }
  return false;
}

int main()
{
  int n = 8;
  std::string bin;
  print_binary(bin, 8, 0);
}
