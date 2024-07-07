#include <iostream>
#include <string>

// Printati sve binarne brojeve duzine n koji imaju tri jedinice u
// svom zapisu.

void print_binary(std::string& binary, int n, int broj_jedinica)
{
  if (binary.size() == n)
  {
    if (broj_jedinica == 3)
      std::cout << binary << std::endl;
    return;
  }
  binary.push_back('0');
  print_binary(binary, n, broj_jedinica);
  binary.pop_back();
  if (broj_jedinica < 3)
  {
    binary.push_back('1');
    print_binary(binary, n, broj_jedinica + 1);
    binary.pop_back();
  }
}

int main()
{
  int n = 8;
  std::string bin;
  print_binary(bin, 8, 0);
}
