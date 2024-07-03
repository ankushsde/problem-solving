class Solution {
public:

    bool floodFill(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j, vector<vector<int>> &visited){
        if(i<0 || j< 0 || i>=grid1.size() || j>= grid1[0].size() || visited[i][j] != 0 || grid2[i][j] == 0){
            return true;
        }
        visited[i][j] = 1;
        bool res = true;
        if(grid1[i][j] == 0){
            res = false;
        }

        res = floodFill(grid1,grid2, i-1, j, visited) && res;
        res = floodFill(grid1,grid2, i, j-1, visited) && res;
        res = floodFill(grid1,grid2, i+1, j, visited) && res;
        res = floodFill(grid1,grid2, i, j+1, visited) && res;

        return res;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int r = grid2.size();
        int c = grid2[0].size();

        vector<vector<int>> visited(r,vector<int> (c,0));
        int count = 0 ; 
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid2[i][j] == 1 && !visited[i][j] && floodFill(grid1,grid2,i,j,visited)){
                    count++;
                }
            }
        }
        return count;
    }
};
