#include <algorithm>
#include <iostream>
#include <vector>

int max_sum(int* arr, int n)
{
  std::vector<int> lookup;
  lookup.resize(n);

  lookup[0] = arr[0];

  int max_sum = arr[0];
  int max_sum_begin_index = 0;
  int max_sum_end_index = 0;

  for (int i = 1; i < n; ++i)
  {
    lookup[i] = arr[i];

    if (lookup[i - 1] > 0)
      lookup[i] += lookup[i - 1];
    else
      max_sum_begin_index = i;

    if (lookup[i] > max_sum)
    {
      max_sum = lookup[i];
      max_sum_end_index = i;
    }
  }

  for (int i = max_sum_begin_index; i <= max_sum_end_index; ++i)
    std::cout << arr[i] << " ";
  std::cout << std::endl;

  return max_sum;
}

int main()
{
  int n;
  std::vector<int> vec;
  while (std::cin >> n) vec.push_back(n);

  std::cout << max_sum(vec.data(), vec.size()) << std::endl;

  return 0;
}
