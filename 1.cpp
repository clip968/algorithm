#include <bits/stdc++.h>
using namespace std;
const int dy[]={-1, -1, -1, 0, 0, 1, 1, 1}, dx[]={-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
    int t, n, c, k, p, rr, cc, age;
    scanf("%d", &t);
    while(t--){
        int power[10][10];
        vector<int> tree[10][10];
        scanf("%d%d%d%d", &n, &c, &k, &p); // 사이즈, 나무 수, 회복, 사이클
        // 지력 입력
        for(int y=0; y<n; ++y){
            for(int x=0; x<n; ++x){
                scanf("%d", &power[y][x]);
            }
        }
        // 나무 입력
        for(int i=0; i<c; ++i){
            scanf("%d%d%d", &rr, &cc, &age);
            tree[rr][cc].push_back(age);
        }
        while(p--){
            // 1. 지력 흡수
            vector<int> death[10][10];
            for(int y=0; y<n; ++y){
                for(int x=0; x<n; ++x){
                    sort(tree[y][x].begin(), tree[y][x].end());
                    vector<int> tmp;
                    for(int i=0; i<tree[y][x].size(); ++i){
                        if(power[y][x]>=tree[y][x][i]){
                            power[y][x]-=tree[y][x][i];
                            tmp.push_back(tree[y][x][i]+1); // 나이 1 증가
                        }
                        else death[y][x].push_back(tree[y][x][i]);
                    }
                    tree[y][x] = tmp;
                }
            }
            // 2. 죽은 나무 지력 회복
            for(int y=0; y<n; ++y){
                for(int x=0; x<n; ++x){
                    for(int p : death[y][x]){
                        power[y][x] += p/2;
                    }
                }
            }
            // 3. 번식
            for(int y=0; y<n; ++y){
                for(int x=0; x<n; ++x){
                    for(int tree_sub : tree[y][x]){
                        if(tree_sub%5!=0) continue;
                        for(int i=0; i<8; ++i){
                            int gy{y+dy[i]}, gx{x+dx[i]};
                            if(gy<0||gx<0||gy>=n||gx>=n) continue;
                            tree[gy][gx].push_back(1);
                        }
                    }
                }
            }
            // 4. 지력 회복
            for(int y=0; y<n; ++y){
                for(int x=0; x<n; ++x){
                    power[y][x] += k;
                }
            }
        }
        // 남아 있는 나무 세기
        int answer{};
        for(int y=0; y<n; ++y){
            for(int x=0; x<n; ++x){
                answer += tree[y][x].size();
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}