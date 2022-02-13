Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int k) {
        
        vector <int> ans;
        unordered_map <int, int> m;
        
        int i;
        m[a[0]] = 1;
        for(i = 1; i < a.size(); i++)
        {
            if(m[k - a[i]] > 0)
            {
                if(i != m[k - a[i]] - 1)
                {
                    ans.push_back(i);
                    ans.push_back(m[k - a[i]] - 1);
                    return ans;
                }
            }
            m[a[i]] = i + 1;
        }
        
        return ans;
    }
};