#include <iostream>
#include <stdexcept>
#include <vector>

// a(0) = 2
// a(1) = 4
// a(2) = 12
// a(n) = 3*a(n-3) + 2*a(n-2) + a(n-3)    pretpostavljam da je stamparska greska i da zadnja treba biti + a(n-1)

using number = long long;

number simple_rec(number n)
{
  if (n < 0) throw std::invalid_argument("Broj nije validan");
  if (n == 0) return 2;
  if (n == 1) return 4;
  if (n == 2) return 12;
  return 3 * simple_rec(n - 3) + 2 * simple_rec(n - 2) + simple_rec(n - 1);
}

number simple_mem_impl(number n, std::vector<number>& vec)
{
  if (n == 0) return 2;
  if (n == 1) return 4;
  if (n == 2) return 12;
  if (vec[n] == 0) vec[n] = 3 * simple_rec(n - 3) + 2 * simple_rec(n - 2) + simple_rec(n - 1);
  return vec[n];
}

number simple_mem(number n)
{
  if (n < 0) throw std::invalid_argument("Broj nije validan");

  std::vector<number> vec;
  vec.resize(n);

  return 3 * simple_rec(n - 3) + 2 * simple_rec(n - 2) + simple_rec(n - 1);
}

number simple_dp(number n)
{
  if (n < 0) throw std::invalid_argument("Broj nije validan");

  std::vector<number> vec;
  vec.resize(n);

  vec[0] = 2;
  vec[1] = 4;
  vec[2] = 12;

  for (int i = 3; i <= n; ++i)
    vec[i] = 3 * vec[i - 3] + 2 * vec[i - 2] + vec[i - 1];

  return vec[n];
}

int main()
{
  std::cout << simple_rec(10) << std::endl;
  std::cout << simple_mem(10) << std::endl;
  std::cout << simple_dp(10) << std::endl;
  return 0;
}
