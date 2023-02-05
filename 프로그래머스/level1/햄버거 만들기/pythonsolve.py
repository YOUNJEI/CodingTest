order = [1, 3, 2, 1]

def solution(ingredient):
    answer = 0
    
    stack = []
    restore = []
    
    for i in ingredient:
        stack.append(i)
        
        if stack and len(stack) >= 4 and stack[-1] == 1:
            j = 0
            
            while j < 4 and stack[-1] == order[j]:
                restore.append(stack[-1])
                stack.pop()
                j += 1
                
            if j == 4:
                answer += 1
                restore.clear()
            else:
                while restore:
                    stack.append(restore[-1])
                    restore.pop()
    return answer
