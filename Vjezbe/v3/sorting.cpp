#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

void selectionsort(int* bg, int n)
{
  for (int i = 0; i < n; i++)
  {
    int ind_min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (bg[j] < bg[ind_min])
      {
        ind_min = j;
      }
    }
    std::swap(bg[ind_min], bg[i]);
  }
}

void bubblesort(int* bg, int n)
{
  for (int e = n; e > 1; e--)
  {
    bool swapped = false;
    for (int i = 0; i < e - 1; i++)
    {
      if (bg[i] > bg[i + 1])
      {
        std::swap(bg[i], bg[i + 1]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}

void insertionsort(int* bg, int n)
{
  for (int i = 1; i < n; i++)
  {
    for (int j = i; j > 0; j--)
    {
      if (bg[j] < bg[j - 1])
        std::swap(bg[j], bg[j - 1]);
      else
        break;
    }
  }
}

void insertionsort_var(int* bg, int n, int increment)
{
  for (int i = increment; i < n; i += increment)
  {
    for (int j = i; j >= increment; j -= increment)
    {
      if (bg[j] < bg[j - increment])
        std::swap(bg[j], bg[j - increment]);
      else
        break;
    }
  }
}

void shellsort(int* bg, int n)
{
  for (int increment = n / 2; increment >= 1; increment = increment / 2)
  {
    for (int i = 0; i < increment; i++)
    {
      insertionsort_var(bg + i, n - i, increment);
    }
  }
}

void benchmark(int* niz, int n, void (*f)(int*, int))
{
  auto begin = std::chrono::steady_clock::now();
  f(niz, n);
  auto end = std::chrono::steady_clock::now();
  std::cout << "Trajanje: " << ((end - begin).count() / 1000) << "us"
            << std::endl;
}

// Change N here!
#define N 10000

int main(int argc, char* argv[])
{
  int v[N];
  for (int i = 0; i < N; i++)
  {
    v[i] = i;
  }
  std::random_shuffle(v, v + N);
  puts("bubblesort");
  benchmark(v, N, bubblesort);

  std::random_shuffle(v, v + N);
  puts("selectionsort");
  benchmark(v, N, selectionsort);

  std::random_shuffle(v, v + N);
  puts("insertionsort");
  benchmark(v, N, insertionsort);

  std::random_shuffle(v, v + N);
  puts("shellsort");
  benchmark(v, N, shellsort);
}
