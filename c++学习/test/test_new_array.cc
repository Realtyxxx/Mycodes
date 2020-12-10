#include<bits/stdc++.h>
using namespace std;
int main(int argc, char **argv){
  int n;
  n = atoi(argv[1]);
  int a[n];
  for(int i=0; i<n;++i){
    a[i] = rand();
  }
  for(auto e:a){
    cout<<e<<" ";
  }
  return 0;
}