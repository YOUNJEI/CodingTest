int birthday(vector<int> s, int d, int m) {
    int i, j;
    int answer = 0;
    
    i = 0;
    while (i < s.size()) {
        int sumCount = 0;
        j = 0;
        while (i + j < s.size() && j < m) {
            sumCount += s[i + j];
            j++;
        }
        if (j == m && sumCount == d) {
            answer++;
        }
        i++;
    }
    return answer;
}
