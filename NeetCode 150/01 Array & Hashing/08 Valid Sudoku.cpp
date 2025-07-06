// Question = Leetcode - 36

bool isValidRow(int row,vector<vector<char>>& board){
    unordered_set<char> s1;
    for(int i=0;i<9;i++){
        if(board[row][i] == '.'){
            continue;
        }
        if(s1.find(board[row][i]) != s1.end()){
            return 0;
        }
        s1.insert(board[row][i]);
    }
    return 1;
} 

bool isValidColumn(int col,vector<vector<char>>& board){
    unordered_set<char> s1;
    for(int i=0;i<9;i++){
        if(board[i][col] == '.'){
            continue;
        }
        if(s1.find(board[i][col]) != s1.end()){
            return 0;
        }
        s1.insert(board[i][col]);
    }
    return 1;
} 

bool isValidGrid(int row, int col,vector<vector<char>>& board){
    unordered_set<char> s1;
    for(int i=row;i<row + 3;i++){
        for(int j=col;j<col+3;j++){
            if(board[i][j] == '.'){
                continue;
            }
            if(s1.find(board[i][j]) != s1.end()){
                return 0;
            }
            s1.insert(board[i][j]);
        }
    }
    return 1;
} 

bool isValidSudoku(vector<vector<char>>& board) {
    // row
    for(int i=0;i<9;i++){
        if(isValidRow(i,board) == 0){
            return 0;
        }
    }

    // column
    for(int i=0;i<9;i++){
        if(isValidColumn(i,board) == 0){
            return 0;
        }  
    }
    

    // Grid
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(i % 3 == 0 && j % 3 == 0){
                if(isValidGrid(i,j,board) == 0){
                    return 0;
                }
            }
        }
    }
    return 1;
}