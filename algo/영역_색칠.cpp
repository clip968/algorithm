#include<bits/stdc++.h>
using namespace std;

int arr[101][101];
int cnt;
int main (){
    int n, m; scanf("%d%d", &n,&m);
    int curr = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] > 0) {
                int curr = arr[i][j];
                for(int k=j;k<m;k++){
                    if(arr[i][k] == 0) break;
                    if(curr == arr[i][k]){
                        arr[i][k] = 0;
                    } 
                }
                cnt++;
            }
           
        }
    }

    printf("%d", cnt);
}