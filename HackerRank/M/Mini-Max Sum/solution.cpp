void miniMaxSum(vector<int> arr) {
    long sum[2] = {0, 0};
    
    sort(arr.begin(), arr.end());
    for (int i = 0; i < 4; i++) {
        sum[0] += arr[i];
        sum[1] += arr[arr.size() -1 -i];
    }
    cout << sum[0] << " " << sum[1];
}
