#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 三数之和
#
# https://leetcode-cn.com/problems/3sum/description/
#
# algorithms
# Medium (28.11%)
# Likes:    2329
# Dislikes: 0
# Total Accepted:    266.4K
# Total Submissions: 939.5K
# Testcase Example:  '[-1,0,1,2,-1,-4]'
#
# 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
# ？请你找出所有满足条件且不重复的三元组。
#
# 注意：答案中不可以包含重复的三元组。
#
#
#
# 示例：
#
# 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
#
# 满足要求的三元组集合为：
# [
# ⁠ [-1, 0, 1],
# ⁠ [-1, -1, 2]
# ]
#
#
#

# @lc code=start


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        ans = list()
        for first in range(n):
            if first > 0 and nums[first] == nums[first-1]:
                continue
            third = n-1
            target = -nums[first]
            for second in range(first+1, n):
                if second > first+1 and nums[second] == nums[second-1]:
                    continue
                while second < third and nums[second]+nums[third] > target:
                    third -= 1
                if second == third:
                    break
                if nums[second]+nums[third] == target:
                    ans.append([nums[first], nums[second], nums[third]])
        return ans


# @lc code=end
