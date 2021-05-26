// Given an unsorted integer array nums, find the smallest missing positive integer.

// You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

// Example 1:

// Input: nums = [1,2,0]
// Output: 3
// Example 2:

// Input: nums = [3,4,-1,1]
// Output: 2

class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
    
        if(a.size() == 0)
            return 1;
        
        int i;
        for(i = 0; i < a.size(); i++)
        {
            while(a[i] > 0 && a[i] <= a.size() && a[i] != a[a[i] - 1])
                swap(a[i], a[a[i] - 1]);
        }
        
        for(i = 0; i < a.size(); i++)
        {
            if(a[i] != i + 1)
                return i + 1;
        }
        
        return a.size() + 1;
    }
};