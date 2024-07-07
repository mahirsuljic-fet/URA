#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using Board = std::vector<bool*>;

void print_board(const Board& board)
{
  std::cout << std::string(board.size() * 2 + 1, '-') << std::endl;
  for (const auto& row : board)
  {
    for (int i = 0; i < board.size(); ++i)
      std::cout << '|' << (row[i] ? '*' : ' ');
    std::cout << '|' << std::endl;
    std::cout << std::string(board.size() * 2 + 1, '-') << std::endl;
  }
}

bool is_safe(const Board& board, int row, int column)
{
  for (int x = 0; x < board.size(); ++x)
  {
    if (board[x][column] || board[row][x])
      return false;

    int y = x - row + column;
    if (y >= 0 && y < board.size())
      if (board[x][y])
        return false;

    y = -x + row + column;
    if (y >= 0 && y < board.size())
      if (board[x][y])
        return false;
  }

  return true;
}

bool place_queens(Board& board, int row = 0)
{
  if (row >= board.size()) return false;

  for (int column = 0; column < board.size(); ++column)
  {
    if (is_safe(board, row, column))
    {
      board[row][column] = true;

      if (row == board.size() - 1)
        return true;

      if (place_queens(board, row + 1))
        return true;

      board[row][column] = false;
    }
  }

  return false;
}

void queens(int n)
{
  Board board;
  board.resize(n);

  bool* board_start = new bool[n * n];
  std::memset(board_start, 0, n * n);

  for (int i = 0; i < n; ++i)
    board[i] = board_start + i * n;

  if (place_queens(board))
    print_board(board);
  else
    std::cout << "NO SOLUTION" << std::endl;
}

int main()
{
  queens(8);
  return 0;
}
