#include<iostream>
#include<vector>

using namespace std;

// @lc code=start

int trap(vector<int> &height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int leftmax = 0, rightmax = 0;
    while (left < right) { 
        if(height[left]<height[right]){
            height[left]>leftmax ?    (leftmax=height[left]) :ans+=(leftmax-height[left]);
            ++left;
        }else{
            height[right]>rightmax ? (rightmax=height[right]) :ans+=(rightmax-height[right]);
            --right;
        }
    }
    return ans;
}

int main(){

    int myints[]={0,1,0,2,1,0,1,3,2,1,2,1};

    vector<int> height(myints,myints+sizeof(myints)/sizeof(int));
    cout<<trap(height)<<endl;
    return 0;

}