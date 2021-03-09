#include <iostream>
#include <set>
using namespace std;

int main() {
  set<int> my_set;
  set<int>::iterator it;

  for (int i = 1; i < 10; i++) {
    my_set.insert(i * 10);
  }

  it = my_set.begin();
  ++it;

  my_set.erase(it);

  my_set.erase(40);

  it = my_set.find(60);
  my_set.erase(it, my_set.end());

  cout << "my_set contains :";
  for (it = my_set.begin(); it != my_set.end(); ++it) {
    cout << ' ' << *it;
  }
  cout << endl;

  return 0;
}
