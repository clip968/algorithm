#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<int>> v(n+1, vector<int>(n+1, 0));
    vector<vector<int>> d(n+1, vector<int>(n+1, 0));
    
    for(int i{1};i<=n;++i){
        for(int j{1};j<=n;++j){
            scanf("%d", &v[i][j]);

            d[i][j] = d[i][j-1] + d[i-1][j] - d[i-1][j-1] + v[i][j];
        }
    }

    for(int i{};i<m;++i){
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        int result = d[x2][y2] - d[x1-1][y2] - d[x2][y1-1] + d[x1-1][y1-1];
        printf("%d\n", result);
    }
}