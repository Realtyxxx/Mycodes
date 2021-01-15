/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (64.50%)
 * Likes:    407
 * Dislikes: 0
 * Total Accepted:    109.4K
 * Total Submissions: 169.6K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */

// @lc code=start
class Solution {
private:
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
    vector<int> sequence;
public:
    void dfs(int pos,int rest){
        if(rest==0){
            ans.push_back(sequence);
            return;
        }
        if(pos==freq.size()||rest<freq[pos].first){
            return;
        }
        dfs(pos+1,rest);
        int most=min(rest/freq[pos].first,freq[pos].second);
        for(int i=1;i<=most;++i){
            sequence.push_back(freq[pos].first);
            dfs(pos+1,rest-i*freq[pos].first);
        }
        for(int i=1;i<=most;++i){
            sequence.pop_back();
        }
    }



    vector<vector<int>> combinationSum2(vector<int>& candidates,int target) {
        sort(candidates.begin(),candidates.end());
        for(int num:candidates){
            if(freq.empty()||num!=freq.back().first){
                freq.emplace_back(num,1);
            }else{
                ++freq.back().second;
            }
        }
        dfs(0,target);
        return ans;
    }
};
// @lc code=end

