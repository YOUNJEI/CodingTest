#include <string>
#include <vector>

using namespace std;

vector<int> solve(long long n)
{
    vector<int> temp;
    
    if (n == 0)
    {
        temp.push_back(0);
        return (temp);
    }
    while (n != 0)
    {
        temp.push_back(n % 10);
        n /= 10;
    }
    return (temp);
}

vector<int> solution(long long n) {
    vector<int> answer;
    answer = solve(n);
    return answer;
}
