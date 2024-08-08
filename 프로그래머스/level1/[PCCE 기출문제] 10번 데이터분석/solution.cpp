#include <string>
#include <vector>
#include <queue>
using namespace std;

int g_IDX = -1;

struct compare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[g_IDX] > b[g_IDX];
    }
};

int get_idx_position(const string& by) {
    if (by == "code")
        return 0;
    else if (by == "date")
        return 1;
    else if (by == "maximum")
        return 2;
    else
        return 3;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    const int idx_ext = get_idx_position(ext);
    g_IDX = get_idx_position(sort_by);
    
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;
    for (int i = 0; i < data.size(); i++) {
        if (data[i][idx_ext] >= val_ext)
            continue;
        pq.push(data[i]);
    }
    while (!pq.empty()) {
        answer.push_back(pq.top());
        pq.pop();
    }
    return answer;
}
