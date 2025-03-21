#include<bits/stdc++.h>
using namespace std;

bool xCols[16], rup[31], lup[31];
int n, ans;

void dfs(int y){    
    if(y == n+1) {
        ans++;
        return;
    }
    for(int x=1;x<=n;x++){
        if(xCols[x] || lup[y-x+n] || rup[y + x]) continue;
        xCols[x] = lup[y-x+n] = rup[y+x] = true;
        dfs(y + 1);
        xCols[x] = lup[y-x+n] = rup[y+x] = false; 
    }
}

int main(){
    scanf("%d", &n);
    dfs(1);
    printf("%d", ans);

}