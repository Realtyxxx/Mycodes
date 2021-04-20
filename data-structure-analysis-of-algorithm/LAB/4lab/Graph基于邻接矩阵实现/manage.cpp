#include <cstring>
#include <iostream>

#include "aqueue.h"
#include "book.h"
#include "create.h"
#include "graph.h"
#include "graphm.h"

using namespace std;

// Topologicalsort: Queue 使用队列进行拓扑排序

void topsort(Graph<string>* G, Queue<int>* Q) {
  int Count[G->n()];

  int v, w;

  for (v = 0; v < G->n(); v++) Count[v] = 0;

  for (v = 0; v < G->n(); v++)  // Process every edge 处理每条边

    for (w = G->first(v); w < G->n(); w = G->next(v, w))

      Count[w]++;  // Add to v2's prereq count先决条件计数器加1

  for (v = 0; v < G->n(); v++)  // Initialize queue 初始化队列

    if (Count[v] == 0)  // Vertex has no prerequisites 节点没有先决条件

      Q->enqueue(v);

  while (Q->length() != 0) {  // Process the vertices 处理节点

    v = Q->dequeue();

    cout << G->getVex(v) << "";  // PreVisit for "v" 前向访问

    for (w = G->first(v); w < G->n(); w = G->next(v, w)) {
      Count[w]--;  // One less prerequisite 减少一个先决条件

      if (Count[w] ==
          0)  // This vertex is now free 这个节点没有先决条件了就释放

        Q->enqueue(w);
    }
  }
}

int main() {
  FILE* fid;

  fid = fopen("test.gph", "rt");

  Graph<string>* G;

  //创建图（create.h)

  G = createGraph(fid);

  //打印图（create.h)

  Gprint(G);

  Queue<int>* Q = new AQueue<int>(G->n());

  cout << "--------------------------------\n"

       << "调用topsort打印顶点顺序：\n";

  topsort(G, Q);

  return 0;
}