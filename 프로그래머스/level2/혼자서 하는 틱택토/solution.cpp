#include <string>
#include <vector>
using namespace std;

int countMark(const vector<string>& board, const char c) {
    int count = 0;
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].length(); j++) {
            if (board[i][j] == c)
                count++;
        }
    }
    return count;
}

bool checkWin(const vector<string>& board, const char c) {
    bool win = false;
    
    for (int i = 0; i < board.size(); i++) {
        if (board[i][0] != c)
            continue;
        win = true;
        for (int j = 1; j < board[i].length(); j++) {
            if (board[i][j] != c) {
                win = false;
                break;
            }
        }
        if (win)
            return win;
    }
    
    for (int i = 0; i < board[0].length(); i++) {
        if (board[0][i] != c)
            continue;
        win = true;
        for (int j = 1; j < board.size(); j++) {
            if (board[j][i] != c) {
                win = false;
                break;
            }
        }
        if (win)
            return win;
    }
    
    win = true;
    for (int i = 0; i < board.size(); i++) {
        if (board[i][i] != c) {
            win = false;
            break;
        }
    }
    if (win)
        return win;
    
    win = true;
    for (int i = 0; i < board.size(); i++) {
        if (board[i][2 - i] != c) {
            win = false;
            break;
        }
    }
    return win;
}

int solution(vector<string> board) {
    int count[2] = {0, 0};
    count[0] = countMark(board, 'O');
    count[1] = countMark(board, 'X');
    if (count[1] > count[0])
        return 0;
    if (count[0] - count[1] > 1)
        return 0;
    
    bool oWin = checkWin(board, 'O');
    bool xWin = checkWin(board, 'X');
    
    if (oWin && xWin)
        return 0;
    if (oWin && count[0] - count[1] != 1)
        return 0;
    if (xWin && count[0] != count[1])
        return 0;
    return 1;
}
