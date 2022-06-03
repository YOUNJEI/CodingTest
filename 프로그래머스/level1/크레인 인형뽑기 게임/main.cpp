#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    
    for (int i = 0; i < moves.size(); i++)
    {
        int cur = moves[i] - 1;
        int tok = 0;
        
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][cur] != 0)
            {
                tok = board[i][cur];
                board[i][cur] = 0;
                break ;
            }
        }
        if (tok != 0)
        {
            if (!s.empty() && s.top() == tok)
            {
                s.pop();
                answer += 2;
            }
            else
                s.push(tok);
        }
    }
    return answer;
}
