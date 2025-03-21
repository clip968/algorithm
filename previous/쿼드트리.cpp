#include<bits/stdc++.h>
using namespace std;
char arr[65][65];
vector<char> v;

bool check(int x, int y, int size) {
    char start = arr[x][y];  
    
    for(int i = x; i < x + size; i++) {
        for(int j = y; j < y + size; j++) {
            if(arr[i][j] != start) return false;
        }
    }
    return true;
}

void solve(int x, int y, int size) {
    if(check(x, y, size)) {
        v.push_back(arr[x][y]);
        return;
    }
    
    v.push_back('(');  
    int half = size/2;
    solve(x, y, half);                
    solve(x, y + half, half);         
    solve(x + half, y, half);         
    solve(x + half, y + half, half);  
    v.push_back(')');  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    getchar(); 
    
    for(int i=0;i<n;i++){
        string line;
        cin >> line;
        for(int j=0;j<n;j++){
            arr[i][j] = line[j];
        }
    }

    solve(0, 0, n);

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         printf("%c ", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    for(auto k : v) {
        printf("%c", k);
    }
}