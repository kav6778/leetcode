/* https://leetcode.com/problems/surrounded-regions/description/
    Given a matrix, capture ('X') all regions that are surrounded ('O')

    Distinguish captured vs escaped, 'X' vs 'O' vs 'E'

    Time: O(m x n)
    Space: O(m x n)
*/
class Solution {
public:
    int n,m;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    pair<int,int> par[1010][1010];
    bool inside(int x, int y){
        return (x>=0 && x<n && y>=0 && y<m);
    }
    void bfs(vector<vector<char>>& board, int i,int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            pair<int,int>cur = q.front();
            q.pop();
            board[cur.first][cur.second] = '1';
            for(int k=0; k<4; k++){
                int newx = cur.first + dx[k];
                int newy = cur.second + dy[k];
                //set all the connected 'O's to a temp character '1' 
                //so that we will get all the regions which do not satisfy the condition
                if(inside(newx,newy) && board[newx][newy] == 'O'){
                        board[newx][newy] = '1';
                        q.push({newx,newy}); 
                }  
            }
        }
    }



void solve(vector<vector<char>>& board) {
       
        n= board.size();
        m=board[0].size();
        //We will first check all the borders for 'O'
        //left and top border 
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')
                bfs(board,i,0);
            if(board[i][m-1]=='O')
                bfs(board,i,m-1);
        }
        //bottom and right 
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O')
                bfs(board,0,i);
            if(board[n-1][i]=='O')
                bfs(board,n-1,i);
        }
        //We will flip all the '1's back to 'O's
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(board[i][j]=='1')
                    board[i][j] = 'O';
                else if(board[i][j]=='O')
                    board[i][j] = 'X';
    }
};
