#include <assert.h>

#include "charmytree.h"

myNode::myNode(char val, myNode* r = nullptr, myNode* l = nullptr,
               myNode* papa = nullptr)
    : E(val), left(l), right(r), father(papa){};
myNode* myNode::getLeft() { return left; }
myNode* myNode::getRight() { return right; }
myNode* myNode::getFather() { return father; }
char myNode::getValue() { return E; }

void myNode::setLeft(myNode* l) {
  assert(left == nullptr);
  left = l;
  father = this;
}
void myNode::setRight(myNode* r) {
  assert(right == nullptr);
  right = r;
  father = this;
}
void myNode::setValue(char val) { E = val; }
void myNode::setFather(myNode* pa) { father = pa; }

// void myNode::next(myNode* pos) {
//   if (pos == pos->father->left) {
//     pos = pos->father->right;
//   } else {
//   }
// }