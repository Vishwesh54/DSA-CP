#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<vector<char>>& board ,int row ,int col ,char c){
    for(int i=0 ; i<9 ; i++){
        if(board[row][i]==c)
            return false;
        if(board[i][col]==c)
            return false;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
            return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board){
    for(int i=0 ; i<9 ;i++){
        for(int j=0 ;j<9 ;j++){
            if(board[i][j]=='.'){
                for(char c='1' ; c<='9'; c++){
                    if(isvalid(board,i,j,c)){
                        board[i][j]=c;
                        if(solve(board)==true)
                            return true;
                        else    
                            board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board);    
}

int main(){
    vector<vector<char>> board = {          // '.' denotes empty spaces
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
    };   
    
    //User input 
    vector<vector<char>> sudoku(9,vector<char>(9,'.'));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>sudoku[i][j];
        }
    }
    /* example
    .7.5.31..
    ..41.....
    .5.......
    2.6..5..7
    ..16.29..
    9..3..2.6
    .......9.
    .....73..
    ..29.4.5.
    */

    solveSudoku(sudoku);

    for(auto i:sudoku){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}