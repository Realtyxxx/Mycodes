#include <assert.h>

#include <iostream>

#include "Graph.h"
#include "memory.h"
using namespace std;

void Assert(bool val, string s) {
  if (!val) {
    cout << s << endl;
    assert(val);
  }
}
enum visit { UNVISITED, VISITED };

class Graphm : public Graph {
 private:
  int numVertex, numEdge;
  int **matrix;
  int *mark;
  char *value;

 public:
  Graphm(int numVert) { Init(numVert); }

  virtual ~Graphm() {
    delete[] mark;
    delete[] value;
    delete[] matrix[1];
    // for (int i = 0; i < numVertex; i++) delete[] matrix[i];
    // delete[] matrix;
  }

  virtual void Init(int n) {
    numVertex = n;
    mark = new int[numVertex];
    for (int i = 0; i < numVertex; i++) mark[i] = UNVISITED;

    value = new char[numVertex];
    matrix = new int *[numVertex];
    for (int i = 0; i < numVertex; i++) {
      matrix[i] = new int[numVertex];
      memset(matrix[i], 0, numVertex * sizeof(int));
    }
    // cout << "runned" << endl;
  }

  void makePair(int v, char c) { value[v] = c; }

  virtual char getValue(int v) { return value[v]; };

  virtual int getKey(char c) {
    for (int i = 0; i < numVertex; i++)
      if (value[i] == c) return i;
    return numVertex;
  }

  virtual int n() { return numVertex; }

  virtual int e() { return numEdge; }

  virtual int first(int v) {
    for (int i = 0; i < numVertex; i++)
      if (matrix[v][i] != 0) return i;
    return numVertex;
  }
  virtual int next(int v, int w) {
    for (int i = w + 1; i < numVertex; i++)
      if (matrix[v][i] != 0) return i;
    return numVertex;
  }
  virtual void setEdge(int v1, int v2, int wght) {
    Assert(wght > 0, "Invalid Value");
    if (matrix[v1][v2] == 0) numEdge++;
    matrix[v1][v2] = wght;
  }
  virtual void delEdge(int v1, int v2) {
    if (matrix[v1][v2] != 0) numEdge--;
    matrix[v1][v2] = 0;
  }
  virtual bool isEdge(int i, int j) { return matrix[i][j] != 0; }
  virtual int weight(int v1, int v2) { return matrix[v1][v2]; }
  virtual int getMark(int v) { return mark[v]; }
  virtual void setMark(int v, int val) { mark[v] = val; }
  virtual void printMatrix() {
    for (int i = 0; i < numVertex; i++) {
      for (int j = 0; j < numVertex; j++) {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
  }
};