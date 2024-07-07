#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define N 8

typedef struct
{
    int x;
    int y;
} pair;

int board[N][N];

pair knights_moves[] = { { 1, 2 }, { 2, 1 }, { 2, -1 }, { 1, -2 },
  { -1, -2 }, { -2, -1 }, { -2, 1 }, { -1, 2 } };

// if the move is valid, move the knight and return true
// else, unchanged
int move_figure(pair* fig, pair move, int jump)
{
  int a = (fig->x + move.x);
  int b = (fig->y + move.y);
  if (a < 0 || a >= N || b < 0 || b >= N || board[a][b] != 0)
    return 0;

  fig->x += move.x;
  fig->y += move.y;
  board[fig->x][fig->y] = jump;
  return 1;
}

// returning does not need validity check
void return_figure(pair* fig, pair move)
{
  board[fig->x][fig->y] = 0;
  fig->x -= move.x;
  fig->y -= move.y;
}

// Pretty print every step
void print_board_step()
{
  for (int gg = 1; gg <= N * N; ++gg)
  {
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        /* if (board[i][j] == gg) */
        /*   printf("\u265E "); */
        /* else */
        if (board[i][j] <= gg)
          printf("% 3d", board[i][j]);
        else
          printf(" o ");
      }
      putchar('\n');
    }
    putchar('\n');
  }
}

// Main algo
void knights_tour(int n, pair* knight)
{
  if (n > N * N)
  { // run is complete
    print_board_step();
    exit(1);
  }
  else
  {
    for (int i = 0; i < 8; ++i)
    {
      if (move_figure(knight, knights_moves[i], n))
      {
        knights_tour(n + 1, knight);
        return_figure(knight, knights_moves[i]);
      }
    }
  }
}

int main(int argc, char* argv[])
{
  pair knight = { 0, 0 };
  board[0][0] = 1;
  knights_tour(2, &knight);
  return 0;
}
