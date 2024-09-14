/*
 * @lc app=leetcode.cn id=1 lang=csharp
 *
 * [1] 两数之和
 */

// @lc code=start
public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        for (int i = 0; i < nums.Count(); i++)
        {
            int d = target - nums[i];
            if (nums.Contains(d))
            {
                for (int j = i + 1; j < nums.Count(); j++)
                {
                    if (nums[j] == d)
                        return[i, j];
                }
            }
        }
        return null;
    }
}
// @lc code=end

