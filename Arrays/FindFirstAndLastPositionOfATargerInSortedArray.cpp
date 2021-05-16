int l = INT_MAX;
int r = INT_MIN;
int f = 0;

class Solution {
public:
    
    void search(vector <int> &ans, vector <int> &a, int s, int e, int t)
    {
        if(s <= e)
        {
            int m = (s + e) / 2;
            
            if(a[m] == t)
            {
                if(f == 0)
                {
                    ans[0] = ans[1] = m;
                    f = 1;
                }
                
                if(m < l)
                {
                    l = m;
                    ans[0] = m;
                }
                
                if(m > r)
                {
                    r = m;
                    ans[1] = m;
                }
                
            }
            
            if(t >= a[m])
            {
                search(ans, a, m + 1, e, t);
            }
            if(t <= a[m])
            {
                search(ans, a, s, m - 1, t);
            }                
        }
    }
    
    vector<int> searchRange(vector<int>& a, int t) {
        
        vector <int> ans(2, -1);
        l = INT_MAX;
        r = INT_MIN;
        f = 0;
        search(ans, a, 0, a.size() - 1, t);
        
        return ans;
    }
};