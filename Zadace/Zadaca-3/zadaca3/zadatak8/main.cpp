#include <iomanip>
#include <iostream>

constexpr static const int N = 8;

int solveKT_impl(int x, int y, int movei, int sol[N][N], const int xMove[], const int yMove[]);

int is_safe(int x, int y, int solution[N][N])
{
  return (x >= 0 && x < N && y >= 0 && y < N && solution[x][y] == -1);
}

void print_solution(int solution[N][N])
{
  for (int x = 0; x < N; x++)
  {
    for (int y = 0; y < N; y++)
      std::cout << " " << std::setw(2) << solution[x][y] << " ";
    std::cout << std::endl;
  }
}

int solveKT()
{
  int solution[N][N];

  for (int x = 0; x < N; x++)
    for (int y = 0; y < N; y++)
      solution[x][y] = -1;

  constexpr static const int move_x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
  constexpr static const int move_y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

  solution[0][0] = 0;

  if (solveKT_impl(0, 0, 1, solution, move_x, move_y) == 0)
  {
    std::cout << "Nema rjesenja";
    return 0;
  }
  else
    print_solution(solution);

  return 1;
}

int solveKT_impl(int x, int y, int move_i, int solution[N][N], const int move_x[8], const int move_y[8])
{
  int k, next_x, next_y;

  if (move_i == N * N) return 1;

  for (k = 0; k < 8; k++)
  {
    next_x = x + move_x[k];
    next_y = y + move_y[k];
    if (is_safe(next_x, next_y, solution))
    {
      solution[next_x][next_y] = move_i;
      if (solveKT_impl(next_x, next_y, move_i + 1, solution, move_x, move_y) == 1)
        return 1;
      else
        solution[next_x][next_y] = -1;
    }
  }
  return 0;
}

int main()
{
  solveKT();
  return 0;
}
