int dfs(vector<int> &ar, int cur, int sum, int count, int target) {
     static int answer = 0;
     
     if (cur == 0) {
         answer = 0;
     }
     if (count == 0) {
         if (sum % target == 0) {
             answer++;
         }
         return answer;
     }
     if (count > 0 && cur < ar.size()) {
         dfs(ar, cur + 1, sum + ar[cur], count - 1, target);
         dfs(ar, cur + 1, sum, count, target);
     }
     return answer;
 }

int divisibleSumPairs(int n, int k, vector<int> ar) {
    int answer = 0;
    
    answer = dfs(ar, 0, 0, 2, k);
    return answer;
}
