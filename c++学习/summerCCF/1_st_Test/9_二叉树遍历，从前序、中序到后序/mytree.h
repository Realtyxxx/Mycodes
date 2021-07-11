#ifndef _MYTREE_
#define _MYTREE_

class myNode {
 private:
  void operator=(const myNode&) {}
  myNode(const myNode&) {}
  myNode* left;
  myNode* right;
  char E;

 public:
  myNode(char);
  ~myNode(){};
  myNode(char e, myNode* r, myNode* l);
  char getValue();
  myNode* getLeft();
  myNode* getRight();
  void setLeft(myNode* l);
  void setRight(myNode* r);
};

#endif