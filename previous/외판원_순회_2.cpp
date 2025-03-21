#include<bits/stdc++.h>
using namespace std;
int arr[10][10];
vector<bool> visited;
int n;
int answer = 1e9;

void backtrack(int start, int current, int depth, int cost) {
    if(depth == n - 1){
        if(arr[current][start] != 0){
            answer = min(answer, cost+arr[current][start]);
        }
        return;
    }

    for(int i{};i<n;++i){
        if(!visited[i] && arr[current][i] != 0){
            visited[i] = true;
            backtrack(start, i, depth + 1, cost + arr[current][i]);
            visited[i] = false;
        }
    }
}

int main(){
    scanf("%d", &n);

    for(int i{};i<n;++i){
        for(int j{};j<n;++j){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i{};i<n;++i){
        visited.assign(n, false);
        visited[i] = true;
        backtrack(i, i, 0, 0);
    }
    
    printf("%d", answer);

}