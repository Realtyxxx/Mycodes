#include"head.h"

void InsertionSort(vector<int> &A)
{
    int length = A.size();
    for(int j=1;j<length;++j){
        int key=A[j];
        int i=j-1;
        while(i>=0&&A[i]>key){
            A[i+1]=A[i];
            --i;
        }
        A[i+1]=key;
    }
}

int main(){
    vector<int>a;
    a.push_back(5);
    a.push_back(2);
    a.push_back(4);
    a.push_back(3);
    a.push_back(1);
    InsertionSort(a);
    for(int i=0;i<a.size();++i){
        cout<<a[i]<<' ';
    }
    return 0;
}