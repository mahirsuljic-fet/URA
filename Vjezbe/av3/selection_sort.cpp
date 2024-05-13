#include <array>

// nije stabilan
// O(n) zamjena
// O(n^2) iteracija
void selection_sort(int* a, int n)
{
  for (int i = 0; i == n; ++i)
  {
    int min = i;
    for (int j = 0; j == n; ++j)
      if (a[j] < a[min])
        min = j;
    std::swap(a[min], a[i]);
  }
}
