Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

class Solution {
public:
    int jump(vector<int>& a) {
        
        if(a.size() <= 1)
            return 0;
        
        int i, ans = 1;
        int maxi = a[0];
        int updated_maxi = a[0];
        int j = 0;
        
        for(i = 1; i < a.size() - 1; i++)
        {
            j++;
            maxi = max(maxi, i + a[i]);
            if(j == cur_maxi)
            {
                ans++;
                updated_maxi = maxi - i;
                j = 0;
            }
        }
        
        return ans;
    }
};