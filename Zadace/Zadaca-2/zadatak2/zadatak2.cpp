#include "../tests.hpp"
#include <functional>
#include <vector>

// za vizuelni prikaz algoritma postaviti visual na true
bool visual = false;
constexpr static const int delay = Test<>::DEFAULT_DELAY;

template <typename It, typename C>
void selectionsort(It begin, It end, C comp)
{
  for (It it_l = begin; it_l != end; ++it_l)
  {
    It it_r = it_l;
    It smallest = it_r;
    while (it_r != end)
    {
      if (visual) Test<>::printcd(begin, end, it_l, "L", smallest, "S", it_r, "R");
      if (comp(*it_r, *smallest))
        smallest = it_r;
      ++it_r;
    }
    if (visual) Test<>::printcd(begin, end, it_l, "L", smallest, "S", it_r, "R");
    std::swap(*it_l, *smallest);
    if (visual) Test<>::printcd(begin, end, it_l, "L", smallest, "S", it_r, "R");
  }
}

int main()
{
  Test<>::test(selectionsort<std::vector<int>::iterator, std::function<bool(int, int)>>);
  return 0;
}
