#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    static int dx[] = {1, -1, 0, 0};
    static int dy[] = {0, 0, 1, -1};
    
    const string& ref = board[h][w];
    for (int i = 0; i < 4; i++) {
        int nx = h + dx[i];
        int ny = w + dy[i];
        
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[nx].size() && board[nx][ny] == ref)
            answer++;
    }
    return answer;
}
