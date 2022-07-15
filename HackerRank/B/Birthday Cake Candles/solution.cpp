int birthdayCakeCandles(vector<int> candles) {
    int maxNum = 0;
    int count = 0;
    
    for (int i = 0; i < candles.size(); i++) {
        if (candles[i] > maxNum) {
            maxNum = candles[i];
            count = 1;
        }
        else if (candles[i] == maxNum) {
            count++;
        }
    }
    return (count);
}
