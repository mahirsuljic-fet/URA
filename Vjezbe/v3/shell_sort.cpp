#include <array>

void insertion_sort_r(int* a, int n, int r)
{
  for (int i = r; i < n; ++i)
  {
    for (int j = n; j > 0; j -= r)
    {
      if (a[j] < a[j - r])
        std::swap(a[j], a[j - r]);
      else
        break;
    }
  }
}

void shell_sort(int* a, int n)
{
  // pocetna vrijednost za r i korak za r su proizvoljne
  // ali n/2 i dijeljenje sa 2 su se pokazale dobre
  for (int r = n / 2; r >= 1; r /= 2)
    for (int i = 0; i < r; ++i)
      insertion_sort_r(a + i, n - i, r);
}
