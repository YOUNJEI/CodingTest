import java.io.*;
import java.util.*;

class Solution {
    private Map<String, Integer> m = new HashMap<>();
    private String charset = "AEIOU";
    
    public void dfs(String make) {
        
        if (make.length() >= 1)
            m.put(make, m.size() + 1);
        if (make.length() == charset.length())
            return;
        for (int i = 0; i < charset.length(); i++)
            dfs(make + charset.charAt(i));
    }
    
    public int solution(String word) {
        int answer = 0;
        
        dfs("");
        return m.get(word);
    }
}
