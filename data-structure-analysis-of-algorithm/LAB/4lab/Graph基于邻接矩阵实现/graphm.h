#include <iostream>

#include "graph.h"

#define MAX_VERTEX_NUM 40

#define UNVISITED 0

#define VISITED 1

using namespace std;

template <typename VertexType>

class Graphm : public Graph<VertexType> {
 private:
  int numVertex, numEdge;  //顶点数和边数

  bool undirected;  // true表示无向图 false表示有向图

  VertexType vexs[MAX_VERTEX_NUM];  //存储顶点信息

  int **matrix;  // Point er to adjacency matrix 指向邻接矩阵matrix

  int *mark;  // Point er to mark array 指向mark数组

 public:
  Graphm(int numVert)  // Constructor 构造函数

  {
    Init(numVert);
  }

  ~Graphm() {  // Destructor 析构函数

    cout << "gramat delete";

    delete[] mark;  // Return  dynamicallyallocated memory回收动态分配内存

    for (int i = 0; i < numVertex; i++) delete[] matrix[i];

    delete[] matrix;
  }

  void Init(int n) {  // Initialize the graph初始化图

    int i;

    numVertex = n;

    numEdge = 0;

    mark = new int[n];  // Initialize mark array 初始化mark数组

    for (i = 0; i < numVertex; i++) mark[i] = UNVISITED;

    matrix = (int **)new int *[numVertex];  // Make matrix 初始化邻接矩阵

    for (i = 0; i < numVertex; i++) matrix[i] = new int[numVertex];

    for (i = 0; i < numVertex; i++)  // Initialize to 0 weights 初始化权值为0

      for (int j = 0; j < numVertex; j++) matrix[i][j] = 0;
  }

  int n() { return numVertex; }  // Number of vertices 返回节点数

  int e() { return numEdge; }  // Number of edges 返回边数

  // Return  first neighbor of"v" 返回v的第一个邻居

  int first(int v) {
    for (int i = 0; i < numVertex; i++)

      if (matrix[v][i] != 0) return i;

    return numVertex;  // Return  n if none 如果没有邻居返回节点数
  }

  // Return  v's next neighbor after w 返回v的在w后的邻居

  int next(int v, int w) {
    for (int i = w + 1; i < numVertex; i++)

      if (matrix[v][i] != 0) return i;

    return numVertex;  // Return  n if none如果没有邻居返回节点数
  }

  //设置图的类型（有向图或无向图）

  void setType(bool flag) { undirected = flag; }

  //获取图的类型

  bool getType() { return undirected; }

  /**返回顶点在图中的位置**/

  int locateVex(VertexType u) {
    for (int i = 0; i < numVertex; i++) {
      if (Comp(u, vexs[i]))  // Comp模板函数写在book.h中

        return i;
    }

    return -1;
  }

  /**返回某个顶点的值(实际信息) **/

  VertexType getVex(int v) { return vexs[v]; }

  /**给某个顶点赋值**/

  void putVex(int v, VertexType value) { vexs[v] = value; }

  // Set edge (v1, v2) to"wt" 设置边(v1,v2)的权值为wt

  void setEdge(int v1, int v2, int wt) {
    Assert(wt > 0, "Illegal weight value");

    if (matrix[v1][v2] == 0) numEdge++;

    matrix[v1][v2] = wt;

    if (undirected) {
      matrix[v2][v1] = wt;
    }
  }

  void delEdge(int v1, int v2) {  // Delete edge (v1, v2) 删除边(v1,v2)

    if (matrix[v1][v2] != 0) {
      numEdge--;

      matrix[v1][v2] = 0;

      if (undirected) {
        matrix[v2][v1] = 0;
      }
    }
  }

  bool isEdge(int i, int j)  // Is(i, j) an edge? 判断边(i,j)是图中的一条边吗？

  {
    return matrix[i][j] != 0;
  }

  int weight(int v1, int v2) { return matrix[v1][v2]; }

  int getMark(int v) { return mark[v]; }

  void setMark(int v, int val) { mark[v] = val; }
};