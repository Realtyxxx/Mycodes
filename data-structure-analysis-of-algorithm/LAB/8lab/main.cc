#include <iostream>
#include <vector>
using namespace std;

int main() {
  int row, col;
  cin >> row >> col;
  vector<vector<int> > grid(row, vector<int>(col));
  for (int i = 0; i < row; i++) {
    grid[i][0] = 1;
  }
  for (int i = 1; i < col; i++) {
    grid[0][i] = 1;
  }
  for (int i = 1; i < row; i++) {
    for (int j = 1; j < col; j++) {
      grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
    }
  }
  cout << grid[row - 1][col - 1] << endl;
  return 0;
}