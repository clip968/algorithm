def solution(numbers):
    
    answer = []

    for i in range(0, len(numbers)):
        for j in range(i + 1, len(numbers)):
            answer.append(numbers[i] + numbers[j])
    
    answer = sorted(set(answer))

    return answer

solution([2,1,3,4,1])