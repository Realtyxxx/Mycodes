#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct Status {
  int val;
  ListNode *ptr;
  bool operator<(const Status &rhs) const { return val > rhs.val; }
};

priority_queue<Status> q;

ListNode* mergeKList(vector<ListNode*>& lists){
    for(auto node:lists){
        if(node) q.push({node->val,node});
    }
    ListNode head,*tail= &head;
    while(!q.empty()){
        auto f = q.top();
        q.pop();
        tail->next = f.ptr;
        tail = tail->next;
        if(f.ptr->next) q.push({f.ptr->next->val,f.ptr->next});
    }
    return head.next;
}

int main(){
    return 0;
}