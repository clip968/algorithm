#include<bits/stdc++.h>
using namespace std;
#define F 0
#define R 1
#define B 2
#define L 3
pair<int, int> arr[50][50], answer;
bool visited[50][50][4];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; 

void dfs(int prev_dir, int x, int y) {
    int tmp_dir = (prev_dir + arr[x][y].first) % 4;
    if(visited[x][y][tmp_dir] == true){
        answer.first = x;
        answer.second = y;
        return;
    }
    visited[x][y][tmp_dir] = true;
    dfs(tmp_dir, x + dx[tmp_dir] * arr[x][y].second, y + dy[tmp_dir] * arr[x][y].second);
}

int main(){
    int t;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        memset(visited, 0, sizeof(visited));
        int n;
        cin >> n;
        for(int i{};i<n;++i){
            for(int j{};j<n;++j){
                string s;
                cin >> s;
                if(s[0] == 'B') arr[i][j].first = B;
                else if(s[0] == 'L') arr[i][j].first = L;
                else if(s[0] == 'F') arr[i][j].first = F;
                else if(s[0] == 'R') arr[i][j].first = R;
                arr[i][j].second = s[1] - '0';
            }
        }
        dfs(B, 0, 0);
        printf("%d %d\n", answer.first, answer.second);

    }
    return 0;
}