// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
    int b_search(vector<int>& a, int s, int e, int k)
    {
        if(s > e)
            return -1;
        
        int m = (s + e) / 2;
        
        if(a[m] == k)
            return m;
        
        if(a[s] <= a[m])
        {
            if(k >= a[s] && k <= a[m])
            {
                return b_search(a, s, m, k);
            }
            
            return b_search(a, m + 1, e, k);
        }
        
        if(k >= a[m] && k <= a[e])
            return b_search(a, m + 1, e, k);
        
        return b_search(a, s, m - 1, k);
    }
    
    int search(vector<int>& a, int k) {
        
        return b_search(a, 0, a.size() - 1, k);
    }
};