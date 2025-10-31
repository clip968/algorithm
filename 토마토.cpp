#include<bits/stdc++.h>
using namespace std;

struct Pos {
    int x, y;
    int depth;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    int m, n;  
    scanf("%d %d", &m, &n);

    vector<vector<int>> board(n, vector<int>(m));
    queue<Pos> q;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            scanf("%d", &board[i][j]);
            if(board[i][j] == 1) {
                q.push({i, j, 0});
            }
        }
    }

    int ans = 0;

    while(!q.empty()) {
        Pos cur = q.front();
        q.pop();

        ans = max(ans, cur.depth);

        for(int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] != 0) continue;  

            board[nx][ny] = 1;
            q.push({nx, ny, cur.depth + 1});
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(board[i][j] == 0) {
                printf("-1\n");
                return 0;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}