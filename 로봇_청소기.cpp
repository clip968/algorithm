#include<bits/stdc++.h>
using namespace std;
// 북 동 남 서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;


    int start_x, start_y, dir;
    cin >>start_x >> start_y >> dir;

    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<int>> visited(n, vector<int>(m, false));

    for(int i{};i<n;++i) {
        for(int j{};j<m;++j) {
            cin >> v[i][j];
            if(v[i][j] == 1) {
                visited[i][j] = true;
            } 
        }
    }
    int x{start_x}, y{start_y};

    while(true) {
        // 현재 칸이 청소되지 않은 경우
        if(v[x][y] == 0 && visited[x][y] == false) {
            visited[x][y] = true;
            ans++;
        }

        bool is_val{false};
        for(int i{};i<4;++i) {
            int nx{x + dx[i]};
            int ny{y + dy[i]};
            //현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
            if(v[nx][ny] == 0 && visited[nx][ny] == false) {
                is_val = true;
                //반시계 방향으로 90도 회전한다
                dir = (dir + 3) % 4;
                int nnx{dx[dir] + x};
                int nny{dy[dir] + y};

                if(v[nnx][nny] == 0 && visited[nnx][nny] == false) {
                    x = nnx;
                    y = nny;
                }
                break;
            }
        }
        // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        if(is_val == false) {
            int nx{x-dx[dir]};
            int ny{y-dy[dir]};
            // 후진 할 수 있는 경우
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && v[nx][ny] == 0) {
                x = nx;
                y = ny;
            }
            else {
                break;
            }
        }
    }
    cout << ans << "\n";
}