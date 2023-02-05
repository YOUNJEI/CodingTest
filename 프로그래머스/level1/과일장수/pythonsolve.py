def solution(k, m, score):
    answer = 0
    score.sort(reverse=True)
    
    minNum = 10
    c = 0
    for s in score:
        if c == m:
            answer += minNum * m
            c = 0
        minNum = min(minNum, s)
        c += 1
    if c == m:
        answer += minNum * m
    
    return answer
