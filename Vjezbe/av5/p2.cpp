#include <iostream>
#include <vector>

int count_rek(int sum, int coins[], int n)
{
  if (sum == 0) return 1;
  if (sum < 0) return 0;
  if (n <= 0) return 0;
  return count_rek(sum - coins[n - 1], coins, n) + count_rek(sum, coins, n - 1);
}

int count_mem_impl(int sum, int coins[], int n, int lookup[2000][20])
{
  if (sum == 0) return 1;
  if (sum < 0) return 0;
  if (n <= 0) return 0;
  if (lookup[sum][n] == 0) lookup[sum][n] = count_mem_impl(sum - coins[n - 1], coins, n, lookup) + count_mem_impl(sum, coins, n - 1, lookup);
  return lookup[sum][n];
}

int count_mem(int sum, int coins[], int n)
{
  int lookup[10000][20];
  return count_mem_impl(sum, coins, n, lookup);
}

int count_din(int sum, int coins[], int n)
{
  int lookup[2000][20];

  for (int i = 0; i <= n; ++i)
    lookup[0][i] = 1;
  for (int i = 0; i <= sum; ++i)
    lookup[i][0] = 1;

  for (int i = 1; i <= sum; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      if (i - coins[j - 1] >= 0)
        lookup[i][j] = lookup[i - coins[j - 1]][j] + lookup[i][j - 1];
      else
        lookup[i][j] = lookup[i][j - 1];
    }
  }

  return lookup[sum][n];
}

// geeksforgeeks.org coin-change-dp

int main(int argc, char* argv[])
{
  int sum;

  std::cout << "Unesite iznos: ";
  std::cin >> sum;

  int coins[] = { 1, 2, 5, 10, 20 };
  int n = sizeof(coins) / sizeof(int);

  std::cout << "Razliciti nacini: " << count_rek(sum, coins, n) << std::endl;

  return 0;
}
