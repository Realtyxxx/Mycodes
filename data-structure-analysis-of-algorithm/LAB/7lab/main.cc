#include <iostream>
#include <vector>
using namespace std;

void printMap(int vertex, vector<vector<int> > map, string routine) {
  cout << "Print :" << routine << endl;
  for (int i = 1; i <= vertex; ++i) {
    for (int j = 1; j <= vertex; ++j) {
      cout << map[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int vertex, edge;
  cin >> vertex >> edge;
  vector<vector<int> > map(vertex + 1, vector<int>(vertex + 1, 0));
  vector<vector<int> > mapcopy(vertex + 1, vector<int>(vertex + 1, 0));
  int in, out;
  while (edge--) {
    cin >> in >> out;
    map[in][out] = 1;
    mapcopy[in][out] = 1;
    // cout << "map[" << in << "][" << out << "]"
    //      << " == " << map[in][out] << endl;
  }

  // floyd
  for (int k = 1; k <= vertex; ++k) {
    for (int i = 1; i <= vertex; ++i) {
      for (int j = 1; j <= vertex; ++j) {
        if (i == j || i == k || j == k) continue;
        if (!map[i][j]) {
          map[i][j] = map[i][k] && map[k][j];
        }
      }
    }
  }
  printMap(vertex, map, "after floyd");
  // self true
  for (int i = 1; i <= vertex; ++i) {
    map[i][i] = true;
  }
  // pre true
  for (int i = 1; i <= vertex; ++i) {
    for (int j = 1; j <= vertex; ++j) {
      if (mapcopy[i][j]) {
        map[j][i] = 1;
      }
    }
  }

  // for (int i = 1; i <= vertex; ++i) {
  // cout << "map[" << 1 << "][" << i << "]"
  //      << " == " << map[1][i] << endl;
  // }
  int ans = 0, count;
  vector<int> sum(vertex + 1, 0);

  // judge if enough out
  for (int i = 1; i <= vertex; ++i) {
    count = 0;
    for (int j = 1; j <= vertex; ++j) {
      if (map[i][j]) count++;
    }
    if (count == vertex) {
      sum[i] = 1;
      // cout << i << endl;
    }
  }
  // judge if enough in
  for (int i = 1; i <= vertex; ++i) {
    count = 0;
    for (int j = 1; j <= vertex; ++j) {
      if (map[j][i]) count++;
    }
    if (count == vertex) {
      sum[i] = 1;
      // cout << i << endl;
    }
  }
  for (int i = 1; i <= vertex; ++i) {
    if (sum[i]) ans++;
  }
  printMap(vertex, map, "final");
  cout << ans << endl;
  return 0;
}