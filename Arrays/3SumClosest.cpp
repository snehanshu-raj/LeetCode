class Solution {
public:
    int threeSumClosest(vector<int>& a, int k) {
        
        int i = 0, left, right;
        int diff = INT_MAX, ans;
        sort(a.begin(), a.end());
        
        while(i < a.size() - 2)
        {
            left = i + 1;
            right = a.size() - 1;
            
            while(left < right)
            {
                int temp_sum = a[i] + a[left] + a[right];
                int temp_diff = abs(temp_sum - k);
                
                if(temp_sum == k)
                    return k;
                
                if(temp_diff < diff)
                {
                    diff = temp_diff;
                    ans = temp_sum;
                }
                
                if(temp_sum > k)
                    right--;
                else
                    left++;
            }
            
            i++;
        }
        
        return ans;        
    }
};