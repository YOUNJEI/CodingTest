#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define BUFFER_SIZE 50000
bool g_visit[BUFFER_SIZE];

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    int left = people.size();
    int i = 0;
    while (i < people.size() && left > 0) {
        if (g_visit[i]) {
            i++;
            continue;
        }
        int temp = limit - people[i];
        int j = upper_bound(people.begin(), people.end(), temp) - people.begin() - 1;
        while (j > i) {
            if (temp >= people[j] && !g_visit[j])
                break;
            j--;
        }
        if (j <= i) {
            g_visit[i] = true;
            left--;
        } else {
            g_visit[i] = true;
            g_visit[j] = true;
            left -= 2;
        }
        answer++;
        i++;
    }
    return answer;
}
