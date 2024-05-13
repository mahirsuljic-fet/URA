#include "../tests.hpp"
#include <functional>
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
    auto current = begin + k;
    auto previous = begin;
    while (current < end)
    {
      if (visual) Test<>::printcd(delay, begin, end, current, "C", previous, "P");
      auto temp = current;
      while (previous >= begin && !comp(*previous, *current))
      {
        std::swap(*previous, *current);
        if (visual) Test<>::printcd(delay, begin, end, current, "C", previous, "P", temp, "T");

        current = previous;
        previous -= k;
      }
      previous = current = temp;
      current += k;
    }
  }
}

int main()
{
  Test<>::test(shellsort<std::vector<int>::iterator, std::function<bool(int, int)>>);
  return 0;
}
