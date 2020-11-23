#include <bits/stdc++.h>
using namespace std;

int Partioning(std::vector<int>& elements, int firstElement,
                 int lastElement) {
  // for(auto element:elements)    cout<<element<<" ";
  // cout<<endl;
  int pivot = firstElement;
  int store = pivot+1;
  for (int i = firstElement + 1; i < lastElement; ++i) {
    if (elements[i] < elements[pivot]) {
      swap(elements[store], elements[i]);
      store++;
    }
  }
  store--;
  swap(elements[pivot], elements[store]);
  pivot=store;
  // for(auto element:elements)  cout<<element<<" ";
  // cout<<endl;
  return pivot;
}


void myQuickSort(vector<int>& elements,int firstElement,int lastElement) {
  if(lastElement>firstElement){
    int middleElement = Partioning(elements,firstElement, lastElement);
    myQuickSort(elements,firstElement,middleElement-1);
    myQuickSort(elements,middleElement+1,lastElement);
  }
  return;
  
}

int main() {
  vector<int> a;
  a.push_back(6);
  a.push_back(2);
  a.push_back(4);
  a.push_back(3);
  a.push_back(1);
  myQuickSort(a,0,a.size());
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << ' ';
  }
  return 0;
}