#ifndef _MYTREE_
#define _MYTREE_

class myNode {
 private:
  void operator=(const myNode&) {}
  myNode(const myNode&) {}
  myNode* left;
  myNode* right;
  int E;

 public:
  myNode(int);
  ~myNode(){};
  myNode(int e, myNode* r, myNode* l);
  int getValue();
  myNode* getLeft();
  myNode* getRight();
  void setLeft(myNode* l);
  void setRight(myNode* r);
};

#endif