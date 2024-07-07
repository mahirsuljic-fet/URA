#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

template <typename It>
void quicksort(It begin, It end)
{
  auto n = end - begin;
  if (n <= 1)
    return;
  auto& last = *(end - 1);
  auto middle = begin + n / 2;
  std::swap(*middle, last);
  auto it = partition(begin, end - 1,
    [&](const auto& elem) { return elem <= last; });
  std::swap(*it, last);
  quicksort(begin, it);
  quicksort(it + 1, end);
}

template <typename It>
void mergesort(It begin, It end)
{
  auto n = end - begin;
  if (n <= 1)
    return;

  It middle = begin + n / 2;

  mergesort(begin, middle);
  mergesort(middle, end);

  std::vector<typename It::value_type> temp;

  auto l_begin = begin;
  auto l_end = middle;
  auto r_begin = middle;
  auto r_end = end;

  while (l_begin != l_end || r_begin != r_end)
  {
    if (r_begin == r_end)
    {
      temp.push_back(*l_begin++);
    }
    else if (l_begin == l_end)
    {
      temp.push_back(*r_begin++);
    }
    else if (*l_begin <= *r_begin)
    {
      temp.push_back(*l_begin++);
    }
    else
    {
      temp.push_back(*r_begin++);
    }
  }

  std::copy(temp.begin(), temp.end(), begin);
}

int main(int argc, char* argv[])
{
  std::vector<int> v;
  for (int i = 0; i < 20; i++)
  {
    v.push_back(i);
  }

  std::random_shuffle(v.begin(), v.end());
  for (int i = 0; i < 20; i++)
  {
    std::cout << v[i] << ", ";
  }
  std::cout << std::endl;
  mergesort(v.begin(), v.end());
  for (int i = 0; i < 20; i++)
  {
    std::cout << v[i] << ", ";
  }
  std::cout << std::endl;

  std::random_shuffle(v.begin(), v.end());
  for (int i = 0; i < 20; i++)
  {
    std::cout << v[i] << ", ";
  }
  std::cout << std::endl;
  quicksort(v.begin(), v.end());
  for (int i = 0; i < 20; i++)
  {
    std::cout << v[i] << ", ";
  }
  std::cout << std::endl;
}
