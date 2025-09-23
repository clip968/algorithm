#include<bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> m >> n >> k;

    vector<vector<int>> board(m, vector<int>(n, 0));

    for(int i{};i<k;++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int y{y1};y<y2;++y){
            for(int x{x1};x<x2;++x){
                board[y][x] = 1;
            }
        }
    }

    vector<int> answer;
    for(int i{};i<m;++i){
        for(int j{};j<n;++j){
            if(board[i][j] == 0){
                int area{0};
                queue<pair<int,int>> q;
                q.push({i,j});
                board[i][j] = 1;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    ++area;
                    for(int dir=0;dir<4;++dir){
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if(nx>=0 && nx<m && ny>=0 && ny<n && board[nx][ny] == 0){
                            board[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                }
                answer.push_back(area);
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for(int x : answer) cout << x << ' ';

    return 0;
}
