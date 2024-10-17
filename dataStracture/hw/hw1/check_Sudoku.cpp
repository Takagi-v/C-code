#include <iostream>
#include <vector>
using namespace std;
const int N = 9;
bool checkSudoku(const vector<vector<int>> &sudoku)
{
  // check row
  for (int i = 0; i < N; i++)
  {
    vector<bool> row_check(N + 1, false);
    for (int j = 0; j < N; j++)
    {
      int num = sudoku[i][j];
      if (row_check[num])
      {
        return false;
      }
      row_check[num] = true;
    }
  }
  // check column
  for (int j = 0; j < N; j++)
  {
    vector<bool> col_check(N + 1, false);
    for (int i = 0; i < N; i++)
    {
      int num = sudoku[i][j];
      if (col_check[num])
      {
        return false;
      }
      col_check[num] = true;
    }
  }
  // check subgrid
  for (int block_row = 0; block_row < N; block_row += 3)
  {
    for (int block_col = 0; block_col < N; block_col += 3)
    {
      vector<bool> subgrid_check(N + 1, false);
      for (int i = block_row; i < block_row + 3; i++)
      {
        for (int j = block_col; j < block_col + 3; j++)
        {
          int num = sudoku[i][j];
          if (subgrid_check[num])
          {
            return false;
          }
          subgrid_check[num] = true;
        }
      }
    }
  }
  return true;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    vector<vector<int>> sudoku(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        cin >> sudoku[i][j];
      }
    }
    if (checkSudoku(sudoku))
    {
      cout << "Right" << endl;
    }
    else
    {
      cout << "Wrong" << endl;
    }

    if (t > 0)
    {
      cin.ignore();
    }
  }
  return 0;
}