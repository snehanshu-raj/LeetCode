Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

class Solution {
public:
    int missingNumber(vector<int>& a) {
        
        int s1 = 0, s2 = 0;
        int i;
        
        for(i = 0; i < a.size(); i++)
            s1 += a[i];
        
        for(i = 1;i <= a.size(); i++)
            s2 += i;
        
        return s2 - s1;
    }
};