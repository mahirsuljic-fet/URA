#pragma once

#include <chrono>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <thread>
#include <vector>

template <typename It = std::vector<int>::iterator>
class Test
{
  private:
    using it_str_pair = std::pair<It, std::string>;
    using milis = std::chrono::milliseconds;

    static inline std::vector<it_str_pair> pairs_;
    static inline It last_begin_;

    constexpr static const int DEFAULT_W = 4;
    constexpr static const char* DEFAULT_EMPTY = ".";
    constexpr static const size_t MIN_ARR_SIZE = 1;
    constexpr static const size_t MAX_ARR_SIZE = 20;
    constexpr static const int MIN_ARR_VALUE = -100;
    constexpr static const int MAX_ARR_VALUE = 100;

    static int get_rand(int min, int max);

  public:
    constexpr static const size_t DEFAULT_DELAY = 250;

    static std::vector<int> random_vector();
    template <typename F>
    static void test(F sort);
    static bool check_sorted(It begin, It end);
    template <typename C>
    static bool check_sorted(It begin, It end, C comp);
    template <typename C>
    static void print_check(It begin, It end, C comp, int w = DEFAULT_W);
    static void print(It begin, It end, int w = DEFAULT_W, const std::string& empty_str = DEFAULT_EMPTY);
    static void print(It begin, It end, It it, const std::string& text = "^", int w = DEFAULT_W, const std::string& empty_str = DEFAULT_EMPTY);
    template <typename... T>
    static void print(It begin, It end, It it, const std::string& text, const T&... other);
    static void print(std::ostream& out, It begin, It end, int w = DEFAULT_W, const std::string& empty_str = DEFAULT_EMPTY);
    static void print(std::ostream& out, It begin, It end, It it, const std::string& text = "^", int w = DEFAULT_W, const std::string& empty_str = DEFAULT_EMPTY);
    template <typename... T>
    static void print(std::ostream& out, It begin, It end, It it, const std::string& text, const T&... other);
    template <typename... T>
    static void printcd(const T&... other);
    template <typename... T>
    static void printcd(int delay, const T&... other);
};

template <typename It>
template <typename F>
void Test<It>::test(F sort)
{
  auto vec = Test<>::random_vector();
  auto vec_copy = vec;
  auto comp_l = [](int lhs, int rhs) { return lhs < rhs; };
  auto comp_g = [](int lhs, int rhs) { return lhs > rhs; };

  std::cout << "Original:  ";
  Test<>::print(vec.begin(), vec.end());

  sort(vec.begin(), vec.end(), comp_l);

  std::cout << "Sort asc:  ";
  Test<>::print_check(vec.begin(), vec.end(), comp_l);

  sort(vec_copy.begin(), vec_copy.end(), comp_g);

  std::cout << "Sort desc: ";
  Test<>::print_check(vec_copy.begin(), vec_copy.end(), comp_g);
}

template <typename It>
template <typename C>
void Test<It>::print_check(It begin, It end, C comp, int w)
{
  for (It it = begin; it != end; ++it)
    std::cout << std::setw(w) << *it;
  std::cout << (Test<>::check_sorted(begin, end, comp) ? "\t(T)" : "\t(F)") << std::endl;

  last_begin_ = It {};
  pairs_.clear();
}

template <typename It>
void Test<It>::print(It begin, It end, int w, const std::string& empty_str)
{
  for (It it = begin; it != end; ++it)
    std::cout << std::setw(w) << *it;
  std::cout << std::endl;

  if (begin == last_begin_ && pairs_.size())
  {
    for (It it = begin; it != end; ++it)
    {
      bool printed = false;
      for (const auto& pair : pairs_)
      {
        if (it == pair.first)
        {
          std::cout << std::setw(w) << pair.second;
          printed = true;
          break;
        }
      }
      if (!printed)
        std::cout << std::setw(w) << empty_str;
    }
    std::cout << std::endl;
  }

  last_begin_ = It {};
  pairs_.clear();
}

template <typename It>
void Test<It>::print(It begin, It end, It it, const std::string& text, int w, const std::string& empty_str)
{
  pairs_.push_back({ it, text });
  last_begin_ = begin;
  print(begin, end, w, empty_str);
}

template <typename It>
template <typename... T>
void Test<It>::print(It begin, It end, It it, const std::string& text, const T&... other)
{
  pairs_.push_back({ it, text });
  last_begin_ = begin;
  print(begin, end, other...);
}

template <typename It>
void Test<It>::print(std::ostream& out, It begin, It end, int w, const std::string& empty_str)
{
  for (It it = begin; it != end; ++it)
    out << std::setw(w) << *it;
  out << std::endl;

  if (begin == last_begin_ && pairs_.size())
  {
    for (It it = begin; it != end; ++it)
    {
      bool printed = false;
      for (const auto& pair : pairs_)
      {
        if (it == pair.first)
        {
          out << std::setw(w) << pair.second;
          printed = true;
          break;
        }
      }
      if (!printed)
        out << std::setw(w) << empty_str;
    }
    out << std::endl;
  }

  last_begin_ = It {};
  pairs_.clear();
}

template <typename It>
void Test<It>::print(std::ostream& out, It begin, It end, It it, const std::string& text, int w, const std::string& empty_str)
{
  pairs_.push_back({ it, text });
  last_begin_ = begin;
  print(out, begin, end, w, empty_str);
}

template <typename It>
template <typename... T>
void Test<It>::print(std::ostream& out, It begin, It end, It it, const std::string& text, const T&... other)
{
  pairs_.push_back({ it, text });
  last_begin_ = begin;
  print(out, begin, end, other...);
}

template <typename It>
template <typename... T>
void Test<It>::printcd(const T&... other)
{
  std::system("clear");
  print(other...);
  std::this_thread::sleep_for(milis(DEFAULT_DELAY));
}

template <typename It>
template <typename... T>
void Test<It>::printcd(int delay, const T&... other)
{
  std::system("clear");
  print(other...);
  std::this_thread::sleep_for(milis(delay));
}

template <typename It>
bool Test<It>::check_sorted(It begin, It end)
{
  It current = begin;
  It previous = current++;
  while (current != end)
    if (*current++ < *previous++)
      return false;
  return true;
}

template <typename It>
template <typename C>
bool Test<It>::check_sorted(It begin, It end, C comp)
{
  It current = begin;
  It previous = current++;
  while (current != end)
    if (comp(*current++, *previous++))
      return false;
  return true;
}
