#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
int answer{};

pair<int, int> direction[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int x, int y, int x_max, int y_max){
    v[y][x] = 0;
    for(int i{};i<4;++i){
        int dx = x + direction[i].first;
        int dy = y + direction[i].second;

        if(dx >= 0 && dx < x_max && dy >= 0 && dy < y_max && v[dy][dx] == 1){
            dfs(dx, dy, x_max, y_max);
        }
    }
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        answer = 0;
        int m, n, k;
        int x, y;
        scanf("%d %d %d", &m, &n, &k);
        v.clear();
        v.resize(n, vector<int>(m, 0));
        vector<pair<int, int>> point;

        for(int i{};i<k;++i){
            scanf("%d %d", &x, &y);
            point.push_back({y, x});
            v[y][x] = 1;
        }

        for(auto k : point) {
            if(v[k.first][k.second] == 1){
                dfs(k.second, k.first, m, n);
                answer++;
            }
        }

        printf("%d\n", answer);
    }
}