#include <iostream>
#include <vector>

int lis(int arr[], int n)
{
  int lis[n];
  int longest = 0;

  lis[0] = 1;
  for (int i = 1; i < n; i++)
  {
    lis[i] = 1;
    for (int j = 0; j < i; j++)
      if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
        lis[i] = lis[j] + 1;

    if (lis[i] > longest) longest = lis[i];
  }

  return longest;
}

int main()
{
  int n;
  std::vector<int> vec;
  while (std::cin >> n) vec.push_back(n);

  std::cout << lis(vec.data(), vec.size()) << std::endl;

  return 0;
}
