class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int directions[][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        
        int r = grid.size();
        int c = grid[0].size();
        
        vector < vector <int> > temp(r, vector <int> (c, 0));
        
        int i, j, ans = 0, area = 0;
        
        for(i = 0; i < r; i++)
        {
            for(j = 0; j < c; j++)
            {
                if(grid[i][j] == 1)
                {
                    if(temp[i][j] == 0)
                    {
                        ans = 1;
                        
                        queue < pair <int, int> > q;
                        q.push({i, j});
                        
                        while(!q.empty())
                        {
                            pair <int, int> p = q.front();
                            q.pop();
                            
                            int ci = p.first;
                            int cj = p.second;
                            
                            temp[i][j] = 1;
                            for(int k = 0; k < 4; k++)
                            {
                                int ni = ci + directions[k][0];
                                int nj = cj + directions[k][1];
                                
                                if(ni >= 0 and ni < r and nj >= 0 and nj < c and 
                                    grid[ni][nj] == 1 and temp[ni][nj] == 0)
                                {
                                    temp[ni][nj] = 1;
                                    q.push({ni, nj});
                                    ans++;
                                }
                            }
                        }
                        
                        area = max(area, ans);
                    }
                }
            }
        }
        
        return area;
    }
};