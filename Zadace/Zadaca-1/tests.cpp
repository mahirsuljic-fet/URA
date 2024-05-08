#include "tests.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <numeric>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

void Test::divide(std::function<int(int, int)> divide, int examples)
{
  std::srand(std::time(NULL));
  for (size_t i = 0; i < examples; ++i)
    divide_example(get_rand(MIN_RAND_A, MAX_RAND_A), get_rand(MIN_RAND_B, MAX_RAND_B), divide);
}

void Test::palindrome(std::function<bool(const char*, int)> palindrome)
{
  std::vector<std::string> palindromes = {
    "racecar",
    "tacocat",
    "mom",
    "testset",
    "aa",
    "evilolive",
    "a",
    "neveroddoreven",
    "murderforajarofredrum",
    "anavolimilovana",
    "drawkward"
  };

  std::vector<std::string> non_palindromes = {
    "test",
    "bigtesttest",
    "notapalindrome",
    "testest",
    "random",
    "burek",
    "algoritam",
    "elektrotehnika",
    "racunarstvo",
    "procesor",
    "palacinak"
  };

  for (int i = 0; i < std::min(palindromes.size(), non_palindromes.size()); ++i)
    palindrome_example(palindrome, palindromes, non_palindromes, i);
}

void Test::sum(std::function<int(const int*, int)> sum, int examples)
{
  std::srand(std::time(NULL));
  for (size_t i = 0; i < examples; ++i)
    sum_example(sum);
}

void Test::push_unique(std::function<bool(std::vector<int>&, int)> push_unique, int examples)
{
  std::srand(std::time(NULL));
  std::vector<int> vec = random_vector();
  remove_duplicates(vec);
  std::cout << "Random vector: ";
  print_vector(vec);
  std::cout << std::endl;

  for (size_t i = 0; i < examples; ++i)
    push_unique_example(push_unique, vec);
}

void Test::upper_bound(std::function<ivec_it(ivec_it, ivec_it, int)> upper_bound, int examples)
{
  std::srand(std::time(NULL));
  std::vector<int> vec = random_vector();
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

  std::cout << "Random vector: ";
  print_vector(vec);
  std::cout << std::endl;

  for (size_t i = 0; i < examples; ++i)
    upper_bound_example(upper_bound, vec);
}

// SINGLE EXAMPLE PRINT FUNCTIONS

void Test::divide_example(int a, int b, std::function<int(int, int)> divide)
{
  try
  {
    std::cout << std::right << std::setw(WIDTH_A) << a << " / " << std::left << std::setw(WIDTH_B) << b << " = ";
    int result = divide(a, b);
    std::cout << std::setw(WIDTH_REZ) << result << (result == a / b ? "(T)" : "(F)") << std::endl;
  }
  catch (const std::exception& err)
  {
    std::cout << err.what() << std::endl;
  }
}

void Test::sum_example(std::function<int(const int*, int)> sum)
{
  constexpr static const int SUM_STR_LEN = 120;
  try
  {
    std::ostringstream oss;
    std::vector<int> arr = random_vector();
    for (auto it = arr.begin(); it < arr.end() - 1; ++it)
      oss << *it << " + ";
    oss << arr.back() << " = ";
    int result = sum(arr.data(), arr.size());
    int std_result = std::accumulate(arr.begin(), arr.end(), 0);
    oss << result;
    std::cout << std::left << std::setw(SUM_STR_LEN) << oss.str() << (result == std_result ? "\t(T)" : "\t(F)") << std::endl;
  }
  catch (const std::exception& err)
  {
    std::cout << err.what() << std::endl;
  }
}

void Test::palindrome_example(std::function<bool(const char*, int)> palindrome, const std::vector<std::string>& palindromes, const std::vector<std::string>& non_palindromes, int i)
{
  static const auto comp = [](std::string lhs, std::string rhs) { return lhs.size() < rhs.size(); };
  static const int max_size_p = std::max_element(palindromes.begin(), palindromes.end(), comp)->size();
  static const int max_size_np = std::max_element(non_palindromes.begin(), non_palindromes.end(), comp)->size();
  static const int STR_W = std::max(max_size_p, max_size_np) + 22;

  try
  {
    std::ostringstream oss;
    bool p_result = palindrome(palindromes[i].c_str(), palindromes[i].size());
    bool np_result = palindrome(non_palindromes[i].c_str(), non_palindromes[i].size());

    oss << palindromes[i] << (p_result ? " is " : " is not ") << "a palindrome.";
    std::cout << std::left << std::setw(STR_W) << oss.str() << (p_result ? "(T)" : "(F)") << std::endl;

    oss.str("");
    oss.clear();

    oss << non_palindromes[i] << (np_result ? " is " : " is not ") << "a palindrome.";
    std::cout << std::left << std::setw(STR_W) << oss.str() << (!np_result ? "(T)" : "(F)") << std::endl;
  }
  catch (const std::exception& err)
  {
    std::cout << err.what() << std::endl;
  }
}

void Test::push_unique_example(std::function<bool(std::vector<int>&, int)> push_unique, std::vector<int>& vec)
{
  try
  {
    int value = get_rand(MIN_ARR_VALUE, MAX_ARR_VALUE);
    if (push_unique(vec, value))
      std::cout << std::setw(WIDTH_REZ) << value << " added to vector" << std::endl;
    else
    {
      std::cout << std::setw(WIDTH_REZ) << value << " is already in vector: ";
      print_vector(vec, value);
    }
  }
  catch (const std::exception& err)
  {
    std::cout << err.what() << std::endl;
  }
}

void Test::upper_bound_example(std::function<ivec_it(ivec_it, ivec_it, int)> upper_bound, std::vector<int>& vec)
{
  try
  {
    int value = get_rand(MIN_ARR_VALUE, MAX_ARR_VALUE);
    auto it = upper_bound(vec.begin(), vec.end(), value);

    std::cout << std::endl;
    std::cout << "Adding " << value << std::endl;
    vec.insert(it, value);
    std::cout << "Correct iterator? " << (std::is_sorted(vec.begin(), vec.end()) ? "(T)" : "(F)") << std::endl;
    print_vector(vec, it);
  }
  catch (const std::exception& err)
  {
    std::cout << err.what() << std::endl;
  }
}

// HELPER FUNCTIONS

int Test::get_rand(int min, int max)
{
  return min + (std::rand() % (max - min + 1));
}

std::vector<int> Test::random_vector()
{
  int size = MIN_ARR_SIZE + (std::rand() % (MAX_ARR_SIZE - MIN_ARR_SIZE + 1));
  std::vector<int> arr(size);
  for (auto& el : arr)
    el = MIN_ARR_VALUE + (std::rand() % (MAX_ARR_VALUE - MIN_ARR_VALUE + 1));
  return arr;
}

void Test::print_vector(const std::vector<int>& vec, std::ostream& out)
{
  for (auto it = vec.begin(); it < vec.end() - 1; ++it)
    out << *it << ", ";
  out << vec.back();
}

void Test::print_vector(const std::vector<int>& vec, int value, std::ostream& out)
{
  for (auto it = vec.begin(); it < vec.end() - 1; ++it)
  {
    if (*it != value)
      out << *it << ", ";
    else
      out << " |" << *it << "|  , ";
  }

  if (vec.back() != value)
    out << vec.back() << std::endl;
  else
    out << " |" << vec.back() << "|";
}

void Test::print_vector(const std::vector<int>& vec, std::vector<int>::iterator highlight, std::ostream& out)
{
  for (auto it = vec.begin(); it < vec.end() - 1; ++it)
  {
    if (it != highlight)
      out << *it << ", ";
    else
      out << " |" << *it << "|  , ";
  }

  if (vec.end() - 1 != highlight)
    out << vec.back() << std::endl;
  else
    out << " |" << vec.back() << "|";
}

void Test::remove_duplicates(std::vector<int>& vec)
{
  for (int i = 0; i < vec.size(); ++i)
    for (int j = i + 1; j < vec.size(); ++j)
      if (vec[i] == vec[j])
        vec.erase(vec.begin() + j);
}
