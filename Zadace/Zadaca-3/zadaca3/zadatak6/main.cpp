#include <cstring>
#include <iostream>
#include <stdexcept>

void kockica(int n, int S)
{
  constexpr static const int MAX_THROW_VALUE = 6;

  if (n < 0) throw std::invalid_argument("Broj bacanja nije validan");
  if (S < n) throw std::invalid_argument("Suma nije validna");

  if (n == 1)
  {
    for (int i = 1; i <= S && i < MAX_THROW_VALUE; ++i)
      std::cout << i << std::endl;
    return;
  }

  int row_sum = n;
  int current_row[n];
  for (int i = 0; i < n; ++i) current_row[i] = 1;

  const auto print_row = [&current_row, n]() {
    for (int i = 0; i < n; ++i)
      std::cout << current_row[i] << " ";
    std::cout << std::endl;
  };

  while (current_row[0] <= MAX_THROW_VALUE)
  {
    int j = n - 1;

    if (row_sum <= S)
    {
      print_row();
      ++current_row[n - 1];
      ++row_sum;
    }
    else
    {
      row_sum = row_sum - current_row[n - 1] + 2;
      current_row[n - 1] = 1;
      ++current_row[n - 2];
      j = n - 2;
    }

    while (current_row[j] > MAX_THROW_VALUE && j > 0)
    {
      row_sum = row_sum - current_row[j] + 2;
      current_row[j--] = 1;
      ++current_row[j];
    }
  }
}

int main()
{
  int n, S;

  std::cout << "Unesite broj bacanja: ";
  std::cin >> n;

  std::cout << "Unesite najvecu dozvoljenu sumu bacanja: ";
  std::cin >> S;

  std::cout << std::endl;

  kockica(n, S);

  return 0;
}
