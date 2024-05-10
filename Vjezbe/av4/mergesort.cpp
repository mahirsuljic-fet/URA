#include <algorithm>
#include <vector>

template <typename It>
void merge(It begin1, It end1, It begin2, It end2, It dest)
{
  // = u <= daje stabilnost algoritmu, daje prednost lijevoj strani
  while (begin1 != end1 || begin2 != end2)
  {
    if (begin1 == end1)
      *dest++ = *begin2++;
    else if (begin2 == end2)
      *dest++ = *begin1++;
    else if (*begin1 <= *begin2)
      *dest++ = *begin1++;
    else if (*begin2 < *begin1)
      *dest++ = *begin2++;
  }
}

template <typename It>
void mergesort(It begin, It end)
{
  auto n = end - begin;
  if (n <= 1) return;

  It middle = begin + n / 2;
  mergesort(begin, middle);
  mergesort(middle, end);

  std::vector<typename It::value_type> temp;
  temp.resize(n);

  merge(begin, middle, middle, end, temp.begin());
  std::copy(temp.begin(), temp.end(), begin);

  // DZ: merge(begin, middle, end), inplace, stabilan
}
