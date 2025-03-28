def solution(arr1, arr2):
    a1, b1 = len(arr1), len(arr1[0])
    a2, b2 = len(arr2), len(arr2[0])
    
    answer = [[0] * b2 for _ in range(a1)]
    
    for i in range(a1):
        for j in range(b2):
            for k in range(b1):
                answer[i][j] += arr1[i][k] * arr2[k][j]
    return answer