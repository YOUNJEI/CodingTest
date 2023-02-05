g_count = 0

def dfs(number, idx, left, score):
    global g_count
    if left == 0:
        if score == 0:
            g_count += 1
        return g_count
    if idx < len(number):
        dfs(number, idx + 1, left - 1, score + number[idx])
        dfs(number, idx + 1, left, score)
    return g_count

def solution(number):
    global g_count
    g_count = 0
    answer = 0
    
    answer = dfs(number, 0, 3, 0)
    return answer
