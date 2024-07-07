#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using Board = std::vector<int*>;

static int w = 1;
static std::string h_border;
static std::string empty_square;

void print_board(const Board& board, int count = 0)
{
  std::cout << h_border << std::endl;
  for (const auto& row : board)
  {
    for (int i = 0; i < board.size(); ++i)
      std::cout << '|' << std::setw(w) << row[i];
    std::cout << '|' << std::endl;
    std::cout << h_border << std::endl;
  }
}

bool place_knights(Board& board, int count, int row = 0, int column = 0)
{
  constexpr static const std::pair<int, int> moves[] = { { 1, 2 }, { 2, 1 }, { 2, -1 }, { 1, -2 }, { -1, -2 }, { -2, -1 }, { -2, 1 }, { -1, 2 } };
  constexpr static const int moves_n = sizeof(moves) / sizeof(moves[0]);

  if (count >= board.size() * board.size())
    return true;

  if (row < 0 || row >= board.size() || column < 0 || column >= board.size())
    return false;

  if (board[row][column])
    return false;

  ++count;
  board[row][column] = count;

  for (int i = 0; i < moves_n; ++i)
    if (place_knights(board, count, row + moves[i].first, column + moves[i].second))
      return true;

  board[row][column] = 0;
  --count;

  return false;
}

void knights(int n)
{
  Board board;
  board.resize(n);

  int* board_start = new int[n * n];
  std::memset(board_start, 0, n * n);

  for (int i = 0; i < n; ++i)
    board[i] = board_start + i * n;

  int x = n * n;
  while (x > 0)
  {
    x /= 10;
    ++w;
  }

  h_border = std::string(board.size() * (w + 1) + 1, '-');

  int count = 0;
  if (place_knights(board, count))
    print_board(board);
  else
    std::cout << "NO SOLUTION" << std::endl;
}

int main()
{
  knights(8);
  return 0;
}
