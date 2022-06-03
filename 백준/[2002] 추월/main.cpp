#include <iostream>
#include <queue>
#include <set>
using namespace std;

int N;

int solution(queue<string> &q1, queue<string> &q2)
{
    int answer = 0;
    string in, out;
    set<string> s;

    while (!q1.empty() && !q2.empty())
    {
        in = q1.front();
        q1.pop();

        out = q2.front();
        q2.pop();
        s.insert(out);

        if (in == out)
            continue;
        if (s.find(in) != s.end())
            continue;
        answer++;
        while (!q2.empty())
        {
            out = q2.front();
            q2.pop();

            s.insert(out);

            if (in == out)
                break ;
            answer++;
        }
    }
    return (answer);
}

int main(void)
{
    string input;
    queue<string> q1;
    queue<string> q2;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        q1.push(input);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        q2.push(input);
    }

    cout << solution(q1, q2) << '\n';
    return (0);
}