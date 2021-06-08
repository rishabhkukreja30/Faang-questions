


    int N, M;
    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};
    
    void dfs(int i, int j, vector<vector<int>>& grid, int& area) {
        grid[i][j] = 0;
        area++;
        
        for(int dir=0;dir<4;dir++) {
            int xd=i+x[dir];
            int yd=j+y[dir];
            
            if(xd>=0 && yd>=0 && xd<=M-1 && yd<=N-1){
                if(grid[xd][yd] == 1){
                    dfs(xd, yd, grid, area);
                }
            }
        }
        return;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j]) {
                    int area = 0;
                    dfs(i, j, grid, area);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }





    