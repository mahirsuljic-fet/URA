#include "../tests.hpp"
#include <functional>
#include <vector>

// za vizuelni prikaz algoritma postaviti visual na true
bool visual = false;
constexpr static const int delay = Test<>::DEFAULT_DELAY;

template <typename It, typename C>
void insertionsort(It begin, It end, C comp)
{
  It current = begin;
  It previous = current++;

  while (current != end)
  {
    if (visual) Test<>::printcd(begin, end, current, "C");
    if (comp(*current, *previous))
    {
      It temp = current;
      while (current != begin && comp(*current, *previous))
      {
        std::swap(*current, *previous);
        if (visual) Test<>::printcd(begin, end, current, "C", temp, "T");
        current = previous--;
        if (visual) Test<>::printcd(begin, end, current, "C", temp, "T");
      }
      current = temp;
    }
    previous = current++;
  }
}

int main()
{
  Test<>::test(insertionsort<std::vector<int>::iterator, std::function<bool(int, int)>>);
  return 0;
}
