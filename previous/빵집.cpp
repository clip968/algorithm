#include<bits/stdc++.h>
using namespace std;
int answer;
int dx[] = {-1, 0, 1}; // 위쪽 대각선, 오른쪽, 아래쪽 대각선
int dy[] = {1, 1, 1};  

bool dfs(int x, int y, vector<vector<char>> &v) {

    if(y == v[0].size() - 1) {
        answer++;
        return true;
    }

    for(int i{};i<3;++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx < v.size() && ny < v[0].size()) {
            if(v[nx][ny] == '.') {
                v[nx][ny] = 'x';
                if(dfs(nx, ny, v)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    int r, c; scanf("%d %d", &r, &c);
    vector<vector<char>> v(r, vector<char>(c));

    for(int i{0};i<r;++i) {
        for(int j{0};j<c;++j) {
            scanf(" %c", &v[i][j]);
        }
    }

    for(int i{0};i<r;++i) {
        dfs(i, 0, v);
    }

    printf("%d", answer);
    // for(auto k : v) {
    //     for(auto l : k) {
    //         printf("%c", l);
    //     }
    //     printf("\n");
    // }
}