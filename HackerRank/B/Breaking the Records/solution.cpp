vector<int> breakingRecords(vector<int> scores) {
    vector<int> answer;
    int target[2] {scores[0], scores[0]};
    int count[2] = {0, 0};
    
    for (int i = 1; i < scores.size(); i++) {
        if (scores[i] > target[0]) {
            target[0] = scores[i];
            count[0]++;
        }
        if (target[1] > scores[i]) {
            target[1] = scores[i];
            count[1]++;
        }
    }
    answer.push_back(count[0]);
    answer.push_back(count[1]);
    return answer;
}
