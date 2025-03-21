#include<bits/stdc++.h>
using namespace std;

void insertionSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수
    // insertion sort 알고리즘 구현
    int value;
    int j;
    
    
    for(int i=0;i<n;i++){
        value = a[i];
        for(j=i-1;j>=0;j--){
            countCmpOps++;
            if(a[j] > value){
                countSwaps++;
                a[j+1] = a[j];   
            }
            else break;
        }
        a[j+1] = value;
    }
    printf("%d %d\n", countCmpOps, countSwaps);
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        int a[n]{};
        for(int i{};i<n;i++){
            scanf("%d", &a[i]);
        }
        
        insertionSort(a, n);
    }
    
}