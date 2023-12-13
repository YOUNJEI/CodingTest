#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int now = health;
    int prevSec = 0;
    
    for (int i = 0; i < attacks.size(); i++) {
        int diffSec = attacks[i][0] - prevSec - 1;
        prevSec = attacks[i][0];
        
        int restoreHp = diffSec * bandage[1];
        restoreHp += (diffSec / bandage[0]) * bandage[2];
        now = min(now + restoreHp, health);
        
        now -= attacks[i][1];
        if (now <= 0)
            return -1;
    }
    return now;
}
