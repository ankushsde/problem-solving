class Solution {
    bool check(string gen,string word){
        for(int i=0;i<gen.size();i++){
            if(gen[i] != word[i] and gen[i] != '$') return false; 
        }
        return true;
    }
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        vector<string>res;
        
        //for rows
        for(int i=0;i<n;i++){
            string str = "";
            int cnt = 0;
            for(int j=0;j<m;j++){
                if(board[i][j] == '#'){
                    if(cnt == word.size()) res.push_back(str);
                    str = "";
                    cnt = 0;
                }else{
                    if(board[i][j] == ' ') str += '$';
                    else str += board[i][j];
                    cnt++;
                } 
            }
            if(cnt == word.size()) res.push_back(str);
        }
        
        //for cols
        for(int j=0;j<m;j++){
            string str = "";
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(board[i][j] == '#'){
                    if(cnt == word.size()) res.push_back(str);
                    str = "";
                    cnt = 0;
                }else{
                    if(board[i][j] == ' ') str += '$';
                    else str += board[i][j];
                    cnt++; 
                } 
            }
            if(cnt == word.size()) res.push_back(str);
        }
        
        
        for(int i=0;i<res.size();i++){
            string str = res[i];
            reverse(str.begin(),str.end());
            if(res[i] == "" || check(res[i],word) || check(str,word)) return true;
        }
        return false;
        
    }
};

// TC: O(nm)
// SC : O(nm)