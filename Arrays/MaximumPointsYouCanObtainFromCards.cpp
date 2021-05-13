// There are several cards arranged in a row, and each card has an associated number of points The points are given in the integer array cardPoints.

// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

// Your score is the sum of the points of the cards you have taken.

// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

class Solution {
public:
    int maxScore(vector<int> &a, int k) {
        
        int i = 0, j = a.size() - 1;
        
        if(k == a.size())
        {
            int sum = 0;
            for(i = 0; i < k; i++)
                sum += a[i];
            return sum;
        }
        
        int sum = 0, ans = 0;
        
        for(i = 0; i < k; i++)
            sum += a[i];
        
        i = k - 1;
        ans = sum;
        
        while(k--)
        {
            sum += a[j] - a[i];
            ans = max(ans, sum);
            
            i--;
            j--;
        }
        
        return ans;
    }
};