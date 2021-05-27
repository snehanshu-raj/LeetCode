You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

class Solution {
public:
    void rotate(vector<vector<int>>& m) {
                
        int n = m.size();
        int i, j;
        
        for(i = 0; i < (n + 1) / 2; i++)
        {
            for(j = 0; j < n / 2; j++)
            {
                int t = m[n - j - 1][i];
                m[n - j - 1][i] = m[n - i - 1][n - j - 1];
                m[n - i - 1][n - j - 1] = m[j][n - i - 1];
                m[j][n - i - 1] = m[i][j];
                m[i][j] = t;
            }
        }
        
        //         int i, j;
//         int n = m.size();
        
//         for(i = 0; i < n; i++)
//         {
//             vector <int> t;
//             for(j = n - 1; j >= 0; j--)
//             {
//                 t.push_back(m[j][i]);
//             }
            
//             m.push_back(t);
//         }
        
//         for(i = 0; i < n; i++)
//             m.erase(m.begin());
    }
};