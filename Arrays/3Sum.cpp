// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        
        int i = 0, left = 1, right = a.size() - 1;
        
        vector <int> temp(3);
        vector < vector <int> > ans;
        
        sort(a.begin(), a.end());
        
        if(a.size() < 3)
            return ans;

        while(i < a.size() - 2)
        {
            if(i > 0 && a[i] == a[i - 1])
            {
                i++;
                continue;
            }
            
            left = i + 1;
            right = a.size() - 1;
            
            while(left < right)
            {
                int sum = a[i] + a[left] + a[right];
                
                if(sum == 0)
                {
                    temp[0] = a[i];
                    temp[1] = a[left];
                    temp[2] = a[right];
                    
                    ans.push_back(temp);
                }
                
                if(sum > 0)
                {
                    right--;
                    while(right > left && a[right] == a[right + 1])
                        right--;
                }
                else
                {
                    left++;
                    while(left < right && a[left] == a[left - 1])
                        left++;
                }
            }
            
            i++;
        }
        
        return ans;
    }
};