#include<bits/stdc++.h>
using namespace std;

int arr[21][21];
int result = INT_MAX;
bool chk[21];
int counter;
int N;
void DFS(int counter, int prev_n) {
    int start = 0;
    int link = 0;

    if(counter == N / 2) {
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(chk[i] == true && chk[j] == true) start += arr[i][j];
                else if(chk[i] == false && chk[j] == false) link += arr[i][j];
            }
        }

        result = min(result, abs(start - link));
    }

    for(int i=prev_n+1;i<=N;i++){
        chk[i] = true;
        DFS(counter+1, i);
        chk[i] = false;
    }
}

int main(){
    scanf("%d", &N);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            scanf("%d", &arr[i][j]);
        }
    }

    DFS(0, 0);


    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=N;j++){
    //         printf("%d ", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d\n", result);
}