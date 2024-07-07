#pragma once
#include <set>

// Checks whether there is any duplicate
// in current row or not
inline bool notInRow(int arr[][9], int row)
{
  // Set to store intacters seen so far.
  std::set<int> st;

  for (int i = 0; i < 9; i++)
  {
    // If already encountered before, return false
    if (st.find(arr[row][i]) != st.end())
      return false;

    // If it is not an empty cell, insert value
    // at the current cell in the set
    if (arr[row][i] != 0)
      st.insert(arr[row][i]);
  }
  return true;
}

// Checks whether there is any duplicate
// in current column or not.
inline bool notInCol(int arr[][9], int col)
{
  std::set<int> st;

  for (int i = 0; i < 9; i++)
  {
    // If already encountered before, return false
    if (st.find(arr[i][col]) != st.end())
      return false;

    // If it is not an empty cell,
    // insert value at the current cell in the set
    if (arr[i][col] != 0)
      st.insert(arr[i][col]);
  }
  return true;
}

// Checks whether there is any duplicate
// in current 3x3 box or not.
inline bool notInBox(int arr[][9], int startRow, int startCol)
{
  std::set<int> st;

  for (int row = 0; row < 3; row++)
  {
    for (int col = 0; col < 3; col++)
    {
      int curr = arr[row + startRow][col + startCol];

      // If already encountered before, return false
      if (st.find(curr) != st.end())
        return false;

      // If it is not an empty cell,
      // insert value at current cell in set
      if (curr != 0)
        st.insert(curr);
    }
  }
  return true;
}

// Checks whether current row and current column and
// current 3x3 box is valid or not
inline bool isValid(int arr[][9], int row, int col)
{
  return notInRow(arr, row) && notInCol(arr, col)
    && notInBox(arr, row - row % 3, col - col % 3);
}

inline bool isValidConfig(int arr[][9], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      // If current row or current column or
      // current 3x3 box is not valid, return false
      if (!isValid(arr, i, j))
        return false;
    }
  }
  return true;
}
