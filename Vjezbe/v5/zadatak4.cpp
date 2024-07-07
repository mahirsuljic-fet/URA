#include <iostream>
#include <vector>

int max_podniz(int do_sad_sabrano, int index, std::vector<int>& niz)
{
  if (index == -1)
  {
    return do_sad_sabrano;
  }

  auto max1 = std::max(do_sad_sabrano,
    max_podniz(do_sad_sabrano + niz[index], index - 1, niz));
  return std::max(max1, max_podniz(niz[index], index - 1, niz));
}

int max_podniz_1(int index, std::vector<int>& niz)
{
  std::vector<int> tabela;
  tabela.resize(index + 1);
  tabela[0] = niz[0];

  int do_sad_sabrano = 0;

  for (int i = 1; i <= index; i++)
  {
    // sredit
    tabela[i] = std::max(niz[i], tabela[i - 1] + niz[i]);
  }

  return tabela[index];
}

int main()
{
  std::vector<int> niz { 5, -4, 7, 2, -12, 6, -2, 5, 6, -1, -13, 7, 2 };
  // std::vector<int> niz{10, -200, 7};
  std::cout << max_podniz(0, niz.size() - 1, niz) << std::endl;
}
