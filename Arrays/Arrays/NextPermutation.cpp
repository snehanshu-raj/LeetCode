// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

// The replacement must be in place and use only constant extra memory.

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        
        int i, j = a.size() - 2;
        
        while(j >= 0 and a[j + 1] <= a[j])
        {
            j--;
        }
        
        if(j >= 0)
        {
            i = a.size() - 1;
            while(a[i] <= a[j])
            {
                i--;
            }
            
            swap(a[i], a[j]);
        }
        reverse(a.begin() + j + 1, a.end());
    }
};