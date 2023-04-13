import java.io.*;
import java.util.*;

class Solution {
    private static final int dx[] = {1, -1, 0, 0};
    private static final int dy[] = {0, 0 , 1, -1};
    private Map<String, Integer> m = new HashMap<>();
    
    private Integer addQueue(final String[] routes, final Integer lastIdx, Queue<Tuple> q, final Point cur) {
        if (lastIdx < routes.length) {
            String[] s = routes[lastIdx].split(" ");
            q.add(new Tuple(cur, m.get(s[0]), Integer.parseInt(s[1])));
        }
        return lastIdx + 1;
    }
    
    private Point bfs(final String[] park, final String[] routes, final Point start) {
        Queue<Tuple> q = new LinkedList<>();
        String[] first = routes[0].split(" ");
        q.add(new Tuple(start, m.get(first[0]), Integer.parseInt(first[1])));
        Point last = start;
        Integer lastIdx = 1;
        
        while (!q.isEmpty()) {
            Tuple cur = q.poll();
            
            if (cur.left == 0) {
                last = new Point(cur.point.x, cur.point.y);
                lastIdx = addQueue(routes, lastIdx, q, cur.point);
                continue;
            }
            
            int nr = cur.point.x + dx[cur.dir];
            int nc = cur.point.y + dy[cur.dir];
            if (nr >= 0 && nr < park.length && nc >= 0 && nc < park[nr].length() && park[nr].charAt(nc) != 'X') {
                q.add(new Tuple(new Point(nr, nc), cur.dir, cur.left - 1));
            } else {
                while (!q.isEmpty())
                    q.poll();
                lastIdx = addQueue(routes, lastIdx, q, last);
            }
        }
        return last;
    }
    
    public int[] solution(String[] park, String[] routes) {
        int[] answer = new int[2];
        m.put("S", 0);
        m.put("N", 1);
        m.put("E", 2);
        m.put("W", 3);
        
        for (int i = 0; i < park.length; i++) {
            for (int j = 0; j < park[i].length(); j++) {
                if (park[i].charAt(j) == 'S') {
                    Point a = bfs(park, routes, new Point(i, j));
                    answer[0] = a.x;
                    answer[1] = a.y;
                }
            }
        }
        return answer;
    }
}

class Point {
    public int x;
    public int y;
    
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Tuple {
    public Point point;
    public int dir;
    public int left;
    
    public Tuple(Point point, int dir, int left) {
        this.point = point;
        this.dir = dir;
        this.left = left;
    }
}
