class Solution {
public:
    bool isValidSudoku(vector<vector<char>>&board){
    
    vector<unordered_set<char>>rows(9);
    vector<unordered_set<char>>cols(9);
    vector<unordered_set<char>>boxes(9);
    for(int r=0;r<9;r++){
        for(int c=0;c<9;c++){
            if(board[r][c]=='.'){
                continue;
            }
            char num = board[r][c];
           //calculate box index
           int boxIndex = (r/3)*3+(c/3);
           //Check  Duplicate
           if(rows[r].count(num)|| cols[c].count(num)|| boxes[boxIndex].count(num)){
            return false;
            
        }
        //Insert into sets
        
        
        rows[r].insert(num);
        cols[c].insert(num);
        boxes[boxIndex].insert(num);
        
        
        
        
    }
    }
    return true;
    
    
    }
    };