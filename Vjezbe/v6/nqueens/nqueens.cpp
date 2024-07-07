#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <chrono>
#include <iostream>
#include <thread>

#define N 8

int board[N][N];
void place_queen(int x, int y)
{
  board[x][y] = 1;
}
void remove_queen(int x, int y)
{
  board[x][y] = 0;
}

// Da li mogu staviti kraljicu na polje x, y
bool is_free(int x, int y)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (board[i][j] == 1)
      {
        // we found a queen placed on the board
        if (i == x)
          return false;
        if (j == y)
          return false;
        if ((i - x) == (j - y))
          return false;
        if ((i - x) == -(j - y))
          return false;
      }
    }
  }
  return true;
}

// Pretty print every step
void print_board()
{
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      if (board[i][j] == 1)
        printf("\u265B ");
      else
        printf("o ");
    }
    putchar('\n');
  }
  putchar('\n');
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

// Main algo - ispisati sva rjesenja
void nqueens(int column)
{
  if (column == N)
  {
    std::cout << "SOLUTION:" << std::endl;
    print_board();
  }
  for (int i = 0; i < N; i++)
  {
    if (is_free(i, column))
    {
      place_queen(i, column);
      nqueens(column + 1);
      remove_queen(i, column);
    }
  }
}

int main(int argc, char* argv[])
{
  nqueens(0);
  puts("Finalno");
  print_board();
  return 0;
}
