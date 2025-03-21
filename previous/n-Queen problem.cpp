#include<bits/stdc++.h>
using namespace std;
#define N 4
int col[N];

int isPromising(int row) {
    for(int k = 0; k < row; k++) {
        if (col[row] == col[k] || abs(col[row] - col[k]) == row - k) {
            return 0;  // 조건을 만족하지 않으면 false (0)
        }
    }
    return 1;  // 모든 조건을 만족하면 true (1)
}

void printNqueens() {
    for(int k : col) {
        printf("%d ", k);
    }
    printf("\n");
}

void nQueens(int row) {
    if(row == N) {
        printNqueens();  // 모든 행에 퀸을 놓았다면 출력
    } else {
        for(int i = 0; i < N; i++) {
            col[row] = i;  // 현재 행에 퀸을 놓을 위치
            if(isPromising(row)) {  // 유망한 위치인지 확인
                nQueens(row + 1);  // 다음 행으로 이동
            }
        }
    }
}

int main() {
    nQueens(0);  // 0번째 행부터 시작
    return 0;
}
