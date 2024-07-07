#include <algorithm>
#include <iostream>
#include <vector>

template <class It>
It rotate(It first, It middle, It last)
{
  if (first == middle)
    return last;
  if (middle == last)
    return first;
  It write = first;
  It next_read = first;
  for (It read = middle; read != last; ++write, ++read)
  {
    if (write == next_read)
      next_read = read; // track where “first” went
    std::iter_swap(write, read);
  }
  // rotate the remaining sequence into place
  ::rotate(write, next_read, last);
  return write;
}

int main()
{
  std::vector<int> numbers { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  auto print = [&numbers]() {
    for (auto n : numbers)
      std::cout << n << ' ';
    std::cout << std::endl;
  };
  print();
  ::rotate(numbers.begin(), numbers.begin() + 3, numbers.end() - 1);
  print();

  return 0;
}
