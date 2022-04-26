#include <string>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

typedef struct s_node
{
    int id;
    struct s_node* prev;
    struct s_node* next;
    s_node(int n, s_node* pr, s_node* ne) : id(n), prev(pr), next(ne) {}
}t_node;

t_node* g_cur;
stack<t_node*> g_stack;

void cmd_UX(int X)
{
    int i = 0;
    
    while (i < X)
    {
        g_cur = g_cur->prev;
        i++;
    }
}

void cmd_DX(int X)
{
    int i = 0;
    
    while (i < X)
    {
        g_cur = g_cur->next;
        i++;
    }
}

void cmd_C(void)
{
    g_stack.push(g_cur);
    if (g_cur->prev != NULL)
        g_cur->prev->next = g_cur->next;
    if (g_cur->next != NULL)
        g_cur->next->prev = g_cur->prev;
    if (g_cur->next == NULL)
        g_cur = g_cur->prev;
    else
        g_cur = g_cur->next;
}

void cmd_Z(void)
{
    t_node *temp = g_stack.top();
    g_stack.pop();
    
    if (temp->prev != NULL)
        temp->prev->next = temp;
    if (temp->next != NULL)
        temp->next->prev = temp;
}

vector<string> split(string input, char delimiter)
{
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');
    t_node *c_temp;
    int i, cmd_num;
    
    g_cur = new t_node(0, NULL, NULL);
    c_temp = g_cur;
    i = 1;
    while (i < n)
    {
        g_cur->next = new t_node(i, g_cur, NULL);
        g_cur = g_cur->next;
        i++;
    }
    g_cur = c_temp;
    cmd_DX(k);
    
    i = 0;
    while (i < cmd.size())
    {
        switch (cmd[i][0])
        {
            case 'U':
                cmd_num = stoi(cmd[i].substr(2));
                cmd_UX(cmd_num);
                break;
                
            case 'D':
                cmd_num = stoi(cmd[i].substr(2));
                cmd_DX(cmd_num);
                break;
                
            case 'C':
                cmd_C();
                break;
                
            case 'Z':
                cmd_Z();
                break;
        }
        i++;
    }
    
    c_temp = g_cur;
    while (g_cur != NULL)
    {
        answer[g_cur->id] = 'O';
        g_cur = g_cur->prev;
    }
    g_cur = c_temp;
    while (g_cur != NULL)
    {
        answer[g_cur->id] = 'O';
        g_cur = g_cur->next;
    }
    return answer;
}
