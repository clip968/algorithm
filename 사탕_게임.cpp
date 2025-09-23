#include<bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int chk_max(vector<vector<char>> &v, int x, int y){
    int n = v.size();
    int maxLen = 1;
    
    int count = 1;
    for(int j = y - 1; j >= 0 && v[x][j] == v[x][y]; j--) count++;
    for(int j = y + 1; j < n && v[x][j] == v[x][y]; j++) count++;
    maxLen = max(maxLen, count);
    
    count = 1;
    for(int i = x - 1; i >= 0 && v[i][y] == v[x][y]; i--) count++;
    for(int i = x + 1; i < n && v[i][y] == v[x][y]; i++) count++;
    maxLen = max(maxLen, count);
    
    return maxLen;
}

int main(){
    int n; scanf("%d", &n);
    vector<vector<char>> v(n, vector<char>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf(" %c", &v[i][j]);
        }
    }

    int result{};

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            result = max(result, chk_max(v, i, j));
            for(int d=0; d<4; d++){
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(v[i][j] != v[nx][ny]){
                    swap(v[i][j], v[nx][ny]);
                    result = max(result, chk_max(v, i, j));
                    result = max(result, chk_max(v, nx, ny));
                    swap(v[i][j], v[nx][ny]);
                }
            }
        }
    }

    printf("%d\n", result);
    return 0;
}