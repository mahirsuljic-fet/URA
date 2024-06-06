#include <iostream>
#include <ostream>
#include <vector>

// 1 - prohodno
// 0 - zid

using MazeRow = std::vector<int>;
using Maze = std::vector<MazeRow>;

static std::ostream& operator<<(std::ostream&, const Maze&);
static std::istream& operator>>(std::istream&, Maze&);

bool isValid(int row, int col, Maze& maze)
{
  const int n = maze.size();
  const int m = maze[0].size();
  return row >= 0 && col >= 0 && row < n && col < m && maze[row][col];
}

void findPath(int row, int col, Maze& maze, std::vector<Maze>& solutions, Maze& current_solution)
{
  // directions: DOWN, LEFT, RIGHT, UP
  constexpr static const int direction_row[4] = { 1, 0, 0, -1 };
  constexpr static const int direction_col[4] = { 0, -1, 1, 0 };

  const int n = maze.size();
  const int m = maze[0].size();

  if (row == n - 1 && col == m - 1)
  {
    current_solution[row][col] = 1;
    solutions.push_back(current_solution);
    return;
  }

  maze[row][col] = 0;

  for (int i = 0; i < 4; i++)
  {
    int nextrow = row + direction_row[i];
    int nextcol = col + direction_col[i];

    if (isValid(nextrow, nextcol, maze))
    {
      current_solution[row][col] = 1;
      findPath(nextrow, nextcol, maze, solutions, current_solution);
      current_solution[nextrow][nextcol] = 0;
    }
  }

  maze[row][col] = 1;
}

int main()
{
  Maze maze;

  std::cin >> maze;

  int n = maze.size();
  int m = maze[0].size();
  std::vector<Maze> solutions;

  std::cout << "Labirint:" << std::endl;
  std::cout << maze << std::endl;

  Maze current_solution(n);
  for (auto& maze : current_solution) maze.resize(m);

  if (maze[0][0] != 0 && maze[n - 1][n - 1] != 0)
    findPath(0, 0, maze, solutions, current_solution);

  if (solutions.size() > 0)
  {
    std::cout << "Rjesenja:" << std::endl;
    for (int i = 0; i < solutions.size() - 1; i++)
      std::cout << solutions[i] << std::endl;
    std::cout << solutions[solutions.size() - 1];
  }
  else
    std::cout << "Nema rjesenja" << std::endl;

  return 0;
}

static std::ostream& operator<<(std::ostream& out, const Maze& maze)
{
  for (const auto& row : maze)
  {
    for (const auto& cell : row)
      out << cell << " ";
    out << std::endl;
  }

  return out;
}

static std::istream& operator>>(std::istream& in, Maze& maze)
{
  int n, m, x;

  in >> n >> m;

  maze.resize(n);
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      in >> x;
      maze[i].push_back(x);
    }
  }

  return in;
}
