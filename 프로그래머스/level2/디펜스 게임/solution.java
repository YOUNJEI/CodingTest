import java.io.*;
import java.util.*;

class Solution {
    public int solution(int n, int k, int[] enemy) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        int cur = 0;
        while (cur < enemy.length) {
            n -= enemy[cur];
            pq.add(enemy[cur]);
            
            if (n < 0) {
                if (k < 1)
                    return cur;
                while (n < 0 && k > 0 && pq.size() > 0) {
                    Integer top = pq.poll();
                    n += top;
                    k--;
                }
                if (n < 0)
                    return cur;
            }
            cur++;
        }
        return cur;
    }
}
