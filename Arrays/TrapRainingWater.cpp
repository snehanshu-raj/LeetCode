// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
class Solution {
public:
    int trap(vector<int>& a) {
        
        int area = 0, i = 0;
        stack <int> s;
        
        while(i < a.size())
        {
            while(!s.empty() && a[i] > a[s.top()])
            {
                int t = s.top();
                s.pop();
                
                if(s.empty())
                    break;
                
                int d = i - s.top() - 1;
                int h = min(a[i], a[s.top()]) - a[t];
                area += d * h;
            }
            
            s.push(i++);
        }
        
        return area;
    }
};