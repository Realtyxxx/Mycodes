#include <assert.h>

#include "./mytree.h"

myNode::myNode(char val) : E(val), left(nullptr), right(nullptr){};
myNode::myNode(char e, myNode* r, myNode* l) : E(e), left(l), right(r){};
myNode* myNode::getLeft() {
  return left;
}
myNode* myNode::getRight() {
  return right;
}

void myNode::setLeft(myNode* l) {
  assert(left == nullptr);
  left = l;
}
void myNode::setRight(myNode* r) {
  assert(right == nullptr);
  right = r;
}
char myNode::getValue() {
  return E;
}
