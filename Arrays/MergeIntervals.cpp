Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        
        a.push_back(b);
        sort(a.begin(), a.end());
           
        vector < vector <int> > ans;
        
        ans.push_back(a[0]);
        int i, j = 0;
        
        for(i = 1; i < a.size(); i++)
        {
            if(ans[j][1] >= a[i][0])
            {
                ans[j][1] = max(ans[j][1], a[i][1]);
            }
            else
            {
                ans.push_back(a[i]);
                j++;
            }
        }
        
        return ans;
    }
};