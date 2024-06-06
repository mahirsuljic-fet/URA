#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int lps(std::string str)
{
  std::string reverse_str = str;
  std::reverse(reverse_str.begin(), reverse_str.end());

  std::vector<int> current(reverse_str.length() + 1, 0);
  std::vector<int> previous(reverse_str.length() + 1, 0);

  for (int i = 1; i <= str.length(); i++)
  {
    for (int j = 1; j <= reverse_str.length(); j++)
    {
      if (str[i - 1] == reverse_str[j - 1])
        current[j] = 1 + previous[j - 1];
      else
        current[j] = std::max(current[j - 1], previous[j]);
    }

    previous = current;
  }

  return current[reverse_str.length()];
}

int main()
{
  std::string str;
  std::cin >> str;
  std::cout << lps(str) << std::endl;
  return 0;
}
