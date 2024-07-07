#include <iostream>
#include <map>
#include <vector>

// sum = 4, coins = [1,2,3]
// razliciti nacini su: {1,1,1,1}, {1,1,2}, {2,2}, {1,3}
// odgovor: 4

// sum = 10, coins = [2, 5, 3, 6]
// nacini: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
// odgovor: 5

int count_rek1(int sum, int coins[], int n)
{
  // Bazni slucajevi:
  if (sum == 0)
    return 1;
  if (sum < 0)
    return 0;
  if (n <= 0)
    return 0;
  return count_rek1(sum - coins[n - 1], coins, n)
    + count_rek1(sum, coins, n - 1);
}

int count_rek_impl(int sum, int coins[], int n, int lookup[2000][20])
{
  // Bazni slucajevi:
  if (sum == 0)
    return 1;
  if (sum < 0)
    return 0;
  if (n <= 0)
    return 0;
  if (lookup[sum][n] == 0)
  {
    lookup[sum][n] = count_rek_impl(sum - coins[n - 1], coins, n, lookup)
      + count_rek_impl(sum, coins, n - 1, lookup);
  }
  return lookup[sum][n];
}

int count_rek(int sum, int coins[], int n)
{
  int lookup[2000][20];
  return count_rek_impl(sum, coins, n, lookup);
}

int count_din(int sum, int coins[], int n)
{
  int lookup[2000][20];
  for (int i = 0; i <= n; i++)
  {
    lookup[0][i] = 1;
  }
  for (int i = 0; i <= sum; i++)
  {
    lookup[i][0] = 0;
  }
  for (int i = 1; i <= sum; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i - coins[j - 1] >= 0)
        lookup[i][j] = lookup[i - coins[j - 1]][j] + lookup[i][j - 1];
      else
        lookup[i][j] = lookup[i][j - 1];
    }
  }
  return lookup[sum][n];
}

int main()
{
  int sum;
  std::cout << "Unesite iznos (max 2000): ";
  std::cin >> sum;
  int coins[] = { 1, 2, 5, 10, 20 };
  int n = sizeof(coins) / sizeof(int);
  std::cout << "Razlicini nacini: " << count_din(sum, coins, n) << std::endl;
  return 0;
}
