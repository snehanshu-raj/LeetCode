// Given an array nums and a value val, remove all instances of that value in-place and return the new length.

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// The order of elements can be changed. It doesn't matter what you leave beyond the new length.

// Clarification:

// Confused why the returned value is an integer but your answer is an array?

// Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller as well.


class Solution {
public:
    int removeElement(vector<int>& a, int k) {
        
        int n = a.size();
        int i = 0, j = n - 1;
        
        while(j >= 0)
        {
            if(a[j] != k)
                break;
            j--;
        }
        
        int ans = 0;
        while(i < j)
        {
            if(a[i] == k)
            {
                swap(a[i], a[j]);
                j--;
                
                if(a[j] == k)
                {
                    while(a[j] == k)
                        j--;
                }
            }
            
            i++;
        }
        
        for(i = 0; i < n; i++)
        {
            if(a[i] != k)
                ans++;
            else
                break;
        }
        
        return ans;
    }
};