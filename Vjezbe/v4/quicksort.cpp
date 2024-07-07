#include <algorithm>
#include <vector>

template <typename It>
void quicksort(It begin, It end)
{
  auto n = end - begin;
  if (n <= 1) return;

  auto& last = *(end - 1);

  // ako zelimo odabrat element iz sredine
  // auto middle = begin + n / 2;
  // std::swap(*middle, last);

  auto it = std::partition(begin, end - 1, [&last](const auto& elem) { return elem < last; });
  std::swap(*it, last);

  // ne moramo ukljuciti it jer je on vec na svom mjestu
  quicksort(begin, it); // ovaj poziv ne ukljucuje it
  quicksort(it + 1, end);
}
