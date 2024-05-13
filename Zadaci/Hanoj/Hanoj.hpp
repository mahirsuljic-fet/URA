#pragma once

#include <chrono>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>

class Hanoj
{
  public:
    static void Solve(size_t n);

  private:
    constexpr static const size_t DEFAULT_TIME = 2000;
    constexpr static const char DISK_CHAR = '=';
    constexpr static const char STICK_CHAR = '|';

    using Tower = std::vector<size_t>;
    using Milis = std::chrono::milliseconds;

    Hanoj() = delete;
    Hanoj(const Hanoj&) = delete;
    Hanoj(Hanoj&&) = delete;
    Hanoj& operator=(const Hanoj&) = delete;
    Hanoj& operator=(Hanoj&&) = delete;
    ~Hanoj();

    static Tower create_tower(size_t n);
    static void move_single(Tower& from, Tower& to);
    static void move(Tower& from, Tower& to, Tower& with, size_t amount);
    static void print(std::ostream& out = std::cout);

    static inline Tower A;
    static inline Tower B;
    static inline Tower C;
};
