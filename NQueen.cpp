#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row ,int col, vector<string>& board, int n){
    for(int i=0;i<row;++i){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0  && j>=0;--i,--j){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0 && j<n;--i,++j){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}

void solve(int row,vector<string>& board,vector<vector<string>>& solution,int n){
    if(row==n){
        solution.push_back(board);
        return;
    }
    
    for(int col=0;col<n;++col){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(row+1,board,solution,n);
            board[row][col]='.';
        }
    }
}

void solveNQueen(int n){
    vector<vector<string>> solution;
    vector<string> board(n,string(n,'.'));
    
    solve(0,board,solution,n);
    for(const auto& sol :solution){
        for(const auto& row: sol){
            cout << row <<endl;
        }
    cout<<endl;
    }
    
    cout<< "Total solution : "<<solution.size()<<endl;
}

int main() {
    // Write C++ code here
    int n;
    cout<<"Enter value of n: ";
    cin>>n;
    solveNQueen(n);
    return 0;
}
