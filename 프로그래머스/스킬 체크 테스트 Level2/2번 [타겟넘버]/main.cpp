#include <string>
#include <vector>

using namespace std;

int makeanswer(vector<int> &numbers, int target, int idx, int sum)
{
    static int count = 0;
    
    if (idx == numbers.size() && sum == target)
        count++;
    if (idx < numbers.size())
    {
        makeanswer(numbers, target, idx + 1, sum + numbers[idx]);
        makeanswer(numbers, target, idx + 1, sum - numbers[idx]);
    }
    return (count);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    answer = makeanswer(numbers, target, 0, 0);
    return (answer);
}