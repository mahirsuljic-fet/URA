#include "../tests.hpp"
#include <functional>
#include <vector>

// za vizuelni prikaz algoritma postaviti visual na true
bool visual = false;
constexpr static const int delay = 100;

template <typename It, typename C>
void bubblesort(It begin, It end, C comp)
{
  bool sorted = false;
  while (!sorted)
  {
    sorted = true;
    It current = begin;
    It previous = current++;
    while (current != end)
    {
      if (!comp(*previous, *current) && *previous != *current)
      {
        if (visual) Test<>::printcd(delay, begin, end, current, "C", previous, "P");
        std::swap(*previous, *current);
        if (visual) Test<>::printcd(delay, begin, end, current, "C", previous, "P");
        sorted = false;
      }
      previous = current++;
    }
  }
}

int main()
{
  Test<>::test(bubblesort<std::vector<int>::iterator, std::function<bool(int, int)>>);
  return 0;
}
