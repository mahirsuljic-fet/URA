#include "validator.hpp"

#include <chrono>
#include <iostream>
#include <thread>

void print_sudoku(int sudoku[9][9])
{
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      std::cout << sudoku[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

bool solve_sudoku(int sudoku[9][9], int row, int col)
{
  // da li smo dosli do kraja
  if (row == 8 && col == 9)
  {
    print_sudoku(sudoku);
    return true;
  }
  if (col == 9)
  {
    col = 0;
    row = row + 1;
  }

  if (sudoku[row][col] != 0)
  {
    if (solve_sudoku(sudoku, row, col + 1))
      return true;
  }
  else
  {
    for (int i = 1; i <= 9; i++)
    {
      sudoku[row][col] = i;
      if (isValid(sudoku, row, col))
      {
        print_sudoku(sudoku);
        getchar();
        if (solve_sudoku(sudoku, row, col + 1))
          return true;
      }
      sudoku[row][col] = 0;
    }
  }
  return false;
}

int main()
{
  int sudoku[9][9] { { 0, 0, 3, 0, 2, 0, 6, 0, 0 }, { 9, 0, 0, 3, 0, 5, 0, 0, 1 },
    { 0, 0, 1, 8, 0, 6, 4, 0, 0 }, { 0, 0, 8, 1, 0, 2, 9, 0, 0 },
    { 7, 0, 0, 0, 0, 0, 0, 0, 8 }, { 0, 0, 6, 7, 0, 8, 2, 0, 0 },
    { 0, 0, 2, 6, 0, 9, 5, 0, 0 }, { 8, 0, 0, 2, 0, 3, 0, 0, 9 },
    { 0, 0, 5, 0, 1, 0, 3, 0, 0 } };
  print_sudoku(sudoku);
  solve_sudoku(sudoku, 0, 0);
  std::cout << (isValidConfig(sudoku, 9) ? "YES\n" : "NO\n");
}
