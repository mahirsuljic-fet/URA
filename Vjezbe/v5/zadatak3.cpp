#include <cstring>
#include <iostream>

// Input: S1 = “AGGTAB”, S2 = “GXTXAYB”
// Output: 4
// Explanation: The longest subsequence which is present in both strings is
// “GTAB”.

// Input: S1 = “ABCDGH”, S2 = “AEDFHR”
// Output: 3
// Explanation: The longest subsequence which is present in both strings is
// “ADH”.

int longest_common_subsequence_r(const char* a, const char* b, int na, int nb)
{
  if (na == 0)
    return 0;
  if (nb == 0)
    return 0;

  if (a[na - 1] == b[nb - 1])
  {
    return 1 + longest_common_subsequence_r(a, b, na - 1, nb - 1);
  }
  else
  {
    return std::max(longest_common_subsequence_r(a, b, na, nb - 1),
      longest_common_subsequence_r(a, b, na - 1, nb));
  }
}

int lookup[100][100];
int longest_common_subsequence_m(const char* a, const char* b, int na, int nb)
{
  if (na == 0)
    return 0;
  if (nb == 0)
    return 0;

  if (lookup[na - 1][nb - 1] == 0)
  {
    if (a[na - 1] == b[nb - 1])
    {
      lookup[na - 1][nb - 1]
        = 1 + longest_common_subsequence_m(a, b, na - 1, nb - 1);
    }
    else
    {
      lookup[na - 1][nb - 1]
        = std::max(longest_common_subsequence_m(a, b, na, nb - 1),
          longest_common_subsequence_m(a, b, na - 1, nb));
    }
  }
  return lookup[na - 1][nb - 1];
}
int longest_common_subsequence_d(const char* a, const char* b, int na, int nb)
{
  int lookup[na + 1][nb + 1];

  for (int i = 0; i <= na; i++)
  {
    lookup[i][0] = 0;
  }
  for (int i = 0; i <= nb; i++)
  {
    lookup[0][i] = 0;
  }

  for (int i = 1; i <= na; i++)
  {
    for (int j = 1; j <= nb; j++)
    {
      if (a[i - 1] == b[j - 1])
      {
        lookup[i][j] = 1 + lookup[i - 1][j - 1];
      }
      else
      {
        lookup[i][j] = std::max(lookup[i][j - 1], lookup[i - 1][j]);
      }
    }
  }

  return lookup[na][nb];
}

int main(int argc, char* argv[])
{
  std::string a = "AGGTAB";
  std::string b = "GXTXAYB";
  std::cout << longest_common_subsequence_d(a.c_str(), b.c_str(), a.size(),
    b.size())
            << std::endl;
  return 0;
}
