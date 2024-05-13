#include "Hanoj.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <thread>

void Hanoj::Solve(size_t n)
{
  A = create_tower(n);
  B.reserve(n);
  C.reserve(n);

  print();
  move(A, B, C, n);
}

Hanoj::Tower Hanoj::create_tower(size_t n)
{
  Tower tower(n);
  for (size_t i = 0; i < n; ++i)
    tower[i] = n - i;
  return tower;
}

void Hanoj::move_single(Tower& from, Tower& to)
{
  auto temp = from.back();
  from.back() = 0;
  from.pop_back();
  to.push_back(temp);
  print();
}

void Hanoj::move(Tower& from, Tower& to, Tower& with, size_t amount)
{
  if (amount == 1)
  {
    move_single(from, to);
    return;
  }

  move(from, with, to, amount - 1);
  move_single(from, to);
  move(with, to, from, amount - 1);
}

void Hanoj::print(std::ostream& out)
{
  system("clear");

  std::string disk_half;
  std::string empty_space;
  int max_w = A.capacity();

  for (int i = max_w - 1; i >= 0; --i)
  {
    disk_half = std::string(A[i], DISK_CHAR);
    empty_space = std::string(max_w - A[i] + 1, ' ');
    out << empty_space << disk_half << STICK_CHAR << disk_half << empty_space;

    disk_half = std::string(B[i], DISK_CHAR);
    empty_space = std::string(max_w - B[i] + 1, ' ');
    out << empty_space << disk_half << STICK_CHAR << disk_half << empty_space;

    disk_half = std::string(C[i], DISK_CHAR);
    empty_space = std::string(max_w - C[i] + 1, ' ');
    out << empty_space << disk_half << STICK_CHAR << disk_half << empty_space << std::endl;
  }

  std::this_thread::sleep_for(Milis(DEFAULT_TIME / max_w));
}
