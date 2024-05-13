#include "../tests.hpp"
#include <functional>
#include <iostream>
#include <vector>

// za vizuelni prikaz algoritma postaviti visual na true
bool visual = false;
constexpr static const int delay = 500;

template <typename It, typename C>
void shellsort(It begin, It end, C comp)
{
  int n = end - begin;
  if (n <= 1) return;

  for (auto k = n / 2; k > 0; k /= 2)
  {
    It current = begin;
    It next = current + k;
    while (next < end)
    {
      if (visual) Test<>::printcd(delay, begin, end, current, "C", next, "N");
      auto mem_step = current;
      while (next < end)
      {
        if (visual) Test<>::printcd(delay, begin, end, current, "C", next, "N", mem_step, "M");
        auto temp = current;
        while (current >= begin && !comp(*current, *next))
        {
          std::swap(*current, *next);
          if (visual) Test<>::printcd(delay, begin, end, current, "C", next, "N");
          current -= k;
          next -= k;
        }

        current = temp + k;
        next = current + k;
      }
      if (k == 1) break;
      current = ++mem_step;
      next = current + k;
    }
  }
}

int main()
{
  Test<>::test(shellsort<std::vector<int>::iterator, std::function<bool(int, int)>>);
  return 0;
}
