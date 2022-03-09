Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        
        sort(a.begin(), a.end());
        vector < vector <int> > ans;
        
        int i;
        
        ans.push_back(a[0]);
        for(i = 1; i < a.size(); i++)
        {
            if(ans.back()[1] < a[i][0])
                ans.push_back(a[i]);
            else
            {
                ans.back()[1] = max(ans.back()[1], a[i][1]);
            }
        }
        return ans;
    }
};