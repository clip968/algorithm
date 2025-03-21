#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    char arr[n][m];
    for(int i{};i<n;++i){
        for(int j{};j<m;++j){
            scanf(" %c", &arr[i][j]);
        }
    }
    int start_x=n, start_y=m, end_x=-1, end_y=-1;
    for(int i{};i<n;++i){
        for(int j{};j<m;++j){
            if(arr[i][j] == '#'){
                start_x = min(start_x, i);
                start_y = min(start_y, j);
                end_x = max(end_x, i);
                end_y = max(end_y, j);
            }
        }
    }
    bool up=false, down=false, left=false, right=false;
    for(int i{start_y};i<end_y;++i){
        if(arr[start_x][i] == '.'){
            up = true;
        }
        if(arr[end_x][i] == '.') {
            down = true;
        }
    }
    for(int i{start_x};i<end_x;++i){
        if(arr[i][start_y] == '.'){
            left = true;
        } 
        if(arr[i][end_y] == '.'){
            right= true;
        }
    }

    if(up) printf("UP");
    else if(down) printf("DOWN");
    else if(left) printf("LEFT");
    else if(right) printf("RIGHT");


    
}