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