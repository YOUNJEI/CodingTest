void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int count[2] = {0, 0};
    
    for (int i = 0; i < apples.size(); i++) {
        if (a + apples[i] >= s && a + apples[i] <= t) {
            count[0]++;
        }
    }
    for (int i = 0; i < oranges.size(); i++) {
        if (b + oranges[i] >= s && b + oranges[i] <= t) {
            count[1]++;
        }
    }
    cout << count[0] << "\n";
    cout << count[1];
}
