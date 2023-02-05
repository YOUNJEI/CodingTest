def solution(food):
    answer = ''
    
    solve = []
    for i in range(1, len(food)):
        solve.append(food[i] // 2)
    
    sub = ''
    for i in range(0, len(solve)):
        for j in range(0, solve[i]):
            sub += str(i + 1)        
    
    answer += sub
    answer += '0'
    answer += sub[::-1]
    return answer
