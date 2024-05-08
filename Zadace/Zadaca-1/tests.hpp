#pragma once

#include <boost/multiprecision/cpp_int.hpp>
#include <cstddef>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

class Test
{
    using ivec_it = std::vector<int>::iterator;

  public:
    static void divide(std::function<int(int, int)> divide, int examples = 20);
    static void palindrome(std::function<bool(const char*, int)> palindrome);
    static void sum(std::function<int(const int*, int)> sum, int examples = 20);
    static void push_unique(std::function<bool(std::vector<int>&, int)> push_unique, int examples = 30);
    static void upper_bound(std::function<ivec_it(ivec_it, ivec_it, int)> upper_bound, int examples = 20);

    template <typename T, typename F>
    static void prod_even(F prod_even, int examples = 10)
    {
      std::srand(std::time(NULL));
      for (int i = 0; i < examples; ++i)
      {
        try
        {
          int n = get_rand(1, MAX_RAND_P);
          T result = prod_even(n);
          std::cout << "Proizvod parnih prirodnih brojeva do " << std::left << std::setw(2) << n << " je " << std::setw(85) << result << (result == check_prod<T>(n) ? " (T)" : " (F)") << std::endl;
        }
        catch (const std::exception& err)
        {
          std::cout << err.what() << std::endl;
        }
      }
    }

    template <typename T, typename F>
    static void partition(F partition, int examples = 5)
    {
      std::srand(std::time(NULL));
      for (size_t i = 0; i < examples; ++i)
        partition_example<T>(partition);
    }

    template <typename T, typename F>
    static void stable_partition(F partition, int examples = 5)
    {
      std::srand(std::time(NULL));
      for (size_t i = 0; i < examples; ++i)
        stable_partition_example<T>(partition);
    }

  private:
    constexpr static const int WIDTH_A = 5;
    constexpr static const int WIDTH_B = 3;
    constexpr static const int WIDTH_REZ = 5;
    constexpr static const int MIN_RAND_A = -100;
    constexpr static const int MAX_RAND_A = 200;
    constexpr static const int MIN_RAND_B = -20;
    constexpr static const int MAX_RAND_B = 30;
    constexpr static const int MAX_RAND_P = 100;
    constexpr static const int MIN_ARR_VALUE = -100;
    constexpr static const int MAX_ARR_VALUE = 100;
    constexpr static const size_t MIN_ARR_SIZE = 1;
    constexpr static const size_t MAX_ARR_SIZE = 20;

    static int get_rand(int min, int max);
    static std::vector<int> random_vector();
    static void remove_duplicates(std::vector<int>& vec);
    static void print_vector(const std::vector<int>& vec, std::ostream& out = std::cout);
    static void print_vector(const std::vector<int>& vec, int value, std::ostream& out = std::cout);
    static void print_vector(const std::vector<int>& vec, std::vector<int>::iterator highlight, std::ostream& out = std::cout);

    static void divide_example(int a, int b, std::function<int(int, int)> divide);
    static void sum_example(std::function<int(const int*, int)> sum);
    static void palindrome_example(std::function<bool(const char*, int)> palindrome, const std::vector<std::string>& palindromes, const std::vector<std::string>& non_palindromes, int i);
    static void push_unique_example(std::function<bool(std::vector<int>&, int)> push_unique, std::vector<int>& vec);
    static void upper_bound_example(std::function<ivec_it(ivec_it, ivec_it, int)> upper_bound, std::vector<int>& vec);

    template <typename T>
    static T check_prod(int n)
    {
      if (n <= 1) return 0;
      T result = 1;
      for (T i = 2; i <= n; i += 2)
        result *= i;
      return result;
    }

    template <typename Iter, typename P>
    static bool partition_validation(Iter begin, Iter seperator, const P& p)
    {
      while (begin != seperator)
      {
        if (!p(*begin))
          return false;
        ++begin;
      }
      return true;
    }

    template <typename Iter, typename P, typename F>
    static bool stable_partition_validation(F stable_partition, Iter begin, Iter seperator, Iter end, const P& p)
    {
      return true;
      using type = decltype(*begin);
      struct S
      {
          type value;
      };
      std::vector<type> vec;

      for (Iter it = begin; it != end; ++it)
      {
        vec.push_back(*it);
      }

      return true;
    }

    template <typename T, typename F>
    static void partition_example(F partition)
    {
      static const auto lambda_even = [](T n) { return n % 2 == 0; };
      static const auto lambda_odd = [](T n) { return n % 2 != 0; };
      static const auto lambda_positive = [](T n) { return n > 0; };
      static const auto lambda_negative = [](T n) { return n < 0; };

      try
      {
        const auto const_vec = random_vector();
        std::cout << std::endl;

        std::cout << "ORIGINAL VECTOR:    ";
        print_vector(const_vec);
        std::cout << std::endl;

        auto vec = const_vec;
        auto it_even = partition(vec.begin(), vec.end(), lambda_even);
        std::cout << "Partition even:     ";
        print_vector(vec);
        std::cout << (partition_validation(vec.begin(), it_even, lambda_even) ? " (T)" : " (F)") << std::endl;
        vec = const_vec;
        auto it_odd = partition(vec.begin(), vec.end(), lambda_odd);
        std::cout << "Partition odd:      ";
        print_vector(vec);
        std::cout << (partition_validation(vec.begin(), it_odd, lambda_odd) ? " (T)" : " (F)") << std::endl;
        vec = const_vec;
        auto it_positive = partition(vec.begin(), vec.end(), lambda_positive);
        std::cout << "Partition positive: ";
        print_vector(vec);
        std::cout << (partition_validation(vec.begin(), it_positive, lambda_positive) ? " (T)" : " (F)") << std::endl;
        vec = const_vec;
        auto it_negative = partition(vec.begin(), vec.end(), lambda_negative);
        std::cout << "Partition negative: ";
        print_vector(vec);
        std::cout << (partition_validation(vec.begin(), it_negative, lambda_negative) ? " (T)" : " (F)") << std::endl;
      }
      catch (const std::exception& err)
      {
        std::cout << err.what() << std::endl;
      }
    }

    template <typename T, typename F>
    static void stable_partition_example(F partition)
    {
      static const auto lambda_even = [](T n) { return n % 2 == 0; };
      static const auto lambda_odd = [](T n) { return n % 2 != 0; };
      static const auto lambda_positive = [](T n) { return n > 0; };
      static const auto lambda_negative = [](T n) { return n < 0; };

      try
      {
        const auto const_vec = random_vector();
        std::cout << std::endl;

        std::cout << "ORIGINAL VECTOR:    ";
        print_vector(const_vec);
        std::cout << std::endl;

        auto vec = const_vec;
        auto it_even = stable_partition(vec.begin(), vec.end(), lambda_even);
        std::cout << "Partition even:     ";
        print_vector(vec);
        std::cout << (stable_partition_validation(stable_partition, vec.begin(), it_even, vec.end(), lambda_even) ? " (T)" : " (F)") << std::endl;
        vec = const_vec;
        auto it_odd = stable_partition(vec.begin(), vec.end(), lambda_odd);
        std::cout << "Partition odd:      ";
        print_vector(vec);
        std::cout << (stable_partition_validation(stable_partition, vec.begin(), it_odd, vec.end(), lambda_odd) ? " (T)" : " (F)") << std::endl;
        vec = const_vec;
        auto it_positive = stable_partition(vec.begin(), vec.end(), lambda_positive);
        std::cout << "Partition positive: ";
        print_vector(vec);
        std::cout << (stable_partition_validation(stable_partition, vec.begin(), it_positive, vec.end(), lambda_positive) ? " (T)" : " (F)") << std::endl;
        vec = const_vec;
        auto it_negative = stable_partition(vec.begin(), vec.end(), lambda_negative);
        std::cout << "Partition negative: ";
        print_vector(vec);
        std::cout << (stable_partition_validation(stable_partition, vec.begin(), it_negative, vec.end(), lambda_negative) ? " (T)" : " (F)") << std::endl;
      }
      catch (const std::exception& err)
      {
        std::cout << err.what() << std::endl;
      }
    }
};
