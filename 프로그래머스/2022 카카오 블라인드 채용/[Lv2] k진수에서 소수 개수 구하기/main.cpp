#include <string>
#include <vector>
#include <iostream>

using namespace std;

string convert_base(int n, int k, int depth)
{
    static string base = "0123456789";
    static string converted;
    if (depth == 0)
        converted = "";
    if (n != 0)
    {
        convert_base(n / k, k, depth + 1);
        converted += base[n % k];
    }
    return (converted);
}

bool isPrimeNum(long num)
{
    long long div;
    
    if (num == 0 || num == 1)
        return (false);
    if (num == 2)
        return (true);
    div = 3;
    while (div * div <= num)
    {
        if (num % div == 0)
            return (false);
        div++;
    }
    return (true);
}

int findPrimeCount(string newNum)
{
    int i, j;
    int count = 0;
    string temp;
    
    i = 0;
    while (i < newNum.length())
    {
        j = i;
        while (j < newNum.length())
        {
            if (newNum[j] == '0')
                break;
            j++;
        }
        temp = newNum.substr(i, j - i);
        if (temp != "" && isPrimeNum(stol(temp)))
            count++;
        i = j + 1;
    }
    return (count);
}

int solution(int n, int k) {
    int answer = -1;
    string newNum = convert_base(n, k, 0);
    answer = findPrimeCount(newNum);
    
    return answer;
}
