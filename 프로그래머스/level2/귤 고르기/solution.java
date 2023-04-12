import java.io.*;
import java.util.*;

class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        
        Map<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < tangerine.length; i++) {
            Integer temp = m.get(tangerine[i]);
            if (temp == null)
                m.put(tangerine[i], 1);
            else
                m.put(tangerine[i], temp + 1);
        }
        List<Map.Entry<Integer, Integer>> lm = new LinkedList(m.entrySet());
        lm.sort(new Comparator<Map.Entry<Integer, Integer>>() {
           @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                return o2.getValue() - o1.getValue();
            }
        });
        
        int count = 0;
        for (int i = 0; i < lm.size(); i++) {
            count += lm.get(i).getValue();
            answer++;
            if (count >= k)
                break;
        }
        return answer;
    }
}
