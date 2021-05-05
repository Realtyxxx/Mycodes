#ifndef __MYTREE__
#define __MYTREE__

class myNode {
 private:
  void operator=(const myNode&) {}
  myNode(const myNode&) {}

 public:
  char E;
  myNode* left;
  myNode* right;
  myNode* father;
  ~myNode(){};
  myNode(char e, myNode* r, myNode* l, myNode* papa);
  char getValue();
  void setValue(char);
  myNode* getLeft();
  myNode* getRight();
  myNode* getFather();
  void setLeft(myNode* l);
  void setRight(myNode* r);
  void setFather(myNode* pa);
  void next(myNode* pos);
};

#endif