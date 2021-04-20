#ifndef GRAPH

#define GRAPH

template <typename VertexType>
class Graph {
 private:
  void operator=(const Graph&) {}  // Protect assignment

  Graph(const Graph&) {}  // Protect copy constructor

 public:
  Graph() {}  // Default constructor默认构造函数

  virtual ~Graph() {}  // Basedestructor 析构函数

  // Initialize a graph of n vertices 初始化一有n个顶点的图

  virtual void Init(int n) = 0;

  // Return: the number of verticesand edges 返回图的顶点数、边数

  virtual int n() = 0;

  virtual int e() = 0;

  // Return v's first neighbor 返回顶点v的第一个邻居

  virtual int first(int v) = 0;

  // Return v's next neighbor 返回在w点之后的邻居（与物理存储中的存放位置有关）

  virtual int next(int v, int w) = 0;

  //设置图的类型（有向图或无向图）

  virtual void setType(bool flag) = 0;

  //获取图的类型

  virtual bool getType() = 0;

  //找到(包含实际信息的）顶点在图中的位置

  virtual int locateVex(VertexType u) = 0;

  //返回某个顶点的值(实际信息)

  virtual VertexType getVex(int v) = 0;

  //给某个顶点赋值

  virtual void putVex(int v, VertexType value) = 0;

  // Set the weight for an edge 为边(v1,v2)设置权值

  virtual void setEdge(int v1, int v2, int wght) = 0;

  // Delete an edge删除边(v1,v2)

  virtual void delEdge(int v1, int v2) = 0;

  // Determine if an edge is in the graph 判断边(i,j)是否在图中

  virtual bool isEdge(int i, int j) = 0;

  // Return an edge's weight 返回边的权值

  virtual int weight(int v1, int v2) = 0;

  // Get and Set the mark value fora vertex 取得和设置顶点的标志位

  virtual int getMark(int v) = 0;

  virtual void setMark(int v, int val) = 0;
};

#endif