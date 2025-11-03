#include<bits/stdc++.h>
using namespace std;

int main(){
    int c, r;
    scanf("%d%d", &c, &r);
    int target;
    scanf("%d", &target);
    
    if(c * r < target) {
        printf("0\n");
        return 0;
    }
    
    vector<vector<int>> board(r+1, vector<int>(c+1, 0));
    
    // 방향: 위(0), 오른쪽(1), 아래(2), 왼쪽(3)
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    int x = 1, y = 1;  
    int dir = 0;  // 처음엔 위쪽으로
    int cnt = 1;
    
    board[y][x] = cnt;
    
    if(cnt == target) {
        printf("%d %d\n", x, y);
        return 0;
    }
    
    while(cnt < c * r) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        // 다음 위치가 범위를 벗어나거나 이미 방문한 곳이면 방향 전환
        if(nx < 1 || nx > c || ny < 1 || ny > r || board[ny][nx] != 0) {
            dir = (dir + 1) % 4;  
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        
        x = nx;
        y = ny;
        cnt++;
        board[y][x] = cnt;
        
        if(cnt == target) {
            printf("%d %d\n", x, y);
            return 0;
        }
    }
    
    return 0;
}