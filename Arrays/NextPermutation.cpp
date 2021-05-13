// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

// The replacement must be in place and use only constant extra memory.

class Solution {
public:
    void nextPermutation(vector <int> &a) {
        
        int n = a.size();
        int i, j = n - 2;
        
        while(j >= 0)
        {
            if(a[j] < a[j + 1])
                break;
            
            j--;
        }
        
        if(j < 0)
        {
            sort(a.begin(), a.end());
            return;
        }
        
        int min_diff = INT_MAX, min_diff_ind;
        
        int k = j;
        for(i = k + 1; i < n; i++)
        {
            if(min_diff > (a[i] - a[j]) && a[i] > a[j])
            {
                min_diff = a[i] - a[j];
                min_diff_ind = i;
            }
        }
        
        swap(a[j], a[min_diff_ind]);
        
        sort(a.begin() + j + 1, a.end());
    }
};