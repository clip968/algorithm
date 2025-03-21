#include<bits/stdc++.h>
using namespace std;

int arr[9][9];
int maxi;

int main(){
    int ans_x, ans_y;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d", &arr[i][j]);
            if(maxi < arr[i][j]) {
                maxi = arr[i][j];
                ans_x = i;
                ans_y = j;
            }
        }
    }

    printf("%d\n%d %d", maxi, ans_x+1, ans_y+1);
}