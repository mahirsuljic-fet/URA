#include <iostream>

// ako kompjuter zna samo inkrementovat ili dekrementovat broj
int sum(int n, int a)
{
  if (a == 0) return n;
  return sum(++n, --a);
}

int main()
{
  std::cout << "5 + 3 = " << sum(5, 3) << std::endl;
  std::cout << "10 + 100 = " << sum(10, 100) << std::endl;

  return 0;
}
