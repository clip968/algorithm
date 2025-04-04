#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<pair<int, int>> selected;
bool visited[51][51];
int min_dist{INT_MAX/2};
void chicken_distance(){
    int ans{};
    for(auto k : house){
        int tmp{INT_MAX/2};
        for(auto k2 : selected){
            tmp = min(tmp, abs(k.first-k2.first)+abs(k.second-k2.second));
        }
        ans+=tmp;
    }

    min_dist = min(min_dist, ans);
}

void backtracking(int x, int selecting){
    if(selecting == m){
        chicken_distance();
    }
    for(int i{x};i<chicken.size();++i){
        if(visited[chicken[i].first][chicken[i].second] == true){
            continue;
        }

        visited[chicken[i].first][chicken[i].second] = true;
        selected.push_back({chicken[i].first, chicken[i].second});
        backtracking(i, selecting+1);
        visited[chicken[i].first][chicken[i].second] = false;
        selected.pop_back();
    }
}

int main(){
    scanf("%d %d", &n, &m);
    vector<vector<int>> v(n+1, vector<int>(n+1));
    for(int i{1};i<=n;i++){
        for(int j{1};j<=n;++j){
            scanf("%d", &v[i][j]);
            if(v[i][j] == 1){
                house.push_back({i, j});
            }
            else if(v[i][j] == 2){
                chicken.push_back({i, j});
            }
        }
    }

    backtracking(0, 0);
    printf("%d", min_dist);



    // for(int i{1};i<=n;++i){
    //     for(int j{1};j<=n;++j){
    //         printf("%d ", v[i][j]);
    //     }
    //     printf("\n");
    // }
}