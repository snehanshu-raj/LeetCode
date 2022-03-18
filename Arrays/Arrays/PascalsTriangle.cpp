Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector < vector <int> > ans;
        
        vector <int> t1 = {1};
        ans.push_back(t1);
        
        if(n == 1)
            return ans;
        
        t1.push_back(1);
        ans.push_back(t1);
        
        if(n == 2)
            return ans;
        
        for(int i = 3; i <= n; i++)
        {
            vector <int> temp(i);
            temp[0] = 1;
            temp[i - 1] = 1;
            
            int ptr = 0;
            for(int j = 1; j < i - 1; j++)
            {
                temp[j] = ans[i - 2][ptr] + ans[i - 2][ptr + 1];
                ptr++;
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};