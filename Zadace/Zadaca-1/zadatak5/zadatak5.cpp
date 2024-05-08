#include "../tests.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using bint = boost::multiprecision::cpp_int;

bint prod_even(int n)
{
  if (n <= 1) return 0;
  if (n <= 3) return 2;
  if (n % 2 == 0)
    return n * prod_even(n - 2);
  else
    return (n - 1) * prod_even(n - 3);
}

int main()
{
  Test::prod_even<bint>(prod_even);
  return 0;
}
