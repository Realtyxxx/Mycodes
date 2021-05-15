#include <iostream>

#include "Graphm.h"
using namespace std;

int main() {
  int n, m, weight;
  char temp, head, tail;
  cin >> n >> m;

  Graphm myMap(n);

  for (int i = 0; i < n; i++) {
    cin >> temp;
    myMap.makePair(i, temp);
  }
  for (int i = 0; i < m; i++) {
    cin >> head >> tail >> weight;
    myMap.setEdge(myMap.getKey(head), myMap.getKey(tail), weight);
  }
  myMap.printMatrix();
  
  char mostOuterDot = myMap.getValue(0);
  int mostOuters = 0;
  for (int i = 0; i < n; i++) {
    int tempDot = myMap.getValue(i);
    int tempOuters = 0;
    for (int j = 0; j < n; j++) {
      if (myMap.weight(i, j)) tempOuters++;
    }
    if (tempOuters > mostOuters) {
      mostOuters = tempOuters;
      mostOuterDot = tempDot;
    } else if (tempOuters == mostOuters) {
      mostOuterDot = mostOuterDot > tempDot ? mostOuterDot : tempDot;
    }
  }
  cout << mostOuterDot << " " << mostOuters << endl;
  return 0;
}