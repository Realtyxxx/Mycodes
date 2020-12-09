#include "../head.h"
using namespace std;

vector<int> cSort(vector<int> sequence) {
  int l = sequence.size();
  int max = 0;
  for (auto element : sequence)
    if (element > max) max = element;
  vector<int> aux(max + 1);
  vector<int> ans(l);
  for (auto element : aux) element = 0;
  for (int i = 0; i < l; ++i) aux[sequence[i]] += 1;
  for (int i = 1; i <= max; ++i) aux[i] += aux[i - 1];
  while (--l >= 0) {
    ans[aux[sequence[l]]-1] = sequence[l];
    // cout << sequence[l] << " " << aux[sequence[l]] << endl;
    aux[sequence[l]]--;
  }
  return ans;
}

int main() {
  vector<int> a;
  a.push_back(8);
  a.push_back(3);
  a.push_back(5);
  a.push_back(17);
  a.push_back(2);
  a.push_back(5);
  a.push_back(1);
  a.push_back(12);
  a.push_back(2);
  for (auto element : a) cout << element << " ";
  cout << endl;
  vector<int> cs = cSort(a);
  // cout << endl;
  for (auto element : cs) cout << element << " ";
  return 0;
}