
// stabilan
// O(n^2) slozenost
void insertion_sort(int* a, int n)
{
  for (int i = 1; i < n; ++i)
  {
    for (int j = n; j > 0; --j)
    {
      if (a[j] < a[j - 1])
        std::swap(a[j], a[j - 1]);
      else
        break;
    }
  }
}
