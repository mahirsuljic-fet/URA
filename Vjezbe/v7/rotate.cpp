#include <algorithm>
#include <iostream>
#include <vector>

template <typename It>
It rotate(It first, It middle, It last)
{
  if (first == middle) return last;
  if (middle == last) return first;

  It write = first;
  It next_read = first;

  for (It read = middle; read != last; ++write, ++read)
  {
    if (write == next_read) next_read = read;
    std::iter_swap(write, read);
  }

  ::rotate(write, next_read, last);
  return write;
}

int main()
{
  std::vector<int> numbers { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  auto print = [&numbers]() {
    for (const auto& n : numbers)
      std::cout << n << ", ";
    std::cout << std::endl;
  };

  print();
  ::rotate(numbers.begin(), numbers.begin() + 2, numbers.end());
  print();

  return 0;
}
