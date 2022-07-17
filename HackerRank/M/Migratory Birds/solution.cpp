int migratoryBirds(vector<int> arr) {
    int answer = 1;
    int maxNum;
    
    for (int i = 0; i < arr.size(); i++) {
        g_count[arr[i]]++;
    }
    maxNum = g_count[1];
    for (int i = 2; i <= BUFFER_SIZE; i++) {
        if (g_count[i] > maxNum) {
            maxNum = g_count[i];
            answer = i;
        }
    }
    return answer;
}
