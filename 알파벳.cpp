#include<bits/stdc++.h>
using namespace std;

int ans{};
bool visited[26];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(vector<vector<char>>& v, int x, int y, int val){
    int r = v.size();
    int c = v[0].size();

    ans = max(ans, val);

    for(int i{};i<4;++i){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < r && ny >= 0 && ny < c){
            int next_char = v[nx][ny] - 'A';
            if(!visited[next_char]){
                visited[next_char] = true;
                dfs(v, nx, ny, val + 1);
                visited[next_char] = false;
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    vector<vector<char>> v(r, vector<char>(c));

    for(int i{};i<r;++i){
        for(int j{};j<c;++j){
            cin >> v[i][j];
        }
    }

    // for(int i{};i<r;++i){
    //     for(int j{};j<c;++j) {
    //         cout << v[i][j] << ' ';
    //     }
    // }

    visited[v[0][0]-'A'] = true;
    dfs(v, 0, 0, 1);
    cout << ans << '\n';
    return 0;
}