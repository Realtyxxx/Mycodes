#include<bits/stdc++.h>

using namespace std;

int a[46]={0,1,2,3,5};


int main(){
    int n;
    cin>>n;
    if(n==1){return 1;}
    if(n==2){return 2;}
    for(int i=0; i<=n; i++){
        a[i]=a[i-1]+a[i-2];
    }    
    return a[n];
}